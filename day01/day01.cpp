#include <iostream>

using namespace std;

unsigned int fuelPart1(unsigned int mass) {
    if (mass < 9)
        return 0;

    return mass / 3 - 2;
}

unsigned int fuelPart2(unsigned int mass) {
    unsigned int fuelMass = fuelPart1(mass);

    if (fuelMass > 0)
        fuelMass += fuelPart2(fuelMass);

    return fuelMass;
}

int main(int argc, char* argv[]) {
    int totalFuelPart1 = 0;
    int totalFuelPart2 = 0;
    int moduleMass;

    while (cin >> moduleMass) {
        totalFuelPart1 += fuelPart1(moduleMass);
        totalFuelPart2 += fuelPart2(moduleMass);
    }

    cout << "Part 1: " << totalFuelPart1 << '\n'
        << "Part 2: " << totalFuelPart2 << '\n';
}
