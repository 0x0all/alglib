/*
 *  graph.cpp
 *  
 *
 *  Created by BRIAN PIN on 9/3/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <list>
#include <iostream>
#include "graph.h"

using namespace std;

void Vertex::set_id(int id)
{
  this->m_id = id;
}

int Vertex::get_id(void) const
{
  return this->m_id;
}

void Vertex::add_connect(Vertex& v, EdgeDirection direction)
{
  if (direction == OUT_GOING)
    m_outs.push_back(v);
  else
    m_ins.push_back(v);
}

/*
 *   FIXME: O(N) type of remove algorithm is not good
 */
void Vertex::remove_connect(const Vertex& v, EdgeDirection direction)
{
  if (direction == OUT_GOING)
    m_outs.remove(v);
  else
    m_ins.remove(v);
}

int Vertex::get_edges(EdgeDirection direction)
{
  int ret;

  if (direction == OUT_GOING)
    ret = m_outs.size();
  else
    ret = m_ins.size();

  return ret;
}

Vertex& Vertex::front(EdgeDirection direction)
{
  if (direction == OUT_GOING)
    return this->m_outs.front();
  else
    return this->m_ins.front();
}

vertices::iterator Vertex::begin(EdgeDirection direction)
{
  v_iter i;
  if (direction == OUT_GOING)
    i = this->m_outs.begin();
  else
    i = this->m_ins.begin();

  return i;
}

bool Vertex::operator==(const Vertex& u)
{
  if (this->m_id == u.m_id)
    return true;
  else
    return false;
}

static void unit_test(void)
{
  Vertex *v = new Vertex;
  v->set_id(9);

  for (int i = 0; i < 3; ++i) {
    Vertex *u = new Vertex;
    u->set_id(i+1);
    v->add_connect(*u, OUT_GOING);
    u->add_connect(*v, IN_COMING);
  }
	
  cout << "Now have " << v->get_edges(OUT_GOING) << " edges"<< endl;
  Vertex::v_iter it = v->begin(OUT_GOING);
  for (int i = 0; i < v->get_edges(OUT_GOING); i++) {
    cout << "IDs: "<< (*it).get_id() <<endl;
    it++;
  }
	
  while (v->get_edges(OUT_GOING) != 0) {
    Vertex& u = v->front(OUT_GOING);
    v->remove_connect(u, OUT_GOING);
    u.remove_connect(*v, IN_COMING);
  }
	
  cout << "then have " << v->get_edges(OUT_GOING) << " edges"<< endl;

  if (v) {
    delete v;
  }
}

int main(int argc, char* argv[])
{
  unit_test();
  return 0;
}
