#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

// ke atas
void strMatch1(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int it, int j, int *lettercount, string *l,
							bool *found){
	int i = it;
	while((!(*found)) && (m->at(i).at(j) == l->at(*lettercount)) && (i >= 0)){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		i--;
		if (i < 0) break;
	}
}

// ke kanan atas
void strMatch2(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int it, int jt, int *lettercount, string *l,
							bool *found){
	int i = it, j = jt;
	while((!(*found)) && (m->at(i).at(j) == l->at(*lettercount)) && (i >= 0) && (j < m->at(i).size())){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		i--;
		j++;
		if (i < 0) break;
		if (j == m->at(i).size()) break;
	}
}

// ke kanan
void strMatch3(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int i, int jt, int *lettercount, string *l,
							bool *found){
	int j = jt;
	while((!(*found)) && (m->at(i).at(j) == l->at(*lettercount)) && (j < m->at(i).size())){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		j++;
		if (j == m->at(i).size()) break;
	}
}

// ke kanan bawah
void strMatch4(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int it, int jt, int *lettercount, string *l,
							bool *found){
	int i = it, j = jt;
	while((!(*found)) && (m->at(i).at(j) == l->at(*lettercount)) && (i < m->size()) && (j < m->at(i).size())){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		i++;
		j++;
		if (i == m->size()) break;
		if (j == m->at(i).size()) break;
	}
}

// ke bawah
void strMatch5(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int it, int j, int *lettercount, string *l,
							bool *found){
	int i = it;
	while((!(*found)) && (m->at(i).at(j) == l->at(*lettercount)) && (i < m->size())){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		i++;
		if (i == m->size()) break;
	}
}

// ke kiri bawah
void strMatch6(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int it, int jt, int *lettercount, string *l,
							bool *found){
	int i = it, j = jt;
	while(!(*found) && (i >= 0) && (j >= 0)){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		i++;
		j--;
		if (i == m->size()) break;
		if (j < 0) break;
	}
}

// ke kiri
void strMatch7(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int i, int jt, int *lettercount, string *l,
							bool *found){
	int j = jt;
	while(!(*found) && (j >= 0)){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		j--;
		if (j < 0) break;
	}
}

// ke kiri atas
void strMatch8(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int it, int jt, int *lettercount, string *l,
							bool *found){
	int i = it, j = jt;
	while(!(*found) && (i >= 0) && (j >= 0)){
		(*lettercount)++;
		coordlist->push_back({i, j});
		if(*lettercount == l->length()){
			*found = true;
		}
		i--;
		j--;
		if (i < 0) break;
		if (j < 0) break;
	}
}

/* strMatch : Search kelanjutan sesuai direction, berhenti kalo k == l.length ato i/j mentok */
void strMatch(vector<vector<char>> *m, 
							vector<vector<int>> *coordlist, 
							int i, int j, int *lettercount, string *l, short int direction,
							bool *found){

	// buat ngebungkus, fungsi cuma dijalanin kalo belom ketemu aja
	if(!(*found)){
		switch(direction){
			case 1:
				strMatch1(m, coordlist, i, j, lettercount, l, found);
				break;
			case 2:
				strMatch2(m, coordlist, i, j, lettercount, l, found);
				break;
			case 3:
				strMatch3(m, coordlist, i, j, lettercount, l, found);
				break;
			case 4:
				strMatch4(m, coordlist, i, j, lettercount, l, found);
				break;
			case 5:
				strMatch5(m, coordlist, i, j, lettercount, l, found);
				break;
			case 6:
				strMatch6(m, coordlist, i, j, lettercount, l, found);
				break;
			case 7:
				strMatch7(m, coordlist, i, j, lettercount, l, found);
				break;
			case 8:
				strMatch8(m, coordlist, i, j, lettercount, l, found);
				break;
		}

		if(!(*found)){ // kalo dari 8 arah belom ketemu full kata
			coordlist->clear();
			direction = -1;
		}
	}

}

