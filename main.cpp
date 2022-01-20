#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

// PROGRAM UTAMA

int main(){
	string filename, line;
	cout << "Insert filename: ";
	cin >> filename;
	ifstream file(filename);
	if (file.is_open()){
		while(getline(file, line)){
			cout << line << "\n";
		}
		file.close();
	} else {
		cout << "Unable to open file.";
	}
	return 0;
}