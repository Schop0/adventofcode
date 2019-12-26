#include "IntCodeProgram.h"

IntCodeProgram::IntCodeProgram(std::vector<int> code) : intCode(code) {
	programCounter = 0;
}

void IntCodeProgram::initInputs(int noun, int verb)
{
	set(1, noun);
	set(2, verb);
}

int IntCodeProgram::getOutput()
{
	return get(0);
}

int IntCodeProgram::nextInt()
{
	return intCode[programCounter++];
}

int IntCodeProgram::get(int position)
{
	return intCode[position];
}

void IntCodeProgram::set(int position, int value)
{
	intCode[position] = value;
}

void IntCodeProgram::print(std::ostream &output) {
	for (int n : intCode) {
		output << n << ' ';
	}
}


