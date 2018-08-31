#include <fstream>
#include <sstream>
#include "dfa.hpp"
#include <iterator>

Dfa::Dfa()
{
	_numStates = 0;
	_alphabet = 0;
}

Dfa::~Dfa() {}
void Dfa::parseDfaFile(std::string fileName)
{
	std::string line;
	std::ifstream dfaFile(fileName);

	if(!dfaFile.is_open())
	{
		std::cout << "error opening file\n";
		return ;
	}
	
	std::getline(dfaFile,line);
	std::stringstream(line) >> _numStates >> _alphabet;

	//Storing final states
	std::getline(dfaFile,line);
	std::stringstream finalStates(line);
	std::copy(std::istream_iterator<int >(finalStates),std::istream_iterator<int >(),std::back_inserter(_finalStates));
	
	//save delta transitions
	for(int i = 0 ; i < _numStates; i ++)
	{
		std::getline(dfaFile,line);
		std::stringstream finalStates(line);
		std::copy(std::istream_iterator<int >(finalStates),std::istream_iterator<int >(),std::back_inserter(_deltaFunction));
		
	}
	dfaFile.close();
}

Dfa *Dfa::intersection(Dfa &other)
{
	Dfa *dfa = new Dfa();
	dfa->setNumStates(_numStates * other.numStates());
	dfa->setAlphabet(_alphabet);
	int numOne = 0;
	int numTwo = 0;
	std::string stateArray[dfa->numStates()];
	std::string state = "";
	//use lazy algorithim
	int queue = 0;
	bool eval = true;

	while(eval)
	{
		eval = false;
	}
	for(int i = 0 ; i < _numStates; i++)
	{
		for(int j = 0 ; j < _alphabet; j ++)
		{
			std::cout << "state " << i << " on " << j << " goes to: " << _deltaFunction.at(i + j) << std::endl;
		}
	}
	dfa->print();
	return dfa;
}

void Dfa::print()
{
	std::cout << "numStates: " << _numStates << std::endl;
	std::cout << "alphabet: " << _alphabet   << std::endl;
	std::cout << "Final States: ";
	for(int i : _finalStates)
		std::cout << i << " " ;
	std::cout << "\nDelta Function: " ;
	for(int i : _deltaFunction)
		std::cout << i << " " ;
	std::cout <<  std::endl;
	std::cout <<  std::endl;
}
