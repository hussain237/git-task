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
// Description:   This header file contains all the defines, either  macro's or constants, used by nMod. Add all new 
//                          defines in here.
//                          Do not reference this header file directly in your *.c files. Instead reference nmod.h, which includes 
//                          this header file.

#ifndef nmod_definesH
#define nmod_definesH

/*definition of square function*/
#define sqr(x) ((x)*(x))

#define MASSIVE_PARTICLE_3 7
#define MASSIVE_PARTICLE_2 6
#define MASSIVE_PARTICLE_1 5
#define MAJOR_PARTICLE_2 4
#define MAJOR_PARTICLE_1 3
#define MINOR_PARTICLE_2 2
#define MINOR_PARTICLE_1 1

#define ACCELARATION_DUE_TO_GRAVITY 9.81

#define TRUE 1
#define FALSE 0

#define NBO_ON 1
#define NBO_OFF 0
#define NBO_TEMPFILE_ON 1
#define NBO_TEMPFILE_OFF 0
#define NBO_MEMORY_ON 1
#define NBO_MEMORY_OFF 0
#define NBO_FILE_ON 1
#define NBO_FILE_OFF 0
#define RECORD_TO_FILE 0
#define RECORD_TO_TEMP_FILE 2
#define PROGRESS_CHECKING_ON 1
#define PROGRESS_CHECKING_OFF 1
#define COLLISION_CHECKING_ON 1
#define COLLISION_CHECKING_OFF 0
#define DISTANCES_COLLECTION_ON 1
#define DISTANCES_COLLECTION_OFF 0
#define pre_evolution_GROUP_ON 1
#define pre_evolution_GROUP_OFF 0
#define LARGE 1
#define SMALL 0
#define SPECIFIC_IMPULSE 0
#define EXHAUST_VELOCITY 1
#define USE_RK4 0
#define USE_MIDPOINT 1
#define COLLISION_OCCURED 1
#define NO_COLLISION 0
#define ONE_PARTICLE_PAIR 1
#define TWO_PARTICLE_PAIRS 2
#define TEN 10
#define HUNDRED 100
#define THOUSAND 1000
#define FIFTY_THOUSAND 50000
#define HUNDRED_THOUSAND 100000
#define HALF_MILLION 500000
#define MILLION 1000000
#define FIVE_MILLION 5000000
#define TEN_MILLION 10000000
#define BILLION 1000000000

#define LOW_EARTH_ORBIT 2000000
// define that means write to the temp particle
#define TEMP_PARTICLE -1
#define PI 3.141592653589793
#define PI_AS_INT 314
#endif
