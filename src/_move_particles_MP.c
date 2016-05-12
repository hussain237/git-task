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
// Description:  Mid Point Integration method

#include "nmod.h"
int _move_particles_MP (particle * local_particles, rk4_store * local_store, int
time, int num_local_particles, particle_pair * begin,
int collapsor, double G) {
    int j, a, k, c, r, l;
    /********************************************
* preperation for Mid Point Integration    *                      
********************************************
*/
    /*
    obtain the first derivative 
*/
    _convert_gravitational_effects_into_velocity (local_particles, num_local_particles, begin, G);
    /*
    store out the initial x,y location, speed and _convert_gravitational_effects_into_velocity of all particles 
*/
    for (k = 0; k < num_local_particles; k++) {
        if (k != collapsor) {
            /*
        if not the sun 
    */
            (local_particles + k)->xloctemp = (local_particles + k)->xloc;
            (local_particles + k)->yloctemp = (local_particles + k)->yloc;
            (local_particles + k)->zloctemp = (local_particles + k)->zloc;
            (local_particles + k)->xsptemp = (local_particles + k)->xsp;
            (local_particles + k)->ysptemp = (local_particles + k)->ysp;
            (local_particles + k)->zsptemp = (local_particles + k)->zsp;
        }
    }
    /*
    move the particles to the mid point of the step 
*/
    for (a = 0; a < time / 2; a++) {
        for (j = 0; j < num_local_particles; j++) {
            if (j != collapsor) {
                /*
    if not the sun 
    */
                (local_particles + j)->xsp += (local_particles + j)->grav_x;
                (local_particles + j)->ysp += (local_particles + j)->grav_y;
                (local_particles + j)->zsp += (local_particles + j)->grav_z;
                (local_particles + j)->xloc += (local_particles + j)->xsp;
                (local_particles + j)->yloc += (local_particles + j)->ysp;
                (local_particles + j)->zloc += (local_particles + j)->zsp;
            }
        }
    }
    /***********
* Step two *
************
*/
    /*
    obtain the midpoint derivative 
*/
    _convert_gravitational_effects_into_velocity (local_particles, num_local_particles, begin, G);
    /*
    swap the start condition for the particles back in 
*/
    for (c = 0; c < num_local_particles; c++) {
        if (c != collapsor) {
            /*
        if not the sun 
    */
            (local_particles + c)->xloc = (local_particles + c)->xloctemp;
            (local_particles + c)->yloc = (local_particles + c)->yloctemp;
            (local_particles + c)->zloc = (local_particles + c)->zloctemp;
            (local_particles + c)->xsp = (local_particles + c)->xsptemp;
            (local_particles + c)->ysp = (local_particles + c)->ysptemp;
            (local_particles + c)->zsp = (local_particles + c)->zsptemp;
        }
    }
    /*
    move particles  across the entire step 
*/
    for (r = 0; r < time; r++) {
        for (l = 0; l < num_local_particles; l++) {
            if (l != collapsor) {
                /*
    if not the sun 
    */
                (local_particles + l)->xsp += (local_particles + l)->grav_x;
                (local_particles + l)->ysp += (local_particles + l)->grav_y;
                (local_particles + l)->zsp += (local_particles + l)->grav_z;
                (local_particles + l)->xloc += (local_particles + l)->xsp;
                (local_particles + l)->yloc += (local_particles + l)->ysp;
                (local_particles + l)->zloc += (local_particles + l)->zsp;
            }
        }
    }
    return 1;
}				/* end of Mid Point integration function */
