#include <iostream>
#include <string.h>
#include <vector>
#include "lib/lib.h"

using namespace std;

int main(){
	string filename;
	vector<vector<char>> m;
	vector<string> wl;

	// isi vector matrix & wordlist
	cout << "Insert filename (from test folder): ";
	cin >> filename;

	readFile(&filename, &m, &wl);

	wordSearch(&m, &wl);

	return 0;
}