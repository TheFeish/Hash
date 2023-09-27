#include <iostream>
#include <sstream>
#include <random>

using namespace std;

unsigned int hash1(int p, int m, string s) {
	unsigned int hash = 0;
	int pow = p;
	for (auto c : s) {
		hash += (c * pow) % m;
		pow = (pow * p) % m;
		
	}
	return hash;
}

string hashHex(unsigned int h1, unsigned int h2) {
	stringstream hash;

	default_random_engine rng1{ h1 };
	default_random_engine rng2{ h2 };

	uniform_int_distribution<> dist{ 0, 15 };

	for (int i = 0; i < 32; i++) {
		hash << hex << dist(rng1);
		hash << hex << dist(rng2);
	}

	return hash.str();
}

int main() {
	string s1 = "1234567890";
	string s2 = "1234567899";

	cout << hashHex(hash1(257, 1e9 + 7, s1), hash1(263, 1e9 + 9, s1)) << endl;
	cout << hashHex(hash1(257, 1e9 + 7, s2), hash1(263, 1e9 + 9, s2)) << endl;
}