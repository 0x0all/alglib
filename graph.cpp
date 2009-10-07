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

#if 0
// added but mem already been allocated
void Graph::add_vertex(Vertex& new_v)
{
	graph_vertices.push_back(new_v);
}

// deleted but mem not recycled
void Graph::del_vertex(const Vertex* v)
{
	vertices::iterator it;
	
	// let all other connections know v is going to disconnect
	for (it = graph_vertices.begin(); it != graph_vertices.end(); it++) {
		if (*it != v) {
			it->del_connection(v);
		}
	}

	// let v disappear on graph_vertices list
	for (it = graph_vertices.begin(); it != graph_vertices.end(); it++) {
		if (*it == v) {
			graph_vertices.erase(it);
			break;
		}
	}
}

void Graph::build_connection(Vertex& parent, const Vertex& child)
{
	parent.add_connection(child);
}

void Graph::bfs_search(const Vertex& source)
{
	std::list<Vertex> bfs_q;
	vertices::iterator it;

	// initialization
	for (it = graph_vertices.begin(); it != graph_vertices.end(); it++) {
		if (source != *it) {
			it->set_dist((unsigned)(-1));
			it->set_flag(WHITE);
		}
	}
	
	bfs_q.push_back(source);
	while (true != bfs_q.empty()) {
		bfs_q.erase(bfs_q.begin());
	}
}
#endif
int unit_test1(void)
{
	typedef std::list<Vertex*> vertices;
	Vertex u("u");
	Vertex v1("v1");
	Vertex v2("v2");
	Vertex v3("v3");
	Vertex v4("v4");

	Vertex u1;

	u.add_connection(&v1);
	u.add_connection(&v2);
	u.add_connection(&v3);
	u.add_connection(&v4);

	u1 = u;
	std::cout << "Name: " << u1.get_name() << std::endl;
	vertices::const_iterator it;
	for (it = u1.connection_begin(); 
		 it != u1.connection_end();
		 it ++) {
		std::cout << "Child: " << (*it)->get_name() <<std::endl;
	}
}


int main(int argc, char* argv[])
{
	unit_test1();
	return 0;
}
