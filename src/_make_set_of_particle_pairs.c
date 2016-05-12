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
// Description:  This function takes as input the amount of bodies in the simulation, and 
//                        returns a pointer to the top of a linked list of pairs without duplicates.

#include "nmod.h"
particle_pair *_make_set_of_particle_pairs (int amount) {
    /*
    get list to make SET without duplicates from simple FOR loops
*/
    int i, j, k;
    particle_pair *first;
    particle_pair *old;
    particle_pair *latest;
    /*
    make the first link in the list, and a pointer to it 
*/
    first = _create_particle_pairs_node (-1, -1);
    old = _create_particle_pairs_node (-1, -1);
    old->next = first;
    latest = _create_particle_pairs_node (-1, -1);
    k = amount;
    /*
    now make the list 
*/
    for (i = amount - 1; i > -1; i--) {
        for (j = k - 1; j > -1; j--) {
            if (i == j) {
                continue;
            }
            latest = _create_particle_pairs_node (i, j);
            latest->next = old->next;
            old->next = latest;
        }
        k--;
    }
    /*
    free up unused particle_pairs before finishing 
*/
    old = NULL;
    first = NULL;
    free (old);
    free (first);
    return latest;
};
