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

//Author         : Carey Pridgeon
// Email           : carey.pridgeon@gmail.com
// Description: The Driver for the nBody model.
//                       This version simply iterates the nBody model until the required number of states is completed, and 
//                       records a n nbo file if one is requested.
#include "nmod.h"
int run_nbody_environment (project * local_project) {
    local_project->steps_done_counter = 0;
    local_project->state_count = 0;
    char newstring_for_exported_nmp_name[100];
    if(local_project->nbo_write_direct == NBO_FILE_ON) {// we are recording to file, so the nbo file needs to be initialised
        _initialise_nbo_file (local_project); // initialise the nbo file 
        if (local_project->outfile != NULL) {// write the first state
            write_current_state (local_project);
        }
    }
    for (;;) {
        if (local_project->method == USE_RK4) {
            _move_particles_RK4 (local_project->particles, local_project->store,local_project->step_size,local_project->num_particles,local_project->begin, local_project->collapsor,local_project->G);
        }
        else if (local_project->method == USE_MIDPOINT ) {
            _move_particles_MP (local_project->particles, local_project->store,local_project->step_size,local_project->num_particles,local_project->begin, local_project->collapsor,local_project->G);
        }
                    // increment the nunber of steps that have occured
        local_project->steps_done_counter++;        
        if (local_project->steps_done_counter >= local_project->number_of_steps_per_state) {      
            // increment the state count first.    
            local_project->state_count++;
            if(local_project->use_stdout) {
               printf ("> State %d of %d completed\n",local_project->state_count,local_project->states_required);
            }
            // time to record the state to file (if required) .
            if(local_project->nbo_write_direct == NBO_FILE_ON) {// we are recording to file, lucky us. 
                if (local_project->outfile != NULL) {// write the current state to the nbo file
                    write_current_state (local_project);
                }
            }         
            //reset the counter for steps completed, ready for counting up the next state
            local_project->steps_done_counter = 0;            
        }
        if (local_project->state_count >= local_project->states_required) {
            // the run has completed 
            if (local_project->write_project) { 
                sprintf(newstring_for_exported_nmp_name,"%s.nmp",local_project->final_conditions_filename);
                export_project_from_current_state (newstring_for_exported_nmp_name,local_project);
            } 
            break; // leave the infinite loop
        }
    }
    return 0;
}
