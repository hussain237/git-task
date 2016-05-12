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
// Description:    This function deletes the particle  pairs linked list

#include "nmod.h"
int _delete_list_of_pairs (particle_pair *begin) {
    particle_pair *temp;
    /*
    go through the linked list of pairs 
*/
    do {
        temp = begin;
        begin = begin->next;
        free (temp);
    }
    while (begin);
    return 0;
}
