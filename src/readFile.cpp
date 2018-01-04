#include "sorting.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ReadFile(const char* filename, int** array, int& n)
{
  //the raw read data
  std::vector<int> res;
  //the stream of data
  std::ifstream file(filename, std::ifstream::in);
  //until the end of the stream is reached continue reading
  while(!file.eof())
    {
      //the read value read from stream
      int v = 0;
      file >> v;
      //add to the vector
      res.push_back(v);
    }
  //allways close streams if not needed
  file.close();

  //the last line contains no value therefore it is only our default value. Ignore it
  n = res.size()-1;

  //create the array at the specified position
  *array = new int[n];
  //fill it with the content from our input stream
  for(int i = 0; i<n;++i)
    (*array)[i] = res[i];
}

void WriteFile(const char* filename, const int* array, int n)
{
  //the name of the resulting file
  std::string name(filename);
  //the ending that is to be inserted before the ending eg .txt
  std::string sorted("_sortiert");
  //assume that the ending is 4 characters long, insert before it
  name.insert(name.size()-4, sorted);

  //create the file with the name
  std::ofstream file(name.c_str(), std::ofstream::out);
  //write all values to the stream seperate them via new lines
  for(int i = 0; i<n; ++i)
    file << array[i] << "\n";
  //close the stream
  file.close();
}
