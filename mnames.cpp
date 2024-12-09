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
	bossNames = {"Witch", "Dragon", "Griffon", "Demon King", "Reaper"};
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
	Sleep(250);

	if (type == "Slime") {
		cout << "\n\n";
		cout << "        ........\n";
		cout << "     :@@@@@@@@@@@@@\n";
		cout << "   @@@            %@@\n";
		cout << "  @@                @\n";
		cout << "  @@    :@@@  *@@@   @\n";
		cout << "  @@    :@@@  *@@@   @\n";
		cout << "  @@                 @\n";
		cout << "   @@#             #@@\n";
		cout << "     =@%%%%%%%%%@@+:\n";
		cout << "\n";
	}

	if (type == "Zombie") {
		cout << "\n\n";
		cout << "                                .....\n";
		cout << "                               C C  / \n";
		cout << "                              /<   /\n";
		cout << "               ___ __________/_#__=o\n";
		cout << "              /(- /(\\_\\________   \\\n";
		cout << "              \\ ) \\ )_      \\o     \\\n ";
		cout << "              /|\\ /|\\       |'     |\n";
		cout << "                            |     _|\n";
		cout << "                            /o   __\\\n";
		cout << "                           / '     | \n";
		cout << "                          / /      | \n";
		cout << "                         /_/\\______|\n";
		cout << "\n";
	}

	if (type == "Wolf") {
		cout << "\n\n";
		cout << "                     .\n";
		cout << "                    / V\\\n";
		cout << "                  / `  /\n";
		cout << "                 <<   |\n";
		cout << "                 /    |\n";
		cout << "               /      |\n";
		cout << "             /        |\n";
		cout << "           /    \\  \\ /\n";
		cout << "          (      ) | |\n";
		cout << "  ________|   _/_  | |\n";
		cout << "<__________\______)\__)\n";
		cout << "\n";
	}

	if (type == "Imp") {
		cout << "\n\n";
		cout << "              v\n";
		cout << "        (__)v | v\n";
		cout << "        /\\/\\\\_|_/\n";
		cout << "       _\\__/  |\n";
		cout << "      /  \\/`\\<`)\n";
		cout << "      \\ (  |\\_/\n";
		cout << "      /)))-(  |\n";
		cout << "     / /^ ^ \\ |\n";
		cout << "    /  )^/\\^( |\n";
		cout << "    )_//`__>> |\n";
		cout << "      #   #`  |\n";
		cout << "\n";
	}

	if (type == "Ghost") {
		cout << "\n\n";
		cout << "       .-.\n";
		cout << "      ( \" )\n";
		cout << "   /\\_.' '._/\\\n";
		cout << "   |         |\n";
		cout << "    \\       /\n";
		cout << "     \\    /`\n";
		cout << "   (__)  /\n";
		cout << "   `.__.'\n";
		cout << "\n";
	}

	if (type == "Witch") {
		cout << "\n\n";
		cout << "           .-----.\n";
		cout << " \ ' /   _/    )/\n";
		cout << "- ( ) -('---''--)\n";
		cout << " / . \\((()\\^_^/)()\n";
		cout << "  \\\\_\\ (()_)-((()()\n";
		cout << "   '- \\ )/\\._./(()\n";
		cout << "     '/\\/( X   ) \\\n";
		cout << "     (___)|___/ ) \\\n";
		cout << "          |.#_|(___)\n";
		cout << "         /\\    \\ ( (_\n";
		cout << "         \\/\\/\\/\\) \\\\\n";
		cout << "         | / \\ |\n";
		cout << "         |(   \\|\n";
		cout << "        _|_)__|_\\_\n";
		cout << "        )...()...(\n";
		cout << "         | (   \\ |     \n";
		cout << "      .-'__,)  (  \\\n";
		cout << "                '\\_-,\n";
		cout << "\n";
	}

	if (type == "Dragon") {
		cout << "\n\n";
		cout << "                \\||/\n";
		cout << "                |  @___oo\n";
		cout << "      /\\  /\\   / (__,,,,|\n";
		cout << "     ) /^\\) ^\\/ _)\n";
		cout << "     )   /^\\/   _)\n";
		cout << "     )   _ /  / _)\n";
		cout << " /\\  )/\\/ ||  | )_)\n";
		cout << "<  >      |(,,) )__)\n";
		cout << " ||      /    \\)___)\\\n";
		cout << " | \\____(      )___) )___\n";
		cout << "  \\______(_______;;; __;;;\n";
		cout << "\n";
	}

	if (type == "Griffon") {
		cout << "\n\n";
		cout << "       _          (`-. \n";
		cout << "       \\`----.    ) ^_`)\n";
		cout << ",__     \\__   `\\_/  ( `\n";
		cout << " \\_\\      \\__  `|   }\n";
		cout << "   \\\\  .--' \\__/    }\n";
		cout << "    ))/   \\__,<  /_/\n";
		cout << "    ((|  _/_/ `\\ \\_\\_\n";
		cout << " jgs `\\_____\\\\  )__\\_\\\n";
		cout << "\n";
	}

	if (type == "Demon King") {
		cout << "\n\n";
		cout << "   ,    ,    /\\   /\\\n";
		cout << "  /( /\\ )\\  _\\ \\_/ /_\n";
		cout << "  |\\_||_/| < \\_   _/ >\n";
		cout << "  \\______/  \\|0   0|/\n";
		cout << "    _\\/_   _(_  ^  _)_\n";
		cout << "   ( () ) /`\\|V\"\"\"V|/`\\\n";
		cout << "     {}   \\  \\_____/  /\n";
		cout << "     ()   /\\   )=(   /\\\n";
		cout << "     {}  /  \\_/\\=/\\_/  \\\n";
		cout << "\n";
	}

	if (type == "Reaper") {
		cout << "\n\n";
		cout << "                   ,____\n";
		cout << "                   |---.\\\n";
		cout << "           ___     |    `\n";
		cout << "          / .-\\  ./=)\n";
		cout << "         |  |\" | _ / \\/|\n";
		cout << "         ;  |-;| /_|\n";
		cout << "";
		cout << "        / \\_| |/ \\ |\n";
		cout << "       /      \\/\\( |\n";
		cout << "       |   /  |` ) |\n";
		cout << "       /   \\ _/    |\n";
		cout << "      /--._/  \\    |\n";
		cout << "      `/|)    |    /\n";
		cout << "        /     |   |\n";
		cout << "      .'      |   |\n";
		cout << "     /         \\  |\n";
		cout << "    (_.-.__.__./  /\n";
		cout << "\n";
	}

}