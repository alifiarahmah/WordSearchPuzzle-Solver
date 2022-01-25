/* readfile.cpp */
/* Mengambil matriks dan daftar kata dari file .txt dalam folder test */

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

vector<char> vectorizeLine(string s){
	vector<char> x;
	for(int i = 0; i < s.length(); i+=2){
		x.push_back(s[i]);
	}
	return x;
}

void readFile(string *filename, vector<vector<char>> *matrix, vector<string> *wordlist){
	string line, fullpath;
	bool inwordlist;
	
	ifstream file("../test/" + *filename);

	if (file.is_open()){
		while(getline(file, line)){
			if(line == ""){
				inwordlist = true;
			} else {
				if (inwordlist){
					(*wordlist).push_back(line);
				} else {
					(*matrix).push_back(vectorizeLine(line));
				}
			}
		}
		file.close();
	} else {
		cout << "Unable to open file.";
	}
}