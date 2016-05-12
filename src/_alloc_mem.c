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
// Description:  Function used to allocate memory to  single variables.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void *_alloc_mem (size_t size) {
    void *amount;
    amount = malloc (size);
    if (!amount) {
        printf ("\nno memory free - exiting\n");
        exit (errno);
    }
    return amount;
}
