#include<iostream>
#include<vector>
#include "sort_ins.h"

using namespace std;
using namespace bp;

int main()
{
  vector<int> test_vector;

  test_vector.push_back(50);
  test_vector.push_back(45);
  test_vector.push_back(65);
  test_vector.push_back(32);
  test_vector.push_back(66);

  for (int i = 0; i < test_vector.size(); i++) {
    cout << test_vector[i] << " ";
  }
  cout << endl;

  insertion_sort(test_vector);

   for (int i = 0; i < test_vector.size(); i++) {
    cout << test_vector[i] << " ";
  }
  cout << endl;

  return 0;
}
