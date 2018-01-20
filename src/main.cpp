#include <iostream>
#include "sorting.hpp"
#include <ctime>
#include <string>

/* some cool shit, not sure if it works under windows, thats why the guard
 */
#ifdef __linux__
#include <sstream>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <cstring>
#endif


/** \brief prints to std::cerr the usage of the program
 */
void printUsage()
{
  std::cerr << "MirkoEbert_JoshuaEndert_JanSprigade [-i/-q/-h] [path to array.txt]\n";

  //The usage of the cool shit I mentioned
#ifdef __linux__
  std::cerr << "Also Possible:\nMirkoEbert_JoshuaEndert_JanSprigade [-a] [path to unsorted arrays] [path where sorted arrays shall be saved]";
#endif
}

//The main shit of the cool shit I mentioned
#ifdef __linux__
/** \brief tests all samples in an directory saves the results to another one and generates a timetable
 */
int GenerateTable(const std::string& UnsortedDir, const std::string& SortedDir);
#endif

int main(int argc, char* argv[])
{
  bool valid = false;
  #ifdef __linux__
  //check what to do
  if(argc == 4)
    {
      std::string a(argv[1]);
      if(a.compare("-a"))
	{
	  printUsage();
	  return 0;
	}
      std::string ud(argv[2]);
      std::string sd(argv[3]);
      return GenerateTable(ud, sd);
    }
  #endif
  if(argc != 3)
    {
      printUsage();
      return 0;
    }
  
  //initialize/declare all needed variables    
  std::string arg1(argv[1]);
  int* array;
  int n = 0;
  clock_t time1;
  clock_t time2;
  //read the file
  ReadFile(argv[2], &array, n);

  //choose which Algorithm shall be used, then use it and measure time before and after
  if(arg1.compare("-i") == 0)
    {
      time1=clock();
      InsertionSort(n, array);
      time2=clock();
    }
  else if(arg1.compare("-q") == 0)
    {
      time1=clock();
      QuickSort(n,array);
      time2=clock();
    }
  else if(arg1.compare("-h") == 0)
    {
      time1=clock();
      HeapSort(n, array);
      time2=clock();
    }
  else
    {
      printUsage();
      delete[] array;
      return 0;
    }

  //print time usage
  std::cout << "Sorting was done within " << ((double)time2-(double)time1)/(double)CLOCKS_PER_SEC << "s\n";

  //write sorted file.
  WriteFile(argv[2], array, n);

  delete[] array;
  return 0;
}


//Now we are down to it
//Creating and printing a nicely formated Table of all the Samples and Algorithms ^^
#ifdef __linux__
struct dirent *drnt;

void PrintTable(double** Times, const std::vector<std::string>& rows, const std::vector<std::string>& cols, const std::vector<bool>& corectness)
{
  int n = 12;

  for(int i = 0; i < cols.size(); ++i)
    if(cols[i].size()>n)
      n = cols[i].size();
  
  for(int i = 0; i < rows.size(); ++i)
    {
      if(rows[i].size()>n)
	n = rows[i].size();
      
      for(int j = 0; j < cols.size(); ++j)
	{
	  std::ostringstream help;
	  help << Times[j][i];
	  std::string h = help.str();
	  if(h.size()>n)
	    n = h.size();
	}
    }

  std::cout << std::string(n, ' ');
  for(int i = 0; i < cols.size(); ++i)
    std::cout << " | " << cols[i] << std::string(n-cols[i].size(), ' ');
  std::cout << "\n";

  std::string correct("Correctness");
  std::cout << correct << std::string(n-correct.size(), ' ');
  for(int i = 0; i < cols.size(); ++i)
    {
      std::string r("UNDEFINED");
      if(i < corectness.size())
	r = (corectness[i])?("True"):("False");
      
      std::cout << " | " << r << std::string(n-r.size(), ' ');
    }
  std::cout << "\n";

  for(int i = 0; i < rows.size(); ++i)
    {
      std::cout << rows[i] << std::string(n-rows[i].size(), ' ');
      for(int j = 0; j < cols.size(); ++j)
	{
	  std::ostringstream help;
	  help << Times[j][i];
	  std::string h = help.str();
	  std::cout << " | " << h << std::string(n-h.size(), ' ');
	}
      std::cout << "\n";
    }
}
int GenerateTable(const std::string& UnsortedDir, const std::string& SortedDir)
{
  DIR *dr;
  dr=opendir(UnsortedDir.c_str());
  std::vector<std::string> files;

  std::vector<std::string> Algorithms;
  Algorithms.push_back("Insertion");
  Algorithms.push_back("Quicksort");
  Algorithms.push_back("Heapsort");
  while((drnt = readdir(dr)) != NULL)
    {
      std::string help(drnt->d_name);
      if(help.compare(".") && help.compare(".."))
	files.push_back(help);
    }
  closedir(dr);

  //sort alphabetical not really needed just for beautys sake
  std::sort(files.begin(), files.end());
  double* TimeTable[3];
  clock_t time1;
  clock_t time2;
  std::vector<bool> correctness(3);
  for(int i=0; i < 3; ++i)
    correctness[i] = true;
  
  for(int i = 0; i < 3; ++i)
    TimeTable[i] = new double[files.size()];

  for(int i=0; i < files.size(); ++i)
    {
      int* IArray;
      int* QArray;
      int* HArray;
      int n = 0;
      
      ReadFile((UnsortedDir+files[i]).c_str(), &IArray, n);
      QArray = new int[n];
      HArray = new int[n];

      memcpy(QArray, IArray, n*sizeof(int));
      memcpy(HArray, IArray, n*sizeof(int));

      time1 = clock();
      InsertionSort(n, IArray);
      time2 = clock();

      TimeTable[0][i] = ((double)time2-(double)time1)/(double)CLOCKS_PER_SEC;

      time1 = clock();
      QuickSort(n, QArray);
      time2 = clock();

      TimeTable[1][i] = ((double)time2-(double)time1)/(double)CLOCKS_PER_SEC;

      time1 = clock();
      HeapSort(n, HArray);
      time2 = clock();

      TimeTable[2][i] = ((double)time2-(double)time1)/(double)CLOCKS_PER_SEC;

      for(int i= 0; i < n-1; ++i)
	{
	  correctness[0] = correctness[0] && (IArray[i] <= IArray[i+1]);
	  correctness[1] = correctness[1] && (QArray[i] <= QArray[i+1]);
	  correctness[2] = correctness[2] && (HArray[i] <= HArray[i+1]);
	}
      
      WriteFile(((SortedDir+files[i]).insert((SortedDir+files[i]).size()-4,"I")).c_str(), IArray, n);
      WriteFile(((SortedDir+files[i]).insert((SortedDir+files[i]).size()-4,"Q")).c_str(), QArray, n);
      WriteFile(((SortedDir+files[i]).insert((SortedDir+files[i]).size()-4,"H")).c_str(), HArray, n);

      delete[] IArray, QArray, HArray;
    }

  PrintTable(TimeTable, files, Algorithms, correctness);
  
  for(int i = 0; i < 3; ++i)
    delete[] TimeTable[i];
  
  return 0;
}
#endif
