#include <iostream>
#include <string>
#define LN printf("\n")

void moreVowels(const std::string &data, size_t index, size_t count){
  if(index < data.length()){
    count = ((data[index] == 'a' or data[index] == 'e' or data[index] == 'i' or data[index] == 'u' or data[index] == 'o') ? ++count : count);
    moreVowels(data,++index,count);
    return;
  }

  printf("%s",(count > (data.size() / 2) ? "more vowels" : "less vowels"));
}

int main(int argc, char const **argv){

  std::string data = "fariiiiiikun aziz";
  moreVowels(data, 0, 0);

  return 0;
}
