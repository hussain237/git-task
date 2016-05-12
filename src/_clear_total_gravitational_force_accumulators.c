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
// Description:  This function resets the accumulator fields of the local_particles array that store the sum of 
//                        gravitational forces for the particles

#include "nmod.h"

int _clear_total_gravitational_force_accumulators (particle * local_particles, int num_local_particles) {
    int i;
    for (i = 0; i < num_local_particles; i++) {
        (local_particles + i)->xforce = 0.0;
        (local_particles + i)->yforce = 0.0;
        (local_particles + i)->zforce = 0.0;
    }
    return 0;
}
