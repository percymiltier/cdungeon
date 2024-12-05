
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
	if (type == "n") {
		// a normal enemy
		return normalNames.at(r);
	}
	else if (type == "b") {
		// a boss enemy
		return bossNames.at(r);
	}
}