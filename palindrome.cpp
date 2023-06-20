#include <iostream>
#include <string>
#define LN printf("\n")

bool palindrome(std::string &words,int len,int front,int back){
  //as long as front < len and words front and back is same, if front == len means true
  return front < len and words[front] == words[back] ? palindrome(words,len,++front,--back) : front == len ? true : false;
}

int main(int argc, char const **argv){

  std::string words = "tomo";
  auto len = words.length();

  std::cout<<std::boolalpha<<palindrome(words, len/2, 0, len-1);

  return 0;
}
