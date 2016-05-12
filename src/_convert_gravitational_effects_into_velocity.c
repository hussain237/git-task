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
// Description:    This function takes as input the local_particles array, the number of local_particles, 
//                          and a pointer to the top of the linked list of pairs as input. 
//                          It calls the _calculate_forces_acting_between_all_particles and get_kps functions, and returns the
//                          derivatives for this step

#include "nmod.h"
int _convert_gravitational_effects_into_velocity (particle * local_particles, int num_local_particles, particle_pair *begin, double G) {
    /*
    reset forces accumulator 
*/
    _clear_total_gravitational_force_accumulators (local_particles, num_local_particles);
    /*
    get gravitational forces 
*/
    _calculate_forces_acting_between_all_particles (begin, local_particles, G);
    /*
    translate these into movements on x, y and z per second 
*/
    _find_meters_per_second_velocity (local_particles, num_local_particles);
    return 0;
}

