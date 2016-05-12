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
// Description:  This function calls the _find_gravitational_interaction_between_pair_of_particles function once for each pair in the pairs linked list.

#include "nmod.h"
int _calculate_forces_acting_between_all_particles (particle_pair * begin, particle * local_particles, double G) {
    int i, j;
    //go through the linked list of particle pairs 
    while (begin->m1 != -1) {
        while (begin->next != NULL) {
            i = begin->m1;
            j = begin->m2;
            _find_gravitational_interaction_between_pair_of_particles (local_particles, i, j, G);
            begin = begin->next;
        }
    }
    return 0;
}
