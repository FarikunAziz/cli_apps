#include <iostream>
#include <limits>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

class GuessSquareNumber{
private:
  std::vector<int> square_number{};
  int start{};
  int how_many{};
private:
  unsigned int acak_angka(){
    std::mt19937 acak {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::uniform_int_distribution<int> batas_acak {2,4};
    return batas_acak(acak);
  }

  void isi_vector(int many){
    for(int i{1}; i<=many; ++i){
        square_number.emplace_back(start * start * acak_angka());
        ++start;
    }
  } 

    bool input_validation(int &x)const{
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            return false;
        }
         std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        return true;
    }
     
   void logic(){
    for(int i{how_many}; i>0; --i){
      int tebak;
      std::cout<<"> ";
      std::cin>>tebak;
      std::cout<<"> "<<tebak;

      auto temu{std::find(square_number.begin(), square_number.end(),tebak)};

    //need refactoring
    if(temu != square_number.end()){
        square_number.erase(temu);
        if(i > 1){
            std::cout<<"\nNice! "<<(square_number.size())<<" numbers left\n";
        }else{    
            printf( "\nNice! You found all number, good job!\n");
        }
    }else{
      std::cout<<'\n'<<tebak<<" is wrong! Try again next time\n";
      break;
      }
    }
  }
public:
  GuessSquareNumber() = default;
  
  void play(){
    while(true){
        std::cout<<"Start where? ";
        if(input_validation(start))break;
    }
    while(true){
        std::cout<<"\nHow many? ";
        if(input_validation(how_many))break;
    }

    isi_vector(how_many);

    std::cout<<"\nI generated "<<how_many<<" square numbers. Do you know what each number is after multiplying it by "<<acak_angka()<<std::endl;
    std::cout<<"\n\n";
    logic();
  }
};


int main(int argc, char const **argv){

  GuessSquareNumber g;
  g.play();
  return 0;
}





