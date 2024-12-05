#ifndef NAMES_H
#define NAMES_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Names {
	// class for grabbing a random name for monsters

public:
	// init
	Names();

	// grabbers
	string getName(string type) const;

private:
	vector<string> normalNames;
	vector<string> bossNames;
};

#endif

