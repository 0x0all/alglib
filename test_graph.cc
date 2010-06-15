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
  
  void show_obj() const {
    std::cout << " " << _name << " ";
  }
};

static Vertex<People>* build_vertex(class People* p, bool directed=true) {
  if (p) {
    return new Vertex<People>(p, directed);
  }
  return NULL;
}

static void deconstruction(Graph<People> *graph)
{
  typename Graph<People>::iterator i;
  Vertex<People> *vert;
  for (i = graph->begin(); i != graph->end(); i++) {
    vert = *i;
    graph->remove(vert);
    delete vert;
  }

  delete graph;
}


static void parse_input(const char* filename, Graph<People> *graph)
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
    }
error:
    inf.close();
  }
  return mpv;
}

int main(int argc, char* argv[])
{
  if (argc == 2) {
    Graph<People> *graph = new Graph<People>;
    parse_input(argv[1], graph);
    graph->show_graph();
    deconstruction(graph);
  } else {
    std::cout << "Usage: execute-file [input_graph_file.txt]" << std::endl;
  }
  return 0;
}

