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
// Description:   This function takes the local_particles array and an index into that array as input. 
//                         It applies the inertia of the body in question, and stores the remaining force for
//                         later application to the particle in question.

#include "nmod.h"
int _account_for_inertia (particle * local_particles, int index) {
    double temp1, temp2, temp3, resultx, resulty, resultz;
    /*
    get the summed forces acting on this body 
*/
    temp1 = (local_particles + index)->xforce;
    temp2 = (local_particles + index)->yforce;
    temp3 = (local_particles + index)->zforce;
    /*
    account for inertia to be overcome 
*/
    resultx = (temp1) / (local_particles + index)->mass;
    resulty = (temp2) / (local_particles + index)->mass;
    resultz = (temp3) / (local_particles + index)->mass;
    /*
    store the resultant force for each axis 
*/
    (local_particles + index)->grav_x = resultx;
    (local_particles + index)->grav_y = resulty;
    (local_particles + index)->grav_z = resultz;
    return 0;
}
