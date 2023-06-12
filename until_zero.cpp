#include <iostream>
#include <vector>
#include <algorithm>
#define LN printf("\n")

bool validate(std::istream &is){
  bool status = true;
  if(is.fail()){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    if(std::cin.gcount() > 1) status = false;
  }

  return status;
}

void untilZero(int repeat){
  //fill vector with random value
  std::vector<int> basket;
  basket.reserve(repeat);
  int basket_size= repeat;

  for(int i{0}; i < basket_size; ++i){
    int fill = (rand() % basket_size) + 1;
    basket.emplace_back(fill);
  }
  //fill vector with random value

  //show and select
  int select{};
  bool welcome {false};
  bool value_not_found {false};
  std::cout<<"select these values : ";

  //ask to input
  while(basket_size != 0){
    printf(welcome == 1 ? "you have %d elements left in your basket\n\n" : "",basket_size);

    printf(value_not_found == 1 ? "\nvalue %d not found\n\n" : "",select);

    //show the contents
    for(const auto &e : basket){
      std::cout<<'['<<e<<']';
    }

    //input must be int, need to improve, using isdigit
    while(!validate(std::cin>>select)){
      printf("\ninput invalid\n");
    }

    //remove from vector
    auto find = std::find(basket.begin(), basket.end(), select);
    std::vector<int>::iterator index = std::find(basket.begin(), basket.end(), select);

    if(find != basket.end()){
      basket.erase(index);
      printf("\nValue %d successfully delete!\n\n",select);
      basket_size--;
    }else{
      value_not_found = true;
    }

    welcome = true;
  }

  printf("\nbasket is now empty");
}

int main(int argc, char const **argv){
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  untilZero(5);

  LN;
  return 0;
}
