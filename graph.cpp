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

Vertex::Vertex()
{
}

void Vertex::set_id(int id)
{
	this->m_id = id;
}

int Vertex::get_id(void) const
{
	return this->m_id;
}

Vertex::~Vertex()
{
	cout<< "Remove a vertex: "<< this->get_id() << endl;
}

void Vertex::add_connect(Vertex* v, EdgeDirection direction)
{
	if (direction == OUT_GOING)
		m_outs.push_back(v);
	else
		m_ins.push_back(v);
}

/*
 *   FIXME: O(N) type of remove algorithm is not good
 */
void Vertex::remove_connect(Vertex* v, EdgeDirection direction)
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

Vertex* Vertex::front(EdgeDirection direction)
{
	Vertex* v;
	switch (direction) {
	case OUT_GOING:
		v = this->m_outs.front();
		break;
	case IN_COMING:
		v = this->m_ins.front();
		break;
	default:
		v = NULL;
		break;
	}
	return v;
}

vertices::iterator Vertex::get_begin(EdgeDirection direction)
{
	vertices::iterator i;
	switch (direction) {
	case OUT_GOING:
		i = this->m_outs.begin();
		break;
	case IN_COMING:
		i = this->m_ins.begin();
		break;
	default:
		i = NULL;
		break;
	}

	return i;
}

static void unit_test(void)
{
	Vertex *v = new Vertex;
	v->set_id(0);
	for (int i = 0; i < 3; ++i) {
		Vertex *u = new Vertex;
		v->add_connect(u, OUT_GOING);
		u->set_id(i+1);
	}
	
	cout << "Now have " << v->get_edges(OUT_GOING) << " edges"<< endl;
	vertices::iterator it = v->get_begin(OUT_GOING);
	for (int i = 0; i < v->get_edges(OUT_GOING); i++) {
		cout << "IDs: "<<(*it)->get_id()<<endl;
		it++;
	}
	
	
	while (v->get_edges(OUT_GOING) != 0) {
		Vertex* u = v->front(OUT_GOING);
		v->remove_connect(u, OUT_GOING);
		delete u;
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
