#include <iostream>
#include <vector>

void transpose(std::vector<std::vector<int>> &matrix){
  int temp{};

  for (int i{0}; i < matrix.size(); i++) {
    for (int j{0}; j < i; j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

int main (int argc, char *argv[])
{
  std::vector<std::vector<int>> matrix
  {
    {1,2,3},
    {4,5,6},
    {7,8,9},
  };

  printf("Before transpose");
  std::cout<<std::endl;
  [=](){
    for (int i{0}; i < matrix.size(); ++i) {
      for (int j{0}; j < matrix[0].size(); ++j) {
        std::cout<<matrix[i][j]<<' ';
      }
      std::cout<<std::endl;
    }
  }();

  std::cout<<std::endl;
  printf("After transpose");
  std::cout<<std::endl;
  transpose(matrix);
  [=](){
    for (int i{0}; i < matrix.size(); ++i) {
      for (int j{0}; j < matrix[0].size(); ++j) {
        std::cout<<matrix[i][j]<<' ';
      } 
      std::cout<<std::endl;
    }
  }();

  return 0;
}
