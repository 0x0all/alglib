/*
 *  graph.h
 *  Created by BRIAN PIN on 9/3/09.
 *  Copyright 2009 P. All rights reserved.
 *  Learning points:
 *	1. Simple, simplicity
 *  2. const_iterator and iterator,
 *  3. exception types
 *  4. mutable keyword
 *  5. STL containers insert,erase,push_back,pop, will all use a copy of T
 */
#ifndef __GRAPH_H__
#define __GRAPH_H__

enum VertexState {
	WHITE =		1,
	GRAY =		2,
	BLACK =		3,
	SOURCE =	4,
};

class Vertex {
private:
	unsigned				state;
	std::string				name;
	std::list<Vertex*>		child_list;

public:
	typedef std::list<Vertex*> vertices;

	// ctor/dtor
	Vertex() : name("no name") { }
	explicit Vertex(std::string aname) : name(aname)
	{ std::cout<<name<<" created"<<std::endl; }
	virtual ~Vertex() {std::cout<<name<<" deleted"<<std::endl;}

	// copy and assign
	Vertex(const Vertex& that_v)
	{
		state = that_v.state;
		name = that_v.name;
		std::cout<<name<<" copied"<<std::endl;
		child_list.clear();
		vertices::const_iterator it;
		for (it = that_v.first_child();
			 it != that_v.last_child();
			 it ++) {
			add_child(*it);
		}
	}

	Vertex& operator=(const Vertex& that_v)
	{
		state = that_v.state;
		name = that_v.name;
		std::cout<<name<<" assigned"<<std::endl;
		child_list.clear();
		vertices::const_iterator it;
		for (it = that_v.first_child();
			 it != that_v.last_child();
			 it ++) {
			add_child(*it);
		}

		return *this;
	}

	bool operator==(const Vertex& u) const
	{
		if (this == &u && name == u.name)
			return true;
		else
			return false;
	}

	bool operator!=(const Vertex& u) const
	{
		return !(*this==u);
	}

	// getters and setters
	std::string get_name(void) const
	{
		return this->name;
	}
	void set_state(unsigned s)
	{
		state = s;
	}
	unsigned get_state(void) const
	{
		return state;
	}
	

	//
	//  Add and Remove child vertex operation
	//
	void add_child(Vertex* v)
	{
		child_list.insert(child_list.begin(), 1, v);
	}
	
	void del_child(Vertex* v)
	{
		vertices::iterator it;
		for (it = child_list.begin(); it != child_list.end(); it ++) {
			if (*it == v) {
				child_list.erase(it);
				std::cout << "remove " << (*it)->get_name() << std::endl;
			}
		}
	}

	vertices::const_iterator first_child(void) const
	{
		return child_list.begin();
	}

	vertices::const_iterator last_child(void) const
	{
		return child_list.end();
	}
};

class Graph {
private:
	// disallow the copy constructor and assign operator
	Graph(const Graph& that_g);
	Graph& operator=(const Graph& that_g);
	std::list<Vertex*>			vertex_list;
public:
	typedef std::list<Vertex*>	vertices;
	Graph();
	virtual ~Graph();
	// copy and assign

	// building and traversing
	virtual void add_vertex(Vertex* new_v);
	virtual void del_vertex(Vertex* v);
	virtual void add_edge(Vertex* parent, Vertex* child);
	virtual void bfs_search(Vertex* source);
};

#endif // __GRAPH_H__
