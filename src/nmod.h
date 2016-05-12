/********************************************************************
* Licence: GPL 3 .0 or later.
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   any later version.
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.

*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/


//Author         :  Carey Pridgeon
// Email           :  carey.pridgeon@gmail.com
// Description:  This header file contains definition of all the 
//                        functions used by nMod. 
//                        Additionally, all the system header files used by 
//                        nMod are included in this header. Global File
//                        pointers are also defined here, rather in globals.h
//                        because they require stdio.h.
//
// There are lots of function here that are unused in the reference build.

#ifndef nmodH
#define nmodH

/*Standard headers*/
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
//#include <sys/stat.h>
//#include <netinet/in.h>
//#include <sys/socket.h>
//#include <resolv.h>
//#include <arpa/inet.h>
//#include <pthread.h>

/*nMod specific header files*/
#include "nmod_structures.h"
#include "nmod_defines.h"

project *default_project;

/* filename for the project data file as it's read in */
FILE *inputfile;

// vars for particle data and config files 

FILE *datafile;

FILE *configfile;

// ##############################################################
// # CORE nBody model  functions, those that you can ignore when coding an EA
// ##############################################################

//function to reset gravitational force storage members of local_particles data structure
int _clear_total_gravitational_force_accumulators (particle * local_particles, int num_local_particles);

//Runge Kutta Fourth Order Integration 
int _move_particles_RK4 (particle * local_particles, rk4_store * local_store,int time, int num_local_particles, particle_pair * begin,int collapsor, double G);

//Mid Point Integration 
int _move_particles_MP (particle * local_particles, rk4_store * local_store,int time, int num_local_particles, particle_pair * begin,int collapsor, double G);

//Top level function to obtain derivatives (gravitational force)
int _convert_gravitational_effects_into_velocity (particle * local_particles, int num_local_particles,particle_pair * begin, double G);

//function that divides gravitational force of a body with the intertia of that body
int _account_for_inertia (particle * local_particles, int index);

//function that calls the 'Pull' function for all local_particles
int _find_meters_per_second_velocity (particle * local_particles, int num_local_particles);

//function that calculates and stores the relative gravitational force for two given local_particles
int _find_gravitational_interaction_between_pair_of_particles (particle * local_particles, int m1, int m2, double G);

//function that calls the force function for all pairs in the linked list of unique pairs
int _calculate_forces_acting_between_all_particles (particle_pair * begin, particle * local_particles, double G);

// function to provide a linked list of unique pairing between all local_particles
particle_pair *_make_set_of_particle_pairs (int amount);

// node creation function for linked list of unique pairs
particle_pair *_create_particle_pairs_node (int location1, int location2);

/* string tokeniser used by read_config_line function */
void _parse_line (char *input, char *word1, char *word2, char *word3);


// ##############################################################
// # MEMORY HANDLING functions that you might want to edit, but can mostly ignore
// ##############################################################

//function to allocate memory to data structures - linked lists - single pointers 
void *_alloc_mem (size_t size);

//function to allocate memory to dynamic arrays
void *_alloc_mem_contiguous (int length, size_t size);

//function that erases the linked list of particle  pairs when the program exits

int _delete_list_of_pairs (particle_pair * begin);

// ##############################################################
// # NMP MANAGEMENT functions that you might edit, if you make changes to the nmp file 
// # and project data structure
// ##############################################################

// function to read in an nmp file and create a project in memory
project * load_project_into_nmod (char *filename, int rval);

// function to load in the data for a single particle
void read_single_particle (FILE * current_file, particle * single_particle, int datasize);

// function to write the current project data to an nmp file. 
int export_project_from_current_state (char *filename, project * subject);

/* function to free the memory assigned to a project */
int free_and_delete_project (project * project);

// ##############################################################
// # NBO MANAGEMENT functions that you might edit, if you make changes to the nbo file format
// # or the way they are handled in nmod
// ##############################################################

// function used when creating the normal  output nbo file initially (writes the preamble).
int _initialise_nbo_file (project * local_project);

// whatever methods in use, this function writes the time series data to it
int write_current_state (project * local_project);

// ##############################################################
// # nBody model driver
// ##############################################################
// function to operate (drive) the nbody model
int run_nbody_environment (project * local_project);

#endif
