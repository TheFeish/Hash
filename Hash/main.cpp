#include <iostream>
#include <fstream>
#include <sstream>
#include "hashFunc.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 3) { cout << "Too few arguments"; }
	else if (argc > 3) { cout << "Too many arguments"; }
	else {
		bool readFile = stoi(argv[1]);
		stringstream ss;
		if (readFile) {
			ifstream input(argv[2]);
			if (input.is_open()) {
				ss << input.rdbuf();
				cout << myHash(ss.str());
			}
			else {
				cout << "File not found";
			}
			input.close();
		}
		else {
			cout << myHash(argv[2]);
		}
	}
	return 0;
}