#include <iostream>
#include <vector>
#include "day02.h"
#include "IntCodeProgram.h"
#include "IntCodeComputer.h"

#include <iterator>
#include <string>
#include <sstream>

int runProgram(std::vector<int> gravityAssist, int noun, int verb) {
	IntCodeProgram part1(gravityAssist);
	part1.initInputs(noun, verb);
	IntCodeComputer shipComputer(part1);
	return shipComputer.run().getOutput();
}

int bruteForce(std::vector<int>& gravityAssist, int solution) {
	int noun, verb;
	for (noun = 0; noun <= 99; noun++)
		for (verb = 0; verb <= 99; verb++)
			if (runProgram(gravityAssist, noun, verb) == solution)
				return 100 * noun + verb;
}

void parseInput(std::vector<int>& intCode) {
	int currentValue;
	while (std::cin >> currentValue) {
		intCode.push_back(currentValue);
		std::cin.ignore(1, ',');
	}
}

void part1(std::vector<int>& gravityAssist) {
	int solution = runProgram(gravityAssist, 12, 2);
	std::cout << "Part 1: " << solution << '\n';
}

void part2(std::vector<int>& gravityAssist) {
	int solution = bruteForce(gravityAssist, 19690720);
	std::cout << "Part 2: " << solution << '\n';
}

int main(int argc, char* argv[]) {
	std::vector<int> gravityAssist;
	parseInput(gravityAssist);

	part1(gravityAssist);

	part2(gravityAssist);

	return 0;
}
