/*
 * Insertion sort template implementation
 * Shao-Huang Pin 2010-08-07
 *
 */
#ifndef __BP_SORT_INS_H__
#define __BP_SORT_INS_H__
#include<algorithm>
#include<vector>
namespace bp {
  template <class C>
    void insertion_sort(std::vector<C>& array)
    {
      typename std::vector<C>::size_type size = array.size();
      for (int i = 0; i < (size - 1); i++) {
        for (int j = i+1; j < size; j++) {
          if (array[j] <= array[i])
            std::swap(array[i], array[j]);
        }
      }
    }
}

#endif
