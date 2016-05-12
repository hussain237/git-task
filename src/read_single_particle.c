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
// Description:  Function to read in the data of a single particle


#include "nmod.h"
void read_single_particle (FILE * current_file, particle * single_particle, int datasize) {
    int i, t;
    char *inputline;
    char *first_word, *second_word, *value;
    first_word = (char *) calloc (100, sizeof (char));
    second_word = (char *) calloc (100, sizeof (char));
    value = (char *) calloc (100, sizeof (char));
    inputline = (char *) calloc (1024, (sizeof (char)));
    if (inputline == NULL) {
        fprintf (stderr, "malloc faliure in _read_single_particle\n");
        exit (0);
    }
    for (i = 0; i < datasize; i++) {
        for (t = 0; t < 100; t++) {
            first_word[t] = '\0';
            second_word[t] = '\0';
            value[t] = '\0';
        }
        for (t = 0; t < 1024; t++) {
            inputline[t] = '\0';
        }
        if ((fgets (inputline, 1024, current_file)) == NULL) {
            fprintf (stderr,
            "The particle datafile seems to be incorrectly formed\n");
        }
        _parse_line (inputline, first_word, second_word, value);
        if ((strcmp ("particle", first_word) == 0)
                && (strcmp ("ident", second_word) == 0)) {
            strcpy (single_particle->particle_id, value);
        }
        if ((strcmp ("particle", first_word) == 0)
                && (strcmp ("type", second_word) == 0)) {
            if ((strcmp ("massive_3", value) == 0)) {
                single_particle->type = MASSIVE_PARTICLE_3;
            }
            if ((strcmp ("massive_2", value) == 0)) {
                single_particle->type = MASSIVE_PARTICLE_2;
            }
            if ((strcmp ("massive_1", value) == 0)) {
                single_particle->type = MASSIVE_PARTICLE_1;
            }
            if ((strcmp ("major_2", value) == 0)) {
                single_particle->type = MAJOR_PARTICLE_2;
            }
            if ((strcmp ("major_1", value) == 0)) {
                single_particle->type = MAJOR_PARTICLE_1;
            }
            if ((strcmp ("minor_2", value) == 0)) {
                single_particle->type = MINOR_PARTICLE_2;
            }
            if ((strcmp ("minor_1", value) == 0)) {
                single_particle->type = MINOR_PARTICLE_1;
            }
        }
        if ((strcmp ("free", first_word) == 0)
                && (strcmp ("text", second_word) == 0)) {
            strcpy (single_particle->freetext, value);
        }
        if ((strcmp ("particle", first_word) == 0)
                && (strcmp ("mass", second_word) == 0)) {
            single_particle->mass = atof (value);
        }
        if ((strcmp ("particle", first_word) == 0)
                && (strcmp ("radius", second_word) == 0)) {
            single_particle->radius = atof (value);
        }
        if ((strcmp ("particle", first_word) == 0)
                && (strcmp ("red", second_word) == 0)) {
            single_particle->rgb_vals.r = atof (value);
        }
        if ((strcmp ("particle", first_word) == 0)
                && (strcmp ("green", second_word) == 0)) {
            single_particle->rgb_vals.g = atof (value);
        }
        if ((strcmp ("particle", first_word) == 0)
                && (strcmp ("blue", second_word) == 0)) {
            single_particle->rgb_vals.b = atof (value);
        }
        if ((strcmp ("X", first_word) == 0)
                && (strcmp ("position", second_word) == 0)) {
            single_particle->xloc = atof (value);
        }
        if ((strcmp ("Y", first_word) == 0)
                && (strcmp ("position", second_word) == 0)) {
            single_particle->yloc = atof (value);
        }
        if ((strcmp ("Z", first_word) == 0)
                && (strcmp ("position", second_word) == 0)) {
            single_particle->zloc = atof (value);
        }
        if ((strcmp ("X", first_word) == 0)
                && (strcmp ("velocity", second_word) == 0)) {
            single_particle->xsp = atof (value);
        }
        if ((strcmp ("Y", first_word) == 0)
                && (strcmp ("velocity", second_word) == 0)) {
            single_particle->ysp = atof (value);
        }
        if ((strcmp ("Z", first_word) == 0)
                && (strcmp ("velocity", second_word) == 0)) {
            single_particle->zsp = atof (value);
        }
    }
    // free things, and leave
    free (first_word);
    free (second_word);
    free (value);
}
