#include "dfa.hpp"

int main()
{	
	Dfa *dfaOne = new Dfa();
	dfaOne->parseDfaFile("dfa1.txt");
	dfaOne->print();
	
	Dfa *dfaTwo = new Dfa();
	dfaTwo->parseDfaFile("dfa2.txt");
	dfaTwo->print();

	Dfa *dfaThree = dfaOne->intersection(*dfaTwo);
	return 0;
}
