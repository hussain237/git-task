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
// Description:   Function used to allocate memory to dynamic arrays.

#include "nmod.h"
void *_alloc_mem_contiguous (int length, size_t size) {
    void *amount;
    amount = calloc (length, size);
    if (amount == NULL) {
        printf ("\nno memory free for calloc - exiting\n");
        exit (errno);
    }
    return amount;
}
