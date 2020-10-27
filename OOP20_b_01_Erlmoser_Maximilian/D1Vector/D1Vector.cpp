#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void coutVector(vector<string> v, string filename) {
	ofstream file(filename);
	int size = v.size();
	if (!file.is_open()) {
		cout << "nah man";
		return;
	}
	file << "Programmname=" << v[0] << "\n";

	file << "Argumente=" << size-1 << "\n";

	for (int i = 1; i < size; i++) {
		file << "Argument_" << i << "=" << v[i] << "\n";
	}

	file.close();
}

int main(int argc, const char* argv[])
{
	if (argc > 4)
		return -1;

	vector<string> arguments(argv, argc + argv);
	coutVector(arguments, "datei.txt");
}