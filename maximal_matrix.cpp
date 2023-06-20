#include <iostream>
#include <vector>

constexpr int limits = 5;

int maximalOne(int data[limits], int temp, int length){
  //-1 to compare with [0][0] data
  if(length == -1)
    return temp;
  return maximalOne(data, (data[length] > temp ? temp = data[length] : temp), length - 1);
}

int maximalTwo(std::vector<int> &data, int temp, int length){
  if(length == -1)
    return temp;
  return maximalTwo(data, (data[length] > temp ? temp = data[length] : temp), length - 1);
}

int main (int argc, char *argv[])
{
  return 0;
}
