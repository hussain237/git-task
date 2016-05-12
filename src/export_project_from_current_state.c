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
// Description:  writes out the current state of all particles in the model. 
// Preceedes this with the nmp file entry fro the number of particles.
// All other nmp file information must be added manually.

#include "nmod.h"
int export_project_from_current_state (char *filename, project * subject) {
    int i;
    FILE *out;
    out = fopen (filename, "w");
    if (out == NULL) {
        fprintf (stderr,
        "> +++ FTB error +++ replace fluffy teddy bear to continue +++\n");
        fprintf (stderr,
        "> (Unable to create file to store the final state in nmp format)\n");
    }
    fprintf (out, "# the number of particles in this project\n");
    fprintf (out, "particle population %d\n", subject->num_particles);
    fprintf (out, "#\n");
    fprintf (out, "<particles>");	// newline handled below
    /*
    writing particle data 
*/
    for (i = 0; i < subject->num_particles; i++) {
        fprintf (out, "\nparticle ident %s",
        (subject->particles + i)->particle_id);
        if ((subject->particles + i)->type == MASSIVE_PARTICLE_3) {
            fprintf (out, "\nparticle type massive_3");
        }
        if ((subject->particles + i)->type == MASSIVE_PARTICLE_2) {
            fprintf (out, "\nparticle type massive_2");
        }
        if ((subject->particles + i)->type == MASSIVE_PARTICLE_1) {
            fprintf (out, "\nparticle type massive_1");
        }
        if ((subject->particles + i)->type == MAJOR_PARTICLE_2) {
            fprintf (out, "\nparticle type major_2");
        }
        if ((subject->particles + i)->type == MAJOR_PARTICLE_1) {
            fprintf (out, "\nparticle type major_1");
        }
        if ((subject->particles + i)->type == MINOR_PARTICLE_2) {
            fprintf (out, "\nparticle type minor_2");
        }
        if ((subject->particles + i)->type == MINOR_PARTICLE_1) {
            fprintf (out, "\nparticle type minor_1");
        }
        fprintf (out, "\nparticle red %d", (subject->particles + i)->rgb_vals.r);
        fprintf (out, "\nparticle green %d",
        (subject->particles + i)->rgb_vals.g);
        fprintf (out, "\nparticle blue %d", (subject->particles + i)->rgb_vals.b);
        fprintf (out, "\nfree text %s", (subject->particles + i)->freetext);
        fprintf (out, "\nX position %.10e", (subject->particles + i)->xloc);
        fprintf (out, "\nY position %.10e", (subject->particles + i)->yloc);
        fprintf (out, "\nZ position %.10e", (subject->particles + i)->zloc);
        fprintf (out, "\nX velocity %.10e", (subject->particles + i)->xsp);
        fprintf (out, "\nY velocity %.10e", (subject->particles + i)->ysp);
        fprintf (out, "\nZ velocity %.10e", (subject->particles + i)->zsp);
    }
    fclose (out);
    return 0;
}
