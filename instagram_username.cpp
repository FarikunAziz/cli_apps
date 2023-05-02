#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]){
  
  std::string kata {};
  std::cout<<"Enter instagram username : ";
  std::getline(std::cin,kata);

  //STL, kenapa menggunakan variabel bantu (c), jika tidak bagaimana kita akan mengAksesnya/mengecek secara individual (karakter), kalau looping biasa bisa, tapi jika menggunakan STL looping tidak bisa, variabel bantu ini bertindak sebagai pengganti dari seluruh isi kata
  std::for_each(kata.begin(), kata.end(), [](char &c){
    if(isspace(c)) c = '_';
  });

  //versi umum
  // for(int i{0}; i<kata.length(); ++i){
  // 	if(isspace(kata[i]))
  // 		kata[i] = '_';
  // }

  std::cout<<kata<<std::endl;
  return 0;
}





