/* main.cpp */
/* Program utama word-search puzzle solver */

#include <iostream>
#include <string.h>
#include <vector>
#include "lib/readfile.h"
#include "lib/wordsearch.h"

using namespace std;

int main(){
	string filename;
	vector<vector<char>> m;
	vector<string> wl;

	cout << "Insert filename (from test folder): ";
	cin >> filename;
	readFile(&filename, &m, &wl);

	wordSearch(&m, &wl);

	return 0;
}