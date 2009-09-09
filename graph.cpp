/*
 *  graph.cpp
 *  
 *
 *  Created by TSU-LING LIN on 9/3/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <list>
#include "graph.h"
#include <iostream>

using namespace std;

Vertex::Vertex()
{
}

void Vertex::set_id(int id)
{
	this->identifier_ = id;
}

int Vertex::get_id(void) const
{
	return this->identifier_;
}

Vertex::~Vertex()
{
}

void Vertex::add_connect(Vertex& v, VEDirection direction)
{
	if (direction == OUT_GOING)
		outs_.push_back(&v);
	else
		ins_.push_back(&v);
}

/*
 *   FIXME: O(N) type of remove algorithm is not good
 */
void Vertex::remove_connect(Vertex& v, VEDirection direction)
{
	if (direction == OUT_GOING)
		outs_.remove(&v);
	else
		ins_.remove(&v);
}

unsigned Vertex::get_edges(VEDirection direction)
{
	unsigned ret;
	if (direction == OUT_GOING)
		ret = outs_.size();
	else
		ret = ins_.size();
	
	return ret;
}

Vertex& Vertex::pop_first(VEDirection direction)
{
	
}

static void unit_test(void)
{
	Vertex *v = new Vertex;
	for (int i = 0; i < 3; ++i) {
		Vertex *u = new Vertex;
		v->add_connect(*v, OUT_GOING);
	}
	
	cout << "Now have " << v->get_edges(OUT_GOING) << " edges"<< endl;
	int num_outs = v->get_edges(OUT_GOING);
	
	for (int i = 0; i < num_outs; i++) {
		
	}
	
	delete v;
}

int main(int argc, char* argv[])
{
	unit_test();
	return 0;
}
