#include <iostream>
using namespace std;

/*BUATAN FARIKUN AZIZ
program untuk membuat inisial secara langsung
*/

inline int hitungSpasi(string&);
inline string proses(string&);
inline void tampilHasil(string&);

//global var, be carefull!!!
//ubah sesuai keperluan, misal len = 2, sarjana teknik = SATE bukan ST
int len = 1;

int main(int maxArgs, char* args[]){
	string kata;
	cout<<"Masukan kata/kalimat untuk dibuat inisial baru : ";
	getline(cin, kata);

	hitungSpasi(kata);
	proses(kata);
	tampilHasil(kata);
	return 0;
}


int hitungSpasi(string& kata){
	int totalSpasi = 0;
	for(int i=0; i<kata.size(); i++){
		//jika kata[i] == spasi
		if(kata[i] == ' '){
			totalSpasi++;
		}
	}
	return totalSpasi;
}
string proses(string& kata){
	int spasi = 0;
	string hasil = "";
	for(int i=0; i<kata.size(); i++){
		for(int j=0; j<hitungSpasi(kata); j++){
			if(kata[i] == ' '){
				//i + 1 karena jika tidak maka yang diambil hanya spasi, padahal yang diambil huruf setelahnya
				spasi = i + 1;
				//potong huruf pertama setelah spasi dan ambil hanya 1 saja lalu simpan ke hasil, terus begitu sehingga hasil hanya berisi potongan hufuf pertama saja
				hasil += kata.substr(spasi, len);
				if(spasi > hitungSpasi(kata)){
					break;
				}
			}
		}
	}
	return hasil;
}
void tampilHasil(string& kata){
	string final = "";
	final = kata.substr(0,len) + proses(kata);
	//buat menjadi uppercase
	for(int i=0; i<final.size(); i++){
		final[i] = toupper(final[i]);
		//ganti spasi yang berlebihan
		if(final[i] == ' '){
			final[i] = '\0';
		}
	}
	cout<<"\nInisial baru : "<<final<<endl;
}