/* strSearch : Search per kata, kalo found diwarnain */
void strSearch(vector<vector<char>> *m, vector<vector<short int>> *mcolor, string *l, int idx){
	int i = 0, j, lettercount = 0, comparison = 0;
	short int direction = -1;
	bool found = false;
	vector<vector<int>> coordlist; // list koordinat masing2 huruf dalam 1 kata yg lagi dicari

	auto start = chrono::high_resolution_clock::now();

	// cari huruf pertama (sequential search)
	while(!found && (i < m->size())){
		j = 0;
		while(!found && (j < m->at(i).size())){
			if (m->at(i).at(j) == l->at(0)){ // kalo ketemu huruf pertama

				lettercount=1;
				coordlist.push_back({i, j});
				if(lettercount == l->length()){
					found = true; // kalo cuma 1 huruf
				} else {
					// cari huruf kedua di 8 arah
					if (i > 0){
						if (m->at(i-1).at(j) == l->at(1)){
							direction = 1; // atas
							strMatch(m, &coordlist, i-1, j, &lettercount, l, direction, &found);
						}
						if (j < m->at(i).size()-1){
							if (m->at(i-1).at(j+1) == l->at(1)){
								direction = 2; // kanan atas
								strMatch(m, &coordlist, i-1, j+1, &lettercount, l, direction, &found);
							}
						}
						if (j > 0){
							if (m->at(i-1).at(j-1) == l->at(1)){
								direction = 8; // kiri atas
								strMatch(m, &coordlist, i-1, j-1, &lettercount, l, direction, &found);
							}
						}
					}
					if (i < m->size()-1){
						if (m->at(i+1).at(j) == l->at(1)){
							direction = 5; // bawah
							strMatch(m, &coordlist, i+1, j, &lettercount, l, direction, &found);
						}
						if (j < m->at(i).size()-1){
							if (m->at(i+1).at(j+1) == l->at(1)){
								direction = 4; // kanan bawah
								strMatch(m, &coordlist, i+1, j+1, &lettercount, l, direction, &found);
							}
						}
						if (j > 0){
							if (m->at(i+1).at(j-1) == l->at(1)){
								direction = 6; // kiri bawah
								strMatch(m, &coordlist, i+1, j-1, &lettercount, l, direction, &found);
							}
						}
					} 
					if (j > 0){
						if (m->at(i).at(j-1) == l->at(1)){
							direction = 7; // kiri
							strMatch(m, &coordlist, i, j-1, &lettercount, l, direction, &found);
						}
					} 
					if (j < m->at(i).size()-1){
						if (m->at(i).at(j+1) == l->at(1)){
							direction = 3; // kanan
							strMatch(m, &coordlist, i, j+1, &lettercount, l, direction, &found);
						}
					}
				}

			}
			if (!found){
				comparison++;
				coordlist.clear();
			}
			j++;
		}
		i++;
	}

	auto end = chrono::high_resolution_clock::now();
	long long diff = chrono::duration_cast<chrono::microseconds>(end - start).count();

	// pake coordlist buat isi mcolor
	// kode warna ulang2 aja
	if (found) {
		int color = 31 + (idx % 6);

		for(i = 0; i < coordlist.size(); i++){
			mcolor->at(coordlist[i][0]).at(coordlist[i][1]) = color;
		}
		cout << *l << " found\n";
		cout << "Total time: " << diff << " microseconds\n";
		cout << "Total comparison: " << comparison << endl;
	}
}

void print_color(char s, short int x){
	cout << "\033[" << x << "m" << s << "\033[0m";
}

// fungsi utama yang dipanggil dari main
// search masing2 kata dalam l, print ulang pake mcolor, tulis keseluruhan waktu
void wordSearch(vector<vector<char>> *m, vector<string> *l){
	int i, j;
	vector<vector<short int>> mcolor;
	vector<short int> x;

	// inisialisasi mcolor
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
		cout << "\nSearching for " << l->at(i) << "..." << endl;
		strSearch(m, &mcolor, &(l->at(i)), i); // search tiap string di matriks
	}

	cout << "\nAll search completed.\n";
	auto endall = chrono::high_resolution_clock::now();
	long long duration = chrono::duration_cast<chrono::microseconds>(endall - startall).count();
	cout << "Total time: " << duration << " microseconds\n\n";
	// print semua warna
	for(i = 0; i < m->size(); i++){
		for(j = 0; j < m->at(i).size(); j++){
			print_color(m->at(i).at(j), mcolor.at(i).at(j));
			if(j != m->at(i).size()-1){
				cout << " ";
			}
		}
		cout << "\n";
	}
}