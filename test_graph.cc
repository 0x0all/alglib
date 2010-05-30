//============================================================================
// Name        : graph_unit_test.cpp
// Author      : Brian Pin
// Version     :
// Copyright   : BrianP
// Description : Hello World in C, Ansi-style
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <list>
#include <queue>
#include <sstream>
#include "graph.h"

using namespace std;
using namespace graph_impl;

const char* name_poll [] = {
  "Brian",
  "Winnie",
  "Isabelle",
  "Kayla",
  "Alyssa",
  "Emma",
  "Samantha",
  "Alina",
  "Sofia",
  "Mia",
  "Ashley",
  "Stephanie",
  "Sarah",
  "Emmily",
  "Teagan",
};


class People {
private:
  std::string   _name;
public:
  explicit People(std::string name) {
    _name = name;
  }
  
  ~People() {
    std::cout << "deleting " << _name << std::endl;
  }
  
  void show_info() const {
    std::cout <<  _name << std::endl;
  }
};

static Vertex<People>* build_vertex(class People* p, bool directed=true) {
  if (p) {
    return new Vertex<People>(p, directed);
  }
  return NULL;
}

static void deconstruction(Vertex<People>* mpv)
{
  Vertex<People>* p;
  Vertex<People>::v_iterator i;

  i = mpv->begin();
  while (i != mpv->end()) {
    p = *i;
    i = mpv->erase(i);
    delete p;
  }
    
  if (mpv) {
    delete mpv;
  }
}

Vertex<People>* parse_input(const char* filename)
{
  stringstream ss;
  ifstream inf;
  char line[256];
  int total;
  string name;
  int num_direct_to;
  People* p = NULL;
  Vertex<People>* pv = NULL;
  Vertex<People>* mpv = NULL;
  
  cout << "parsing " << string(filename) << endl;
  inf.open(filename, ios::in);
  if (inf.is_open()) {
    inf.getline(line, 256);
    ss.clear();
    ss.str(line);
    ss >> total;
    cout << "total set: " << total << endl;
    while (total > 0) {
      ss.clear();
      inf.getline(line, 256);
      ss.str(line);
      ss >> name >> num_direct_to;
      p = new People(name);
      if (p) {
        mpv = build_vertex(p);
      }

      while (num_direct_to > 0) {
        ss.clear();
        inf.getline(line, 256);
        ss.str(line);
        ss >> name;
        p = new People(name);
        if (p) {
          pv = build_vertex(p);
          mpv->insert(pv);
        }
        num_direct_to--;
      }
      total=0;
    }
error:
    inf.close();
  }
  return mpv;
}

int main(int argc, char* argv[])
{
  if (argc == 2) {
    Vertex<People> *mpv = NULL;
    mpv = parse_input(argv[1]);
    mpv->show_info();
    Vertex<People>::v_iterator itr;
    for (itr = mpv->begin(); itr != mpv->end(); itr++) {
      (*itr)->show_info();
    }
    
    deconstruction(mpv);
  }
  return 0;
}
