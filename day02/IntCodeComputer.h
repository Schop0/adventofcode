#pragma once

#include "IntCodeProgram.h"

class IntCodeComputer
{
public:
	IntCodeComputer(IntCodeProgram);

	IntCodeProgram run();

private:
	IntCodeProgram program;

	bool execute(int opcode);
	void operation(int func(int, int));
};

