#include <iostream>
#include <vector>
using namespace std;

string wave_text(string& str){
	string s{};
	for(size_t i=0; i<str.size(); ++i){
		if(i % 2 == 0)
			s += toupper(str[i]);
		else
			s += tolower(str[i]);
	}
	return s;
}

int main(int argc, char const *argv[]){
	
	cout<<"Masukan kalimat : ";
	string kalimat;
	getline(cin,kalimat);
	cout<<wave_text(kalimat)<<endl;
	
	return 0;
}

	

