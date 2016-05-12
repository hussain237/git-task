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
// Description:  This function takes as input a bodies array and 
//                         the total number of bodies in that array. It calls 
//                         the account_for_inertia function for each element of the bodies array

#include "nmod.h"
int _find_meters_per_second_velocity (particle *local_bodies, int num_local_bodies) {
    int i;
    for (i = 0; i < num_local_bodies; i++) {
        _account_for_inertia (local_bodies, i);
    }
    return 0;
}


