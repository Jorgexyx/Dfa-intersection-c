#ifndef __DFA__HPP
#define __DFA__HPP

#include <iostream>
#include <string>
#include <vector>

class Dfa
{
	public:
		Dfa();
		~Dfa();
		void parseDfaFile(std::string fileName);
		Dfa *intersection(Dfa &other);
		void print();
	
		void setNumStates(int numStates) { _numStates = numStates; }
		void setAlphabet(int alph) 	 { _alphabet = alph ;}
		int numStates() { return _numStates;}
		
	private:
		int _numStates;
		int _alphabet;
		std::vector<int > _finalStates;
		std::vector<int > _deltaFunction;
};
#endif
