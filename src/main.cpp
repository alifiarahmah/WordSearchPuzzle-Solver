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

	// print semua warna
	cout << "\n";
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m.at(i).size(); j++){
			cout << m.at(i).at(j);
			if(j != m.at(i).size()-1){
				cout << " ";
			}
		}
		cout << "\n";
	}

	wordSearch(&m, &wl);

	return 0;
}