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
// Description:   Simple function to parse a line of text and tokenise it into three words.
//                         pretty basic really, can only do three words.

#include "nmod.h"
void _parse_line (char *input, char *word1, char *word2, char *word3) {
    int a, pos;
    a = pos = 0;

    while (1) {
        while ((input[pos] != '\0') && (input[pos] != ' ')
        && (input[pos] != '\n') && (input[pos] != '\r')) {
            word1[a] = input[pos];
            a++;
            pos++;
        }
        if (input[pos] == '\0') {
            break;
        }
        a = 0;
        pos++;
        while ((input[pos] != '\0') && (input[pos] != ' ')
        && (input[pos] != '\n') && (input[pos] != '\r')) {
            word2[a] = input[pos];
            a++;
            pos++;
        }
        if (input[pos] == '\0') {
            break;
        }
        a = 0;
        pos++;
        while ((input[pos] != '\0') && (input[pos] != ' ')
        && (input[pos] != '\n') && (input[pos] != '\r')) {
            word3[a] = input[pos];
            a++;
            pos++;
        }
        if (input[pos] == '\0') {
            break;
        }
    }
}
