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
// Description:   All the structures used by nMod

#ifndef nmodstructH
#define nmodstructH


typedef struct
{ 
    int r;			// red colour
    int g;			// green colour
    int b;			// guess!
} particlecolour;

/* structure that is used when representing a body in the nBody model */
typedef struct {    
    char particle_id[100];
    int type;
    particlecolour rgb_vals;
    char freetext[100];
    double radius;
    int iscollapsor;
    double mass;
    double xloc;			/*position in the WCS */
    double yloc;
    double zloc;
    double xsp;			/*speed in the WCS */
    double ysp;
    double zsp;
    double grav_x;		/*gravitational force per second for each axis */
    double grav_y;
    double grav_z;
    double xforce;		/* accumulators used when collecting total gravitational forces */
    double yforce;
    double zforce;
    double xloctemp;		/* location and speed members used when integrating */
    double yloctemp;
    double zloctemp;
    double xsptemp;
    double ysptemp;
    double zsptemp;
    // these options are for when nmod is in use for experiments only. 
    // therefore they are commented out here (the burn plan would otherwise take up a lot of memory
    //int is_EA_spaceship; // boolean
    //int burn_plan_exists; // boolean (well, ish...)
    //double rocket_fuel_payload;
    //burn_sequence burn_plan; // only used if this particle is to be a spaceship in an EA.
} particle;

/* 
* structure used to created a linked list
* of pairs of planets
*/
typedef struct particle_pair_t
{    
    int m1;
    int m2;
    struct particle_pair_t *next;
} particle_pair;

/* 
* structure used for the fourth order runge kutta integrator
*/
typedef struct {    
    double xforce1;
    double yforce1;
    double zforce1;
    double xforce2;
    double yforce2;
    double zforce2;
    double xforce3;
    double yforce3;
    double zforce3;
    double xforce4;
    double yforce4;
    double zforce4;
} rk4_store;

//-----
// the following sequence of structs come from nbview. We use them here as a means to store 
// the nbo files we record to memory, prior to writing them to file

//structure that is used when representing a particle in the viewer

typedef struct
{    
    char particle_id[100];
    int type;
    float mass;
    float radius;
    char freetext[100];
    particlecolour rgb_vals;
    float xloc;			/*position in the WCS */
    float yloc;
    float zloc;
    float xsp;			/*speed in the WCS */
    float ysp;
    float zsp;
} particle_data;

//-----
/* 
* The data structure for a single project. This includes all the
* data, files, arrays and other variables required by a single project within nMod.
* 
* If you need to add any new variables for use by a project, add them here. 
* avoid adding project specific variables anywhere else, since if they are not 
* encapsulated here, they won't be threadsafe, so you can't run concurrent projects in memory.
*/

typedef struct
{    
    char project_name[100]; // the name for this project (will be used as part of the final report file name)
    char final_conditions_filename[100]; //if the final state of all particles is to be recorded in nmp format, use this name of the file
    int num_particles; // how many particles there are in the system when the nbody model is running
    particle *particles; // the particles which get iterated by the nbody model
    rk4_store *store;
    char tempfname[100];
    char nbo_append_text[100];
    int nbo_write_direct;
    int particle_info_size;
    int states_required;
    int step_size;
    int number_of_steps_per_state;
    int steps_done_counter;
    int state_count;
    int method;
    int use_stdout;
    float G;
    char outputfilename[100];
    char new_projectname[100];
    int write_project;
    int record_destination; // file or memory
    int nbo_required;
    particle_pair *begin;
    int collapsor;
    int integration_method;
    int take_sample_counter;
    FILE *outfile;
    FILE *reportfile; // used for the EA summary
} project;



#endif
