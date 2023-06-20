#include <iostream>
#include <string>
#define LN printf("\n")

void reverse(std::string &words, int len, int front, int back){
  if(front < len){
    std::swap(words[front],words[back]);
    reverse(words,len,++front,--back);
  }
  return;
}

int main(int argc, char const **argv){
  std::string words = "farikun aziz";
  auto len = words.length();

  reverse(words,len/2,0,len-1);

  std::cout<<words;

  return 0;
}
