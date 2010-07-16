//
// Brian Pin
// July, 2010
// test_vector_new_del.cc
//
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include "object.h"

using namespace std;

int main(int argc, char* argv[])
{
  string name;
  Object *ob_p;
  vector<Object*> container;
  
  while (cin >> name) {
    if (strcmp(name.c_str(), "quit") == 0)
      break;
    ob_p = new Object(name);
    if (ob_p) {
      container.push_back(ob_p);
    }
  }
  
  vector<Object*>::size_type s = container.size();
  cout << "number of elements: " << s << endl;
  
  
#ifdef CORRECT  
  vector<Object*>::iterator i = container.begin();
  while (i != container.end()) {
    delete *i;
    i = container.erase(i);
  }
#else
  for (vector<Object*>::size_type i = 0; i != container.size(); i++) {
    cout << container[i]->getname() << " will be deleted" << endl;
    delete container[i];
  }
#endif
  
  
  if (container.size() == s) {
    cout << "Watch out, the number of elements has not changed" << endl;
    cout << "number of elements: " << container.size() << endl;
  } else
    cout << "number of elements: " << container.size() << endl;
  
  return 0;
}
