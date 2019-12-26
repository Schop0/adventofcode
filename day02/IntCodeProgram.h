#pragma once

#include <vector>
#include <istream>

class IntCodeProgram
{
public:
	IntCodeProgram(std::vector<int>);

	void initInputs(int noun, int verb);
	int getOutput();
	int nextInt();
	int get(int position);
	void set(int position, int value);
	void print(std::ostream&);

private:
	std::vector<int> intCode;
	int programCounter;
};
