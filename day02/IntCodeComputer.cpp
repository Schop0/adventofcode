#include <iostream>
#include "IntCodeComputer.h"

IntCodeComputer::IntCodeComputer(IntCodeProgram p) : program(p) {}

#define OPCODE_ADD 1
#define OPCODE_MUL 2 
#define OPCODE_END 99

IntCodeProgram IntCodeComputer::run() {
	try {
		while (execute(program.nextInt()));
	}
	catch (int e) {
		std::cerr << "Illegal instruction: " << e;
	}

	return program;
}

int add(int a, int b)
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

bool IntCodeComputer::execute(int opcode) {
	switch (opcode)
	{
	case OPCODE_ADD:
		operation(add);
		break;
	case OPCODE_MUL:
		operation(multiply);
		break;
	case OPCODE_END:
		return false;
	default:
		throw opcode;
	}

	return true;
}

void IntCodeComputer::operation(int func(int,int)) {
	int a_pos = program.nextInt();
	int b_pos = program.nextInt();
	int target = program.nextInt();

	int a = program.get(a_pos);
	int b = program.get(b_pos);

	int result = func(a, b);

	program.set(target, result);
}
