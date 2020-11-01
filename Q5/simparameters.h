
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
//#define all_discrete


#define Call_ARRIVALRATE 1*1, 1*1, 1*1, 1*1, 1*1, 1*1   /* calls/minute */ //lamda
#define MEAN_CALL_DURATION 1*1, 3*1, 5*1, 7*1, 9*1, 11*1 /* minutes */ // D
#define RUNLENGTH 5e4        /* number of successful calls */
#define GIVE_UP_TIME 1*1, 3*1, 5*1, 7*1, 9*1, 11*1 //G
#define WAIT_TIME 1*1, 3*1, 5*1, 7*1, 9*1, 11*1 //W

#define BLIPRATE 1e3
#define NUMBER_OF_CHANNELS 1, 3, 5, 9, 13, 17, 19, 23, 27, 30 //K
/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 400050636, 400099173, 345


/*******************************************************************************/

#endif /* simparameters.h */
