#include <iostream>
#include <vector>
#define LN printf("\n")

int findMaximum(const std::vector<int> &data, int temp, int length){
  if(length == -1)
    return temp;
  return findMaximum(data, (data[length] > temp ? temp = data[length] : temp), length - 1);
}

int findMinimum(const std::vector<int> &data, int temp, int length){
  if(length == -1)
    return temp;
  return findMinimum(data, (data[length] < temp ? temp = data[length] : temp), length - 1);
}

int main(int argc, char const **argv){

  std::vector<int> data {2,8,3,4,-1};
  auto len = data.size() - 1;

  printf("maximum : %d\n",findMaximum(data,0,len));
  printf("\nminimum : %d\n",findMinimum(data,data[len],len));

  LN;
  return 0;
}
