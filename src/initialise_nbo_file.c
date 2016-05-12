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
// Description: This function creates the ouput nbo file, and writes the preamble to it.

#include "nmod.h"
int _initialise_nbo_file (project * local_project) {

    //first off, edit the nbo filename using the globally available
    // char array 'nbo_append_text', which is itself set using the function 'set_nbo_append'
    sprintf(local_project->outputfilename,"%s%s.nbo",local_project->outputfilename,local_project->nbo_append_text);

    // opening as writeable binary
    local_project->outfile = fopen (local_project->outputfilename, "w");

    /*
        * reset the file pointer to start of file 
        */
    if ((fseek (local_project->outfile, 0, SEEK_SET)) == -1) {
        printf ("> Error on file pointer reset for %s",local_project->outputfilename);
    }  
    if (local_project->outfile == NULL) {
        fprintf (stderr, "nbo file '%s' not opened correctly \n",local_project->outputfilename);
        exit (0);
    }
    // write the nbo file preamble
    fprintf (local_project->outfile, "#%d", local_project->states_required);
    fprintf (local_project->outfile, ":%d", local_project->num_particles);
    fprintf (local_project->outfile, ":%d", local_project->number_of_steps_per_state);
    fprintf (local_project->outfile, ":%d#", local_project->particle_info_size);
    fclose(local_project->outfile);
    return 0;
}

