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
// Description:   This function creates a node for the particle pairs linked list, or exits on error
#include "nmod.h"
particle_pair *_create_particle_pairs_node (int location1, int location2) {
    particle_pair *temp = (particle_pair *) malloc (sizeof (particle_pair));	/* allocate memory for this
                            particle_pair */
    if (temp == NULL) {
        /*
    Errooor! 
    */
        fprintf (stderr,
        "memory allocation failure on pairs list creation - exiting");
        exit (errno);
    }
    /*
    memory is available 
*/
    temp->m1 = location1;
    temp->m2 = location2;
    temp->next = NULL;
    return temp;
}				/*end */
