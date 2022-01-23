#include <iostream>
#include <string.h>
#include <vector>
#include "lib/lib.h"

using namespace std;

int main(){
	string filename;
	vector<vector<char>> matrix;
	vector<string> wordlist;

	// isi vector matrix & wordlist
	cout << "Insert filename (from test folder): ";
	cin >> filename;

	readFile(&filename, &matrix, &wordlist);

	wordSearch(&matrix, &wordlist);

	return 0;
}