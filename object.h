#ifndef __OBJECTH__
#define __OBJECTH__

#include<string>
#include<iostream>

class Object {
  int _refcount;
  std::string _name;
  size_t _value;
public:
  Object () { _refcount = 1; _value = 0; }
  explicit Object (const std::string& given_name) {
    _name = given_name;
    _refcount = 1;
    _value = 0;
  }
  virtual ~Object() { _refcount = 0; }

  // copy construct and assign operator
  Object (const Object& aobj) { 
    _refcount = aobj.refcount();
    _name = aobj.getname();
    _value = aobj.value();
  }
  Object& operator=(const Object& aobj) {
    this->_name = aobj.getname();
    this->_refcount = aobj.refcount();
    return *this;
  }
  
  //operator override
  bool operator<(const Object& aobj){
    using namespace std;
    string::const_iterator c1;
    string::const_iterator c2;
    char ch1, ch2;
    string his_name = aobj.getname();
    c1 = _name.begin();
    c2 = his_name.begin();
    while (c1 != _name.end() && c2 != his_name.end()) {
      ch1 = *c1;
      ch2 = *c2;
      if (ch1 != ch2)
        break;
      c1 ++;
      c2 ++;
    }
    if (ch1 < ch2)
      return true;
    else
      return false;
  }
  
  bool operator<=(const Object& aobj){
    using namespace std;
    string::const_iterator c1;
    string::const_iterator c2;
    char ch1, ch2;
    string his_name = aobj.getname();
    c1 = _name.begin();
    c2 = his_name.begin();
    while (c1 != _name.end() && c2 != his_name.end()) {
      ch1 = *c1;
      ch2 = *c2;
      if (ch1 != ch2)
        break;
      c1 ++;
      c2 ++;
    }
    if (ch1 <= ch2)
      return true;
    else
      return false;
  }
  
  bool operator>(const Object& aobj){
    using namespace std;
    string::const_iterator c1;
    string::const_iterator c2;
    char ch1, ch2;
    string his_name = aobj.getname();
    c1 = _name.begin();
    c2 = his_name.begin();
    while (c1 != _name.end() && c2 != his_name.end()) {
      ch1 = *c1;
      ch2 = *c2;
      if (ch1 != ch2)
        break;
      c1 ++;
      c2 ++;
    }
    if (ch1 > ch2)
      return true;
    else
      return false;
  }
  
  bool operator>=(const Object& aobj){
    using namespace std;
    string::const_iterator c1;
    string::const_iterator c2;
    char ch1, ch2;
    string his_name = aobj.getname();
    c1 = _name.begin();
    c2 = his_name.begin();
    while (c1 != _name.end() && c2 != his_name.end()) {
      ch1 = *c1;
      ch2 = *c2;
      if (ch1 != ch2)
        break;
      c1 ++;
      c2 ++;
    }
    if (ch1 >= ch2)
      return true;
    else
      return false;
  }
  
  //attribute getter
  int refcount(void) const { return _refcount; }
  std::string getname(void) const { return _name;}
  size_t value(void) const { return _value;}
  //attribbute setter
  void set_refcount(int count) { _refcount = count; }
  void set_name(std::string name) { _name = name; }
  void set_value(int value) { _value = value; }

  //member function
  void showinfo(void) {
    std::cout << "Name: " << _name << " count: " << _refcount << std::endl;
  }
};

#endif

