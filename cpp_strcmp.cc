#include<string>
#include<iostream>

using namespace std;

int main()
{
  string funnytitle("How amzaing it is!");
  string sthlessfunny("Wow what is that??");
  string ateststr("");

  string::iterator c1,c2,c3,c4;
  char ch1, ch2;
  c1 = funnytitle.begin();
  c2 = sthlessfunny.begin();
  c3 = ateststr.begin();
  c4 = ateststr.end();

  while(c1 != funnytitle.end() && c2 != sthlessfunny.end()) {
    ch1 = *c1;
    ch2 = *c2;
    if (ch1 == ch2) {
      c1 ++;
      c2 ++;
    } else
      break;
  }
  if (ch1 > ch2)
    cout << funnytitle << ">" << sthlessfunny << endl;
  else if (ch1 == ch2)
    cout << funnytitle << "=" << sthlessfunny << endl;
  else
    cout << funnytitle << "<" << sthlessfunny << endl;

  if (c3 == c4)
    cout << "4 empty string, begin() is end()" << endl;

  return 0;
}
