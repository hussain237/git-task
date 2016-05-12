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
// Description:  This function parses the project file (nmp file) and fills the project data structure that nmod will use.
//
// Since this is the reference build, a lot of EA specific code is commented out at the bottom of this file, and there are a lot 
// of options here for entries that are not in the reference build, since they are for experimentation only

#include "nmod.h"
project * load_project_into_nmod (char *filename, int rval) {
    int x, t;
    char *inputline;
    project *local_project;
    char *first_word, *second_word, *value;
    first_word = (char *) calloc (100, sizeof (char));
    second_word = (char *) calloc (100, sizeof (char));
    value = (char *) calloc (100, sizeof (char));
    inputline = (char *) calloc (1024, (sizeof (char)));
    local_project = _alloc_mem (sizeof (project));
    // is the requested project file in the specified location?
    inputfile = fopen (filename, "r");
    if (inputfile == NULL) {// not found at current location
        free (inputline);
        free(local_project);
        free (first_word);
        free (second_word);
        free (value);
        free (local_project);
        rval = 1;
        return NULL;
    }
    rval = 0;
    // now, read the project file.
    fseek (inputfile, 0, SEEK_SET);
    while (1) {
        for (t = 0; t < 100; t++) {
            first_word[t] = '\0';
            second_word[t] = '\0';
            value[t] = '\0';
        }
        for (t = 0; t < 1024; t++) {
            inputline[t] = '\0';
        }
        if (fgets (inputline, 1024, inputfile) == NULL) {
            printf ("<particles> tag not found before end of file");
            local_project->num_particles = -1;
            break;
        }
        if (inputline[0] == '#') {
            continue;			/* comment in project file */
        }
        _parse_line (inputline, first_word, second_word, value);
        if ((strcmp ("<particles>", first_word)) == 0) {
            break;
        }
        if ((strcmp ("particle", first_word) == 0) && (strcmp ("population", second_word)) == 0) {
            local_project->num_particles = atoi (value);
            continue;
        }
        if ((strcmp ("states", first_word) == 0) && (strcmp ("required", second_word) == 0)) {
            local_project->states_required = atoi (value);
            continue;
        }
        if ((strcmp (first_word, "step") == 0)&& (strcmp (second_word, "count") == 0)) {
            local_project->number_of_steps_per_state = atoi (value);
            continue;
        }
        if ((strcmp ("step", first_word) == 0) && (strcmp ("size", second_word) == 0)) {
            local_project->step_size = atoi (value);        
            continue;
        }
        if ((strcmp ("collapsor", first_word) == 0) && (strcmp ("defined",second_word) == 0)) {
            local_project->collapsor = atoi (value);
            continue;
        }
        if ((strcmp ("gravitational", first_word) == 0) && (strcmp ("constant",second_word) == 0)) {
            local_project->G = atof (value);
            continue;
        }  
        if ((strcmp ("nbo", first_word) == 0) && (strcmp ("recording", second_word) == 0)) {
            if (strcmp ("TRUE", value) == 0) {
                local_project->nbo_write_direct = NBO_FILE_ON;
            }
            else {
                local_project->nbo_write_direct = NBO_FILE_OFF;
            }
        }
        if ((strcmp ("output", first_word) == 0) && (strcmp ("filename", second_word) == 0)) {
            strcpy (local_project->outputfilename, value);
            continue;
        }
        if ((strcmp ("use", first_word) == 0) && (strcmp ("stdout", second_word) == 0)) {
            if (strcmp ("TRUE", value) == 0) {
                local_project->use_stdout = 1;
            }
            else {
                local_project->use_stdout = 0;
            }
        }
        if ((strcmp ("write", first_word) == 0) && (strcmp ("project", second_word) == 0)) {
            if (strcmp ("TRUE", value) == 0) {
                local_project->write_project = TRUE;
            }
            else {
                local_project->write_project = FALSE;
            }
        }
        if ((strcmp ("nbo", first_word) == 0) && (strcmp ("recording", second_word) == 0)) {
            if (strcmp ("TRUE", value) == 0) { 
                local_project->nbo_required = NBO_ON;
            }
            else {
                local_project->nbo_required = NBO_OFF;
            }
        }
        if ((strcmp ("particle", first_word) == 0) && (strcmp ("info_size",second_word) == 0)) {
            local_project->particle_info_size = atoi (value);
        }
        if ((strcmp ("project", first_word) == 0) && (strcmp ("name", second_word) == 0)) {
            strcpy (local_project->project_name, value);
            continue;
        }
        if ((strcmp ("final_conditions", first_word) == 0) && (strcmp ("filename", second_word) == 0)) {
            strcpy (local_project->final_conditions_filename, value);
            continue;
        }
        if ((strcmp ("integration", first_word) == 0) && (strcmp ("method",second_word)== 0)) {
            if (strcmp ("RK4", value) == 0) {
                local_project->method = USE_RK4;
            }
            else if (strcmp ("MidPoint", value) == 0) {
                local_project->method = USE_MIDPOINT;
            }
            continue;
        }

    }
    /*
    reading particle data. First create the array to store them
*/
    local_project->particles = _alloc_mem_contiguous (local_project->num_particles,sizeof (particle));
    /*
    create the array to store integration values
*/
    local_project->store = _alloc_mem_contiguous (local_project->num_particles, sizeof (rk4_store));
    for (x = 0; x < local_project->num_particles; x++) {
        read_single_particle (inputfile, &(local_project->particles[x]),local_project->particle_info_size);
    }
    local_project->begin = _make_set_of_particle_pairs (local_project->num_particles);


    fclose (inputfile);
    free (inputline);
    free (first_word);
    free (second_word);
    free (value);
    return local_project;
}

