#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

/* strMatch : Search kelanjutan sesuai direction, berhenti kalo k == l.length ato i/j mentok */
void strMatch(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int i, int j, int k, string *l, short int direction,
							bool *found){

	if(!found){
		

		if(!found){
			coordlist->clear();
			direction = -1;
		}
	}

}

/* strSearch : Search per kata, kalo found diwarnain */
void strSearch(vector<vector<char>> *m, vector<vector<short int>> *mcolor, string *l){
	int i = 0, j, lettercount = 0, comparison = 0;
	short int direction = -1;
	bool found = false;
	vector<vector<int>> coordlist;
	auto startsearch = chrono::high_resolution_clock::now();

	// cari huruf pertama (sequential search) habis itu rekursi
	while(!found && (i < m->size())){
		j = 0;
		while(!found && (j < m->at(i).size())){
			if (m->at(i).at(j) == l->at(0)){ // kalo ketemu huruf pertama

				lettercount++;
				coordlist.push_back({i, j});
				if(lettercount == l->length()){
					found = true; // kalo cuma 1
				} else {
					// cari huruf kedua ke sekitaran huruf pertama, tentuin direction
					if (i > 0){
						if (m->at(i-1).at(j) == l->at(1)){
							direction = 1; // atas
							strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
						}
						if (j < m->at(i).size()-1){
							if (m->at(i-1).at(j+1) == l->at(1)){
								direction = 2; // kanan atas
								strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
							}
						}
						if (j > 0){
							if (m->at(i-1).at(j-1) == l->at(1)){
								direction = 8; // kiri atas
								strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
							}
						}
					}
					if (i < m->size()-1){
						if (m->at(i+1).at(j) == l->at(1)){
							direction = 5; // bawah
							strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
						}
						if (j < m->at(i).size()-1){
							if (m->at(i+1).at(j+1) == l->at(1)){
								direction = 4; // kanan bawah
								strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
							}
						}
						if (j > 0){
							if (m->at(i+1).at(j-1) == l->at(1)){
								direction = 6; // kiri bawah
								strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
							}
						}
					} 
					if (j > 0){
						if (m->at(i).at(j-1) == l->at(1)){
							direction = 7; // kiri
							strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
						}
					} 
					if (j < m->at(i).size()-1){
						if (m->at(i).at(j+1) == l->at(1)){
							direction = 3; // kanan
							strMatch(m, &coordlist, i, j, lettercount, l, direction, &found);
						}
					}
				}

			}
			if (!found) comparison++;
			j++;
		}
		i++;
	}

	// pake coordlist buat isi mcolor
	// kode warna ulang2 aja
	if (found) {

	}

	auto endsearch = chrono::high_resolution_clock::now();
	auto diff = endsearch - startsearch;
	long long duration = chrono::duration_cast<chrono::nanoseconds>(diff).count();
	if(found){
		cout << *l << " found\n";
		cout << "Search time: " << duration << "ns\n";
		cout << "Total comparison: " << comparison << endl;
	}
}

// fungsi utama yang dipanggil dari main
// search masing2 kata dalam l, print ulang pake mcolor, tulis keseluruhan waktu
void wordSearch(vector<vector<char>> *m, vector<string> *l){
	int i, j;

	// inisialisasi mcolor
	vector<vector<short int>> mcolor;
	vector<short int> x;
	for(i = 0; i < m->size(); i++){
		for(j = 0; j < m->at(i).size(); j++){
			x.push_back(0);
		}
		mcolor.push_back(x);
		x.clear();
	}
	x.erase(x.begin(), x.end());

	auto startall = chrono::high_resolution_clock::now();
	
	// cari semua kata + taroh kode2 warna di mcolor
	for(i = 0; i < l->size(); i++){
		cout << "\nSearching for " << l->at(i) << "...\n";
		strSearch(m, &mcolor, &(l->at(i))); // search tiap string di matriks
	}

	// tulis keseluruhan mcolor + warna

	cout << "\nAll search completed.\n";
	auto endall = chrono::high_resolution_clock::now();
	auto diff = endall - startall;
	long long duration = chrono::duration_cast<chrono::microseconds>(diff).count();
	cout << "Total time: " << duration/1000 << "ms\n";

	// print semua warna
}