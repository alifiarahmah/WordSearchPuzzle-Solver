#include <iostream>
#include <vector>
using namespace std;

// menguji pembacaan vektor matriks m dan vektor list word l
void vectorTest(vector<vector<char>> *m, vector<string> *l){
	int i, j;
	for(i = 0; i < m->size(); i++){
		for(j = 0; j < m->at(i).size(); j++){
			cout << m->at(i).at(j) << " ";
		}
		cout << endl;
	}
	for(i = 0; i < l->size(); i++){
		cout << l->at(i) << endl;
	}
}