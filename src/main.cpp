#include <iostream>
#include "sorting.hpp"
#include <ctime>
#include <string>

void printUsage()
{
  std::cerr << "MirkoEbert_JoshuaEndert_JanSprigade [-i/-q/-h] [path to array.txt]\n";
}

int main(int argc, char* argv[])
{
  bool valid = false;
  if(argc != 3)
    {
      printUsage();
      return 0;
    }

  std::string arg1(argv[1]);
  int* array;
  int n;
  ReadFile(argv[2], &array, n);
  
  if(arg1.compare("-i") == 0)
    {
      std::cout << "Insertion\n";
      InsertionSort(n, array); 
    }
  else if(arg1.compare("-q") == 0)
    {
      std::cout << "Quick\n";
      QuickSort(n,array);
    }
  else if(arg1.compare("-h") == 0)
    {
      std::cout << "Heap\n";
      HeapSort(n, array);
    }
  else
    {
      printUsage();
    }
  WriteFile(argv[2], array, n);
  
  return 0;
}
