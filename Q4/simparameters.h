
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

#define Call_ARRIVALRATE 1, 2, 0.33, 1, 3, 2, 1, 2, 3  /* calls/minute */
#define MEAN_CALL_DURATION 1, 0.5, 3, 3, 1, 1.5, 6, 3, 2  /* minutes */
#define RUNLENGTH 5e6        /* number of successful calls */
#define BLIPRATE 1e3
#define NUMBER_OF_CHANNELS 2, 2, 2, 4, 4, 4, 8, 8, 8
#define WAITING_TIME_LIMIT 30, 50, 70, 40, 70, 100, 1, 10, 100 /* SEC */
/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 400050636, 400099173, 345

/*******************************************************************************/

#endif /* simparameters.h */
