#include "sorting.hpp"
#include <iostream>

/** \brief a simple Heap Structure
 */
struct MaxHeap
{
public:
  /** \brief construct a Heap out of the \a array

      Costs are O(nlogn)
   */
  MaxHeap(int n, int* array)
  {
    m_size = n;
    m_array = array;

    //go through the array from bottom to top
    for(int i = GetParent(n-1); i>=0; --i)
      {
	int j = i;
	//when ever you encounter a switch, you must bring it down until it will no longer violate the heap condition
	while(FixProperty(j, &j));
      }
  }
  /** \brief default dtor
   */
  ~MaxHeap()
  {
    //do nothing because you do not own the int*
  }

  /** \brief swaps the root to the end of the heap and shortens the array

      Costs O(logn)
      Swaps the root with the last element in the active array
      Then Fixes the heap condition by following the new root on its descent to the propper position
   */
  void RemoveRoot()
  {
    //swap root to the end
    int tmp = m_array[--m_size];
    m_array[m_size] = m_array[0];
    m_array[0] = tmp;

    //follow the decent of the new root
    int i = 0;
    while(FixProperty(i, &i))
      {
      }
  }

  /** \brief debug feature, prints the active part of the array
   */
  void Print()
  {
    for(int i = 0; i < m_size; ++i)
      std::cout << m_array[i] << ", ";
    std::cout << "\n";
  }

  /** \brief returns the size of the active part of the array
   */
  int GetSize()
  {
    return m_size;
  }
  
private:
  /** \brief returns the index of the left child
   */
  int GetLeftChild(int index)
  {
    return (index+1)*2-1;
  }

  /** \brief returns the index of the right child
   */
  int GetRightChild(int index)
  {
    return (index+1)*2;
  }

  /** \brief returns the index of the parent
   */
  int GetParent(int index)
  {
    return (index+1)/2-1;
  }

  /** \brief returns a bool if the heap condition was violated

      \a index is the index of the current parrentnode. \a switchedIndex is if set
      the address where the new index of the same node is stored.
      It returns if the condition was violated and therefore if a switch occured
   */
  bool FixProperty(int index, int* switchedIndex = (int*)0)
  {
    //get the indices of the children
    int lc = GetLeftChild(index);
    int rc = GetRightChild(index);

    //if lc >= m_size then there are no children
    if(lc >= m_size)
      lc = rc = index;
    //if only rc>= m_size then there is only one child
    else if(rc >= m_size)
      rc = lc;

    //if the parrentnode is >= than every child the condition is not violated.
    if(m_array[index] >= m_array[lc] && m_array[index] >= m_array[rc])
      return false;
    //else we need to do more work.

    //use the left child as swap index.
    int s = lc;
    //if the right one is > than it, then use the right child instead
    if(m_array[rc] > m_array[lc])
      s = rc;

    //if the switchIndex shall be saved, do so.
    if(switchedIndex)
      *switchedIndex=s;

    //switch parrent and the chosen child.
    int temp = m_array[s];
    m_array[s] = m_array[index];
    m_array[index] = temp;

    //return that the condition was violated
    return true;
  }
  
  
private:
  int m_size;
  int* m_array;
};

void HeapSort(int n, int* array)
{
  //Create a MaxHeap O(nlog(n))
  MaxHeap h(n, array);
  //Continue as long as the size is > 0 O(n)
  while(h.GetSize() > 0)
    {
      //remove the Root O(log(n))
      h.RemoveRoot();
    }

  //==> O(nlog(n))
}
