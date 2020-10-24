
/*
 * 
 * Call Blocking in Circuit Switched Networks
 * 
 * Copyright (C) 2014 Terence D. Todd
 * Hamilton, Ontario, CANADA
 * todd@mcmaster.ca
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 * 
 */

/*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "output.h"
#include "trace.h"
#include "simparameters.h"
#include "cleanup.h"
#include "call_arrival.h"
#include "main.h"

/*******************************************************************************/

int main(void)
{
  int j = 0;

  Simulation_Run_Ptr simulation_run;
  Simulation_Run_Data data; /* Simulation_Run_Data is defined in main.h. */
  Simulation_Run_Data for_avg_acc;
  Call call;

  // create a csv file
  FILE *fp;
  char data_set_name[] = "./Q3.csv";
  //file IO

  fp = fopen(data_set_name, "w");
  //cell/element name/type

  fprintf(fp, ("Random Seed,"));
  fprintf(fp, ("Offered Load,"));
  fprintf(fp, ("Number of channels,"));
  fprintf(fp, ("Call arrival count,"));
  fprintf(fp, ("Blocked call count,"));
  fprintf(fp, ("Calls processed ,"));
  fprintf(fp, ("Block rate ,"));

  fprintf(fp, "\n");
  fclose(fp);

  /* 
   * Get the list of random number generator seeds defined in simparameters.h.
   */
  unsigned RANDOM_SEEDS[] = {RANDOM_SEED_LIST, 0};
  unsigned random_seed;
  int NUMBER_OF_CHANNELS_LIST[] = {NUMBER_OF_CHANNELS};
  double Call_ARRIVALRATE_LIST[] = {Call_ARRIVALRATE};
  double MEAN_CALL_DURATION_LIST[] = {MEAN_CALL_DURATION};
  int size_rand_seed = (sizeof(RANDOM_SEEDS) / sizeof(unsigned)) - 1;

  //double OFFERED_LOAD_LIST[] = {OFFERED_LOAD};
  /* 
   * Loop for each random number generator seed, doing a separate
   * simulation_run run for each.
   */
  for (int k = 0; k < (sizeof(Call_ARRIVALRATE_LIST) / sizeof(double)); k++)
  {
    j = 0;
    random_seed = RANDOM_SEEDS[j];

    for_avg_acc.call_arrival_count = 0;
    for_avg_acc.blip_counter = 0;
    for_avg_acc.blocked_call_count = 0;
    for_avg_acc.number_of_calls_processed = 0;
    for_avg_acc.accumulated_call_time = 0;
    //for_avg_acc.random_seed = 0;

    while (random_seed != 0)
    {
      /* Create a new simulation_run. This gives a clock and eventlist. */
      simulation_run = simulation_run_new();

      /* Add our data definitions to the simulation_run. */
      simulation_run_set_data(simulation_run, (void *)&data);

      /* Initialize our simulation_run data variables. */
      data.call_arrival_rate = Call_ARRIVALRATE_LIST[k];
      data.call_duration = MEAN_CALL_DURATION_LIST[k];
      data.number_of_channels = NUMBER_OF_CHANNELS_LIST[k];
      data.blip_counter = 0;
      data.call_arrival_count = 0;
      data.blocked_call_count = 0;
      data.number_of_calls_processed = 0;
      data.accumulated_call_time = 0.0;
      data.random_seed = random_seed;

      /* Create the channels. */
      data.channels = (Channel_Ptr *)xcalloc((int)NUMBER_OF_CHANNELS_LIST[k],
                                             sizeof(Channel_Ptr));

      /* Initialize the channels. */
      for (int i = 0; i < NUMBER_OF_CHANNELS_LIST[k]; i++)
      {
        *(data.channels + i) = server_new();
      }

      /* Set the random number generator seed. */
      random_generator_initialize((unsigned)random_seed);

      /* Schedule the initial call arrival. */
      schedule_call_arrival_event(simulation_run,
                                  simulation_run_get_time(simulation_run) +
                                      exponential_generator((double)1 / Call_ARRIVALRATE_LIST[k]));

      /* Execute events until we are finished. */
      while (data.number_of_calls_processed < RUNLENGTH)
      {
        simulation_run_execute_event(simulation_run);
      }
      /* Print out some results. */
      //output_results(simulation_run);

      for_avg_acc.call_arrival_count += data.call_arrival_count;
      for_avg_acc.blip_counter += data.call_arrival_count;
      for_avg_acc.blocked_call_count += data.blocked_call_count;
      for_avg_acc.number_of_calls_processed += data.number_of_calls_processed;
      for_avg_acc.accumulated_call_time += data.accumulated_call_time;
      /* Clean up memory. */
      cleanup(simulation_run);

      /* Updata random seeds */
      random_seed = RANDOM_SEEDS[++j];
    }

    for_avg_acc.call_arrival_count /= size_rand_seed;
    for_avg_acc.blip_counter /= size_rand_seed;
    for_avg_acc.blocked_call_count /= size_rand_seed;
    for_avg_acc.number_of_calls_processed /= size_rand_seed;
    for_avg_acc.accumulated_call_time /= size_rand_seed;
    //for_avg_acc.random_seed /= size_rand_seed;

#ifndef NO_CSV_OUTPUT
    fp = fopen(data_set_name, "a");
    //cell/element name/type

    //fprintf(fp, ("Random Seed,"));
    fprintf(fp, "%d,", random_seed);

    //fprintf(fp, ("Offered Load,"));
    fprintf(fp, "%f, ", data.call_arrival_rate * data.call_duration);

    //fprintf(fp, ("Number of channels,"));
    fprintf(fp, "%d, ", data.number_of_channels);

    //fprintf(fp, ("Call arrival count,"));
    fprintf(fp, "%ld, ", for_avg_acc.call_arrival_count);

    //fprintf(fp, ("Blocked call count,"));
    fprintf(fp, "%ld, ", for_avg_acc.blocked_call_count);

    //fprintf(fp, ("Calls processed ,"));
    fprintf(fp, "%ld, ", for_avg_acc.number_of_calls_processed);

    //fprintf(fp, ("Block rate ,"));
    fprintf(fp, "%f, ", (double)for_avg_acc.blocked_call_count / for_avg_acc.call_arrival_count);

    fprintf(fp, "\n");
    fclose(fp);
#endif

    printf("\n");
    printf("Random Seed = %d \n", random_seed);
    printf("Offered Load = %f \n", data.call_arrival_rate * data.call_duration);
    printf("Number of channels = %d \n", NUMBER_OF_CHANNELS_LIST[k]);
    printf("Call arrival count = %ld \n", for_avg_acc.call_arrival_count);
    printf("Blocked call count = %ld \n", for_avg_acc.blocked_call_count);
    printf("Calls processed = %ld \n", for_avg_acc.number_of_calls_processed);
    printf("Block rate = %f \n", (double)for_avg_acc.blocked_call_count / for_avg_acc.call_arrival_count);
    printf("\n");
  }

  /* Pause before finishing. */
  //getchar();
  return 0;
}
