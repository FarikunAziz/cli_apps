#include <iostream>
#include <vector>

int total2D(std::vector<std::vector<int>> & data,int row, int col) noexcept{
  if(row == 0 and col == 0){
    return data[0][0];
  }else{
    return total2D(data,(col == 0 ? row - 1 : row), (col == 0 ? data[row - 1].size() - 1 : col - 1)) + data[row][col];
  }
}

int main (int argc, char *argv[])
{
  std::vector<std::vector<int>> matrix
  {
    {1,1,1},
    {1,1,1},
    {1,1,1},
    {1,1,1,1,1},
    {1,1,1},
    {1},
    {1,1,1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
  };

  int row = matrix.size() - 1;
  int col = matrix[row].size() - 1;

  std::cout<<total2D(matrix,row,col);

  return 0;
}
