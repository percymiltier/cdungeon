#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

#include "mnames.h"

//init
Names::Names() {
	//populates the vectors with names
	normalNames = {"Slime", "Zombie", "Wolf", "Imp", "Ghost"};
	bossNames = {"Orc", "Assasin", "Giant Slime", "Demon", "Angered Zombie"};
}

// grabbers
string Names::getName(string type) const {
	int r = rand() % 5;
	if (type == "b") {
		// a boss enemy
		return bossNames.at(r);
	}
	// a normal enemy
	return normalNames.at(r);
}

// fancy ascii printer
void Names::printMon(string type) const {
	Sleep(500);

	if (type == "Slime") {
		cout << "\n\n";
		cout << "            .......           \n";
		cout << "        -#@*:.   .=#%%*=.\n";
		cout << "     .*#-              .=@= \n";
		cout << "   .**.                   =%.\n";
		cout << "   +*                      =#\n";
		cout << "   %.             =@@@%    :@\n";
		cout << "  -#.   :@@@%-   #@@@@@:   :@\n";
		cout << "  -#   .@@@@@@:  @@@#      :@ \n";
		cout << "  -#  .@@@@@%=             =+\n";
		cout << "  -#    -=-               =%. \n";
		cout << "  :%.                   .*# \n";
		cout << "   .*#-.             :+%+.\n";
		cout << "      .:-----------:::. \n";
		cout << "\n";
	}

	if (type == "Zombie") {
		cout << "\n\n";
		cout << "          ::-@@%%--%@#@+\n";
		cout << "         %.  .@       %#===\n";
		cout << "     +@*:     @        .@\n";
		cout << "    =-        @         %\n";
		cout << "   .@:       #+  -@@@@  %\n";
		cout << "   :@    @@@@@   @@@@@  % \n";
		cout << "    @@@@@@==     @@@@#  %\n";
		cout << "     @                 .@\n";
		cout << "     =@     *@@@*     @*\n";
		cout << "      :@            @# \n";
		cout << "       #@          @:\n";
		cout << "        @  %+   @  @\n";
		cout << "        @  @    @+##\n";
		cout << "\n";
	}

	if (type == "Wolf") {
		cout << "\n\n";
		cout << "                         =@@ \n";
		cout << "                    -@@:  @% \n";
		cout << "                :@@:      @%\n";
		cout << "           #@==*          @%\n";
		cout << "         %@ =@@.          @.\n";
		cout << "        %% @-@@.         -@:\n";
		cout << "     +@@%                @@@ \n";
		cout << "  @@@@.                  =@@*\n";
		cout << "  %@@@                    #@@\n";
		cout << "    @:     .*@@@@%%%*:.    @@:\n";
		cout << "      %@@=     @:          =@-\n";
		cout << "             @@             @%\n";
		cout << "       @@%%-%-              @%\n";
		cout << "         @@ \n";
		cout << "      @@@@@ \n";
		cout << "\n\n";
	}

	if (type == "Imp") {
		cout << "\n";
		cout << "          @@*       :@@\n";
		cout << "        *@ #=       =@@@= \n";
		cout << "      *@*  #@       #% @@-\n";
		cout << "     +@.   #@       %%  *@:\n";
		cout << "     @@     @%@@@@@@@@  .@@ \n";
		cout << "     @@ @@@=.         -: @@:\n";
		cout << "     @% -@@@+      =@@@- +@:\n";
		cout << "    =%%    @@@%   %@@*   =@:\n";
		cout << "    =%%    @@@   @@@@+   =@.\n";
		cout << "    -@%   =@@@-   @@@@   =@ \n";
		cout << "     @**  -@@@    @@@%   =@  \n";
		cout << "     #@@           %     +@ \n";
		cout << "      @@@                @-\n";
		cout << "         @@@@@@#------%@@* \n";
		cout << "             *@@@@@@@@@-\n";
		cout << "\n\n";
	}

	if (type == "Ghost") {
		cout << "\n";
		cout << "      @@@@@@@@@@@@+ \n";
		cout << "    @@@@           @@@= \n";
		cout << "   @@@@%            .@@@ \n";
		cout << "  -@@@               :@@@\n";
		cout << " .@@@    @:    %@:    =@%- \n";
		cout << " @@@    :@%-   %@-     @@@\n";
		cout << ".@@-     @@-   %@@      @@\n";
		cout << "%@@      #@              @:\n";
		cout << "%@-                      @@ \n";
		cout << "%@                        @@ \n";
		cout << "%@-                       #@.\n";
		cout << "%@%                 :-     @*\n";
		cout << "%@@     :@%       @@*=@@@#:@#\n";
		cout << "%@@.   @@#@@     %@      @@@@\n";
		cout << ":@@: %@@    @@@@@@\n";
		cout << "  @@@         =@@ \n";
		cout << "\n\n";
	}

}