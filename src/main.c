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



//Author          : Carey Pridgeon 
// Email           : carey.pridgeon@gmail.com
// Description:  reference build main

#include "nmod.h"
int main (int argc, char *argv[]) {
    int ret_nb = 0;
    int ret = 0;

    // try to open the project file
    // this loads the nmp file specified at the command line, and allocates
    // memory to all the variables and arrays that nmod needs
    //The ea_project structure is global, and declared in nmod.h.  
    default_project = load_project_into_nmod ("reference_project.nmp",ret);
    if (ret == 1){
        printf("> Project file '%s' not found at specified location, exiting\n",argv[1]);
        exit(0);
    }

    ret_nb = NO_COLLISION;       
    ret_nb = run_nbody_environment (default_project);
    free_and_delete_project (default_project); // this must be called for every project that is instantiated in memory once the program is finished
    if (default_project->use_stdout) {
        printf("> Finished\n");
    }
    return 0;
}


