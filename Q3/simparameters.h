
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

#define Call_ARRIVALRATE 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1   /* calls/minute */
#define MEAN_CALL_DURATION 1-0.5, 2-0.5, 3-0.5, 4-0.5, 5-0.5, 6-0.5, 7-0.5, 8-0.5, 9-0.5, 10-0.5, 30-0.5, 50-0.5, 60-0.5, 90-0.5, 100-0.5 /* minutes */
#define RUNLENGTH 5e5        /* number of successful calls */
#define BLIPRATE 1e3
#define NUMBER_OF_CHANNELS 5, 7, 8, 10, 11, 13, 14, 15, 17, 18, 42, 64, 75, 106, 117

/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 400050636, 400099173, 345

/*******************************************************************************/

#endif /* simparameters.h */
