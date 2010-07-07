#include "object.h"

using namespace std;

int testcase1(void)
{
  int ret = -1;
  Object* obj1 = NULL;
  Object obj0;
  obj1 = new Object("MostLikely");
  obj0 = *obj1;
  
  obj0.set_value(9);
  obj1->set_value(8);
  
  if (obj0 < *obj1) {
    cout << "obj0 < obj1" << endl;
  } else {
    cout << "obj0 >= obj1" << endl;
  }

  
  obj0.showinfo();
  obj1->showinfo();
  delete obj1;
  ret = 0;
  return ret;
}


int main(int argc, char* argv[])
{
  testcase1();
  return 0;
}
