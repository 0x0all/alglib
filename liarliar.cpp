#include <list>
#include <iostream>
#include <fstream>
#include "liarliar.h"

//
//  helper function for Club class
//
static void liarliar_string_parse(const std::string& str)
{
	std::string::const_iterator cit;

	for (cit = str.begin(); cit!=str.end(); cit++) {
		if (' ' != *cit) {
			std::cout << *cit << std::endl;
		}
	}
}


//
// class Club
//
int Club::build_club(const char* filename)
{
	const int IN_FIRST_LINE = 0;
	const int NOT_IN_FIRST_LINE = 1;
	
	int __line = IN_FIRST_LINE;
	int lie_teller_line;
	std::ifstream infile;
	char name[256];

	infile.open(filename, std::ifstream::in);
	while (infile.good()) {
		infile.getline(name, (sizeof name / sizeof name[0]));
		if (IN_FIRST_LINE == __line) {
			this->_nr_members = atoi(name);
			__line = NOT_IN_FIRST_LINE;
		} else {
			std::string line_str(name);
			liarliar_string_parse(line_str);
		}
		//std::cout << name << std::endl;
	}
	infile.close();
	return 0;
}


int main(int argc, char** argv)
{
	Club club;
	club.build_club("liarliar_input.txt");
	return 0;
}
