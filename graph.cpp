/*
 *  graph.cpp
 *  
 *
 *  Created by BRIAN PIN on 9/3/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <list>
#include <queue>
#include <iostream>
#include "graph.h"

// added but mem already been allocated
void Graph::add_vertex(Vertex* new_v)
{
	vertex_list.insert(vertex_list.begin(), 1, new_v);
}

// deleted but mem not recycled
void Graph::del_vertex(Vertex* v)
{
	vertices::iterator it;

	// let all other connections know v is going to disconnect
	for (it = vertex_list.begin(); it != vertex_list.end(); it++) {
		if (*it != v) {
			(*it)->del_child(v);
		} else {
			vertex_list.erase(it);
		}
	}
}

void Graph::add_edge(Vertex* parent, Vertex* child)
{
	parent->add_child(child);
}

void Graph::bfs_search(const Vertex& source)
{
}

int unit_test1(void)
{
	typedef std::list<Vertex*> vertices;
	Vertex u("u");
	Vertex v1("v1");
	Vertex v2("v2");
	Vertex v3("v3");
	Vertex v4("v4");

	Vertex u1;

	u.add_child(&v1);
	u.add_child(&v2);
	u.add_child(&v3);
	u.add_child(&v4);

	u1 = u;

	std::cout << "Name: " << u1.get_name() << std::endl;
	vertices::const_iterator it;
	for (it = u1.first_child(); 
		 it != u1.last_child();
		 it ++) {
		std::cout << "Child: " << (*it)->get_name() <<std::endl;
	}
}


int main(int argc, char* argv[])
{
	unit_test1();
	return 0;
}
