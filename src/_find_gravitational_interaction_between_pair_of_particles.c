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
// Description:  This function takes as the array of particles, and two 
//                         indexes into that array, and outputs the
//                         gravitational forces between thos particles. 
//                        The indexes have to be valid, as there are no checks.


#include "nmod.h"
int _find_gravitational_interaction_between_pair_of_particles (particle * local_particles, int m1, int m2, double G) {
    double a, b, c, d, e, grav_force;
    double t1, t2, t3, res1, res2, bit;
    /*
    get the distance 
*/
    a = (local_particles + m1)->xloc - (local_particles + m2)->xloc;
    b = (local_particles + m1)->yloc - (local_particles + m2)->yloc;
    e = (local_particles + m1)->zloc - (local_particles + m2)->zloc;
    c = (sqr (a) + sqr (b) + sqr (e));
    d = sqrt (c);
    /*
    now calculate gravitational force 
*/
    grav_force =
    G * ((local_particles + m1)->mass * (local_particles + m2)->mass) / c;
    /*
    ########################################################
    * # Sum gravitational forces in the accumulator array.   #
    * # This applies each gravitational force to the body    #
    * # in question,taking account of relative positions of  #
    * # local_particles in the WCS.                          #
    * ########################################################
*/
    /*
    test to find in which direction force must be applied 
*/
    /*
    X for m1 first 
*/
    t1 = (local_particles + m1)->xloc;
    t2 = (local_particles + m2)->xloc;
    res1 = sqr (t1 - t2);
    /*
    take 1/4 of the distance. This will be used as the bit to add 
*/
    bit = res1 / 4;
    t3 = (local_particles + m1)->xloc + bit;
    res2 = sqr (t3 - t2);
    if (res2 < res1) {
        /*
    direction to apply force to m1 found 
    */
        (local_particles + m1)->xforce += (grav_force * a / d);
    }
    else {
        (local_particles + m1)->xforce -= (grav_force * a / d);
    }
    /*
    X for m2 now 
*/
    t1 = (local_particles + m1)->xloc;
    t2 = (local_particles + m2)->xloc;
    res1 = sqr (t1 - t2);
    /*
    take 1/4 of the distance. This will be used as the bit to add 
*/
    bit = res1 / 4;
    t3 = (local_particles + m2)->xloc + bit;
    res2 = sqr (t3 - t1);
    if (res2 < res1) {
        /*
    direction to apply force to m2 found 
    */
        (local_particles + m2)->xforce += (grav_force * a / d);
    }
    else {
        (local_particles + m2)->xforce -= (grav_force * a / d);
    }
    /*
    Y for m1 first 
*/
    t1 = (local_particles + m1)->yloc;
    t2 = (local_particles + m2)->yloc;
    res1 = sqr (t1 - t2);
    /*
    take 1/4 of the distance. This will be used as the bit to add 
*/
    bit = res1 / 4;
    t3 = (local_particles + m1)->yloc + bit;
    res2 = sqr (t3 - t2);
    if (res2 < res1) {
        /*
    direction to apply force to m1 found 
    */
        (local_particles + m1)->yforce += (grav_force * b / d);
    }
    else {
        (local_particles + m1)->yforce -= (grav_force * b / d);
    }
    /*
    Y for m2 now 
*/
    t1 = (local_particles + m1)->yloc;
    t2 = (local_particles + m2)->yloc;
    res1 = sqr (t1 - t2);
    /*
    take 1/4 of the distance. This will be used as the bit to add 
*/
    bit = res1 / 4;
    t3 = (local_particles + m2)->yloc + bit;
    res2 = sqr (t3 - t1);
    if (res2 < res1) {
        /*
    direction to apply force to m2 found 
    */
        (local_particles + m2)->yforce += (grav_force * b / d);
    }
    else {
        (local_particles + m2)->yforce -= (grav_force * b / d);
    }
    /*
    Z for m1 first 
*/
    t1 = (local_particles + m1)->zloc;
    t2 = (local_particles + m2)->zloc;
    res1 = sqr (t1 - t2);
    /*
    take 1/4 of the distance. This will be used as the bit to add 
*/
    bit = res1 / 4;
    t3 = (local_particles + m1)->zloc + bit;
    res2 = sqr (t3 - t2);
    if (res2 < res1) {
        /*
    direction to apply force to m1 found 
    */
        (local_particles + m1)->zforce += (grav_force * e / d);
    }
    else {
        (local_particles + m1)->zforce -= (grav_force * e / d);
    }
    /*
    Z for m2 now 
*/
    t1 = (local_particles + m1)->zloc;
    t2 = (local_particles + m2)->zloc;
    res1 = sqr (t1 - t2);
    /*
    take 1/4 of the distance. This will be used as the bit to add 
*/
    bit = res1 / 4;
    t3 = (local_particles + m2)->zloc + bit;
    res2 = sqr (t3 - t1);
    if (res2 < res1) {
        /*
    direction to apply force to m2 found 
    */
        (local_particles + m2)->zforce += (grav_force * e / d);
    }
    else {
        (local_particles + m2)->zforce -= (grav_force * e / d);
    }
    return 0;
}
