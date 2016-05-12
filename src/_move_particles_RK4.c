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
// Description:   Fourth Order Runge Kutta Integration method.
//                        Scary math description:
//                         k1 = hf(xn,yn)
//                         k2 = hf(xn+h/2,yn+ k1/2)
//                         k3 = hf(xn+h/2. yn+k2/2)
//                         k4 = hf(xn+h,yn+k3)
//                        yn+1 =yn + k1/6 + k2/3 + k3/3 + k4/6 +O(h^5)

#include "nmod.h"
int _move_particles_RK4 (particle * local_particles, rk4_store * local_store,
int time, int num_local_particles, particle_pair * begin,
int collapsor, double G) {
    
    int i, j, a, k, c, n, r, l, x, o, p, t, f, w, v;

    /*
    obtain the first derivative 
*/
    _convert_gravitational_effects_into_velocity (local_particles, num_local_particles, begin, G);

    /*
    store out the initial x,y location, speed and _convert_gravitational_effects_into_velocity of all particles 
*/
    for (k = 0; k < num_local_particles; k++) {
        if (k != collapsor) {	/*if not the sun */
            (local_particles + k)->xloctemp = (local_particles + k)->xloc;
            (local_particles + k)->yloctemp = (local_particles + k)->yloc;
            (local_particles + k)->zloctemp = (local_particles + k)->zloc;
            (local_particles + k)->xsptemp = (local_particles + k)->xsp;
            (local_particles + k)->ysptemp = (local_particles + k)->ysp;
            (local_particles + k)->zsptemp = (local_particles + k)->zsp;
            /*
        temp _convert_gravitational_effects_into_velocity local_store array 
    */
            (local_store + k)->xforce1 = (local_particles + k)->grav_x;
            (local_store + k)->yforce1 = (local_particles + k)->grav_y;
            (local_store + k)->zforce1 = (local_particles + k)->grav_z;
        }
    }

    /*
    move the particles to the first trial mid point 
*/
    for (a = 0; a < time / 2; a++) {
        for (j = 0; j < num_local_particles; j++) {
            if (j != collapsor) {	/*if not the sun */
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
    obtain the second midpoint derivative 
*/
    _convert_gravitational_effects_into_velocity (local_particles, num_local_particles, begin, G);

    /*
    store that out into the derivatives local_store array 
*/
    for (i = 0; i < num_local_particles; i++) {
        if (i != collapsor) {	/*if not the sun */
            (local_store + i)->xforce2 = (local_particles + i)->grav_x;
            (local_store + i)->yforce2 = (local_particles + i)->grav_y;
            (local_store + i)->zforce2 = (local_particles + i)->grav_z;
        }
    }

    /*
    swap the start condition for the particles back in 
*/
    for (c = 0; c < num_local_particles; c++) {
        if (c != collapsor) {	/*if not the sun */
            (local_particles + c)->xloc = (local_particles + c)->xloctemp;
            (local_particles + c)->yloc = (local_particles + c)->yloctemp;
            (local_particles + c)->zloc = (local_particles + c)->zloctemp;
            (local_particles + c)->xsp = (local_particles + c)->xsptemp;
            (local_particles + c)->ysp = (local_particles + c)->ysptemp;
            (local_particles + c)->zsp = (local_particles + c)->zsptemp;
        }
    }

    /*
    move particles  to the second trial mid point 
*/
    for (r = 0; r < time / 2; r++) {
        for (l = 0; l < num_local_particles; l++) {
            if (l != collapsor) {	/*if not the sun */
                (local_particles + l)->xsp += (local_particles + l)->grav_x;
                (local_particles + l)->ysp += (local_particles + l)->grav_y;
                (local_particles + l)->zsp += (local_particles + l)->grav_z;
                (local_particles + l)->xloc += (local_particles + l)->xsp;
                (local_particles + l)->yloc += (local_particles + l)->ysp;
                (local_particles + l)->zloc += (local_particles + l)->zsp;
            }
        }
    }
    /***************
    * step three  *
    ***************
    */
    /*
    obtain the third midpoint derivative 
*/
    _convert_gravitational_effects_into_velocity (local_particles, num_local_particles, begin, G);

    /*
    store these out into the derivatives local_store array 
*/
    for (x = 0; x < num_local_particles; x++) {
        if (x != collapsor) {	/*if not the sun */
            (local_store + x)->xforce3 = (local_particles + x)->grav_x;
            (local_store + x)->yforce3 = (local_particles + x)->grav_y;
            (local_store + x)->zforce3 = (local_particles + x)->grav_z;
        }
    }

    /*
    swap the start condition for the particles back in 
*/
    for (n = 0; n < num_local_particles; n++) {
        if (n != collapsor) {	/*if not the sun */
            (local_particles + n)->xloc = (local_particles + n)->xloctemp;
            (local_particles + n)->yloc = (local_particles + n)->yloctemp;
            (local_particles + n)->zloc = (local_particles + n)->zloctemp;
            (local_particles + n)->xsp = (local_particles + n)->xsptemp;
            (local_particles + n)->ysp = (local_particles + n)->ysptemp;
            (local_particles + n)->zsp = (local_particles + n)->zsptemp;
        }
    }

    /*
    move particles across the whole interval using the third derivatives 
*/
    for (o = 0; o < time; o++) {
        for (p = 0; p < num_local_particles; p++) {
            if (p != collapsor) {	/*if not the sun */
                (local_particles + p)->xsp += (local_particles + p)->grav_x;
                (local_particles + p)->ysp += (local_particles + p)->grav_y;
                (local_particles + p)->zsp += (local_particles + p)->grav_z;
                (local_particles + p)->xloc += (local_particles + p)->xsp;
                (local_particles + p)->yloc += (local_particles + p)->ysp;
                (local_particles + p)->zloc += (local_particles + p)->zsp;
            }
        }
    }

    /***************
    * step four   *
    ***************
    */
    /*
    obtain the fourth derivative 
*/
    _convert_gravitational_effects_into_velocity (local_particles, num_local_particles, begin, G);

    /*
    store  out into the derivatives local_store array 
*/
    for (t = 0; t < num_local_particles; t++) {
        if (t != collapsor) {	/*if not the sun */
            (local_store + t)->xforce4 = (local_particles + t)->grav_x;
            (local_store + t)->yforce4 = (local_particles + t)->grav_y;
            (local_store + t)->zforce4 = (local_particles + t)->grav_z;
        }
    }

    /***************
    * Final stage *
    ***************
    */

    /*
    swap the start condition for the particles back in 
*/
    for (f = 0; f < num_local_particles; f++) {
        if (f != collapsor) {	/*if not the sun */
            (local_particles + f)->xloc = (local_particles + f)->xloctemp;
            (local_particles + f)->yloc = (local_particles + f)->yloctemp;
            (local_particles + f)->zloc = (local_particles + f)->zloctemp;
            (local_particles + f)->xsp = (local_particles + f)->xsptemp;
            (local_particles + f)->ysp = (local_particles + f)->ysptemp;
            (local_particles + f)->zsp = (local_particles + f)->zsptemp;
        }
    }

    /*
    Move the particles across the whole interval,
    * adding the derivatives from each step with
    * the correct weights
*/

    for (v = 0; v < time; v++) {
        for (w = 0; w < num_local_particles; w++) {
            if (w != collapsor) {	/*if not the sun */
                (local_particles + w)->xsp +=
                ((local_store + w)->xforce1 + (local_store + w)->xforce4 +
                (2 * (local_store + w)->xforce2) +
                (2 * (local_store + w)->xforce3)) / 6;
                (local_particles + w)->ysp +=
                ((local_store + w)->yforce1 + (local_store + w)->yforce4 +
                (2 * (local_store + w)->yforce2) +
                (2 * (local_store + w)->yforce3)) / 6;
                (local_particles + w)->zsp +=
                ((local_store + w)->zforce1 + (local_store + w)->zforce4 +
                (2 * (local_store + w)->zforce2) +
                (2 * (local_store + w)->zforce3)) / 6;
                (local_particles + w)->xloc += (local_particles + w)->xsp;
                (local_particles + w)->yloc += (local_particles + w)->ysp;
                (local_particles + w)->zloc += (local_particles + w)->zsp;
            }
        }
    }

    return 1;
}				/* end of runge Kutta Fourth order integration function */
