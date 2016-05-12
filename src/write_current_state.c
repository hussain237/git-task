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
// Description:    This function writes the current environment state to one of two forms of nbo file

#include "nmod.h"
int write_current_state (project * local_project) {
    int i;
        // opening as append
        local_project->outfile = fopen (local_project->outputfilename, "a");
        /*
        * reset the file pointer to start of file 
        */
        if ((fseek (local_project->outfile, 0, SEEK_SET)) == -1) {
            printf ("> Error on file pointer reset for %s", local_project->outputfilename);
        }  
        if (local_project->outfile == NULL) {
            fprintf (stderr, "nbo file '%s' not opened correctly \n",local_project->outputfilename);
            exit (0);
        }
        // state preamble
        fprintf (local_project->outfile, "[s%d", local_project->state_count);
        fprintf (local_project->outfile, "!%d!", local_project->num_particles);
        // start of particle data itself
        for (i = 0; i < local_project->num_particles; i++) {
            fprintf (local_project->outfile, "(%s", local_project->particles[i].particle_id);
            if (local_project->particles[i].type == MASSIVE_PARTICLE_3) {
                fprintf (local_project->outfile, "|ma3");
            }
            if (local_project->particles[i].type == MASSIVE_PARTICLE_2) {
                fprintf (local_project->outfile, "|ma2");
            }
            if (local_project->particles[i].type == MASSIVE_PARTICLE_1) {
                fprintf (local_project->outfile, "|ma1");
            }
            if (local_project->particles[i].type == MAJOR_PARTICLE_2) {
                fprintf (local_project->outfile, "|mj2");
            }
            if (local_project->particles[i].type == MAJOR_PARTICLE_1) {
                fprintf (local_project->outfile, "|mj1");
            }
            if (local_project->particles[i].type == MINOR_PARTICLE_2) {
                fprintf (local_project->outfile, "|mn2");
            }
            if (local_project->particles[i].type == MINOR_PARTICLE_1) {
                fprintf (local_project->outfile, "|mn1");
            }
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].mass);
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].radius);
            fprintf (local_project->outfile, "|%d,", local_project->particles[i].rgb_vals.r);
            fprintf (local_project->outfile, "%d,", local_project->particles[i].rgb_vals.g);
            fprintf (local_project->outfile, "%d", local_project->particles[i].rgb_vals.b);
            fprintf (local_project->outfile, "|%s", local_project->particles[i].freetext);
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].xloc);
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].yloc);
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].zloc);
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].xsp);
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].ysp);
            fprintf (local_project->outfile, "|%.10e", local_project->particles[i].zsp);
            fprintf (local_project->outfile, ")");
        }
        fprintf (local_project->outfile, "]");
        fclose(local_project->outfile);
        return 0;    
    }
