//============================================================================
// Name        : Graphs.cpp
// Author      : Brian Pin
// Version     :
// Copyright   : BrianP
// Description : Hello World in C, Ansi-style
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <list>
#include <queue>
#include <iostream>
#include "graph.h"

using namespace std;

int unit_test1(void)
{
  struct people {
    char *name;
  } member[] = {
    "Allen",
    "Bryant",
    "Charles",
    "Doug",
    "Edward",
  };

  Vertex<struct people> master = Vertex<struct people>("bpin");

  Vertex<struct people>* v;
  for (int i = 0; i < sizeof member / sizeof member[0]; ++i){
    v = new Vertex<struct people>;
    if (v){
      v->set_name(member[i].name);
      master.add_child(*v);
    }
  }


  return 0;
}


int main(void) {
  unit_test1();
  return EXIT_SUCCESS;
}
