#include <iostream>
#include <vector>
#define LN printf("\n")

void evenFirstIter(std::vector<int> &data, int len){
  int front{0};
  int back {len - 1};
  int start {0};
  len = ((len & 1) == 1 ? len / 2 + 1 : len / 2);

  while(start < len){
    //[must be odd]->[n]->[must be even]
    if((data[front] & 1) == 1 and (data[back] & 1) == 0){
      std::swap(data[front],data[back]);
      --back;++front;
    }else{
      if((data[back] & 1) == 1){
        --back;
      }else{
        ++front;
      }
    }

    ++start;
  }
}

void  evenFirstRec(std::vector<int> &data,int start, int front, int back, int len){
  if(start == len){
    return;
  }else{
    if(((data[front] & 1) == 1) and (data[back] & 1) == 0){
      std::swap(data[front],data[back]);
      ++front;--back;
    }
    evenFirstRec(data,++start,((data[front] & 1) == 0 ? ++front : front),((data[back] & 1) == 1 ? --back : back),len);
  }
}

int main(int argc, char const **argv){

  std::vector<int> data {4,2,3,1,6};
  // std::vector<int> data {1,5,3,2,4,6};
  // std::vector<int> data {1,2,3};
  auto len = data.size();

  // evenFirstIter(data,len);
  evenFirstRec(data,0,0,len-1,((len & 1) == 1 ? len / 2 + 1 : len / 2));

  [&]{
    for(int i{0}; i < len; ++i){
      std::cout<<data[i]<< ' ';
    }
  }();


  return 0;
}
