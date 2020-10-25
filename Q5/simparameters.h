
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

#ifndef _SIMPARAMETERS_H_
#define _SIMPARAMETERS_H_

/*******************************************************************************/

#ifdef FAST_RUN

#define Call_ARRIVALRATE 1, 1   /* calls/minute */ //lamda
#define MEAN_CALL_DURATION 1, 3 /* minutes */ // D
#define RUNLENGTH 5e1        /* number of successful calls */
#define GIVE_UP_TIME 1, 3 //G
#define WAIT_TIME 1, 3 //W

#define BLIPRATE 1e3
#define NUMBER_OF_CHANNELS 1, 3, 5 //K
/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 400050636, 400099173

#else

#define Call_ARRIVALRATE 1, 1, 1, 1, 1, 1   /* calls/minute */ //lamda
#define MEAN_CALL_DURATION 1, 3, 5, 7, 9, 11 /* minutes */ // D
#define RUNLENGTH 5e6        /* number of successful calls */
#define GIVE_UP_TIME 1, 3, 5, 7, 9, 11 //G
#define WAIT_TIME 1, 3, 5, 7, 9, 11 //W

#define BLIPRATE 1e3
#define NUMBER_OF_CHANNELS 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 //K
/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 400050636, 400099173, 345

#endif //FAST_RUN
/*******************************************************************************/

#endif /* simparameters.h */
