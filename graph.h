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

class VertexAssignException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Vertex operator= assign to an existing Vertex";
	}
};

enum VertexFlags {
	WHITE = 1,
	GREY = 2,
	BLACK = 3,
};

class Vertex {
public:
	typedef std::list<Vertex*> vertices;
	Vertex() { }
	explicit Vertex(std::string aname) : name(aname)
	{ std::cout<<name<<" created"<<std::endl; }

	virtual ~Vertex() {std::cout<<name<<" deleted"<<std::endl;}
	
	//
	// copy and assign
	//
	Vertex(const Vertex& that_v)
	{
		name = that_v.name;
		std::cout<<name<<" copied"<<std::endl;
	}
	
	Vertex& operator=(const Vertex& that_v)
	{
		name = that_v.name;
		std::cout<<name<<" assigned"<<std::endl;
		if (true != connection_list.empty()) {
			throw VertexAssignException();
		}
		connection_list.clear();
		vertices::const_iterator it;
		for (it = that_v.connection_begin(); it != that_v.connection_end(); it ++) {
			add_connection(*it);
		}
	}

	// compare, do I need it?
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
	
	const std::string& get_name(void) const
	{
		return this->name;
	}
	

	//
	//  Add and Remove child vertex operation
	//
	void add_connection(Vertex* v)
	{
		connection_list.insert(connection_list.begin(), 1, v);
	}
	
	void del_connection(Vertex* v)
	{
		vertices::iterator it;
		for (it = connection_list.begin(); it != connection_list.end();
				it ++) {
			if (*it == v) {
				connection_list.erase(it);
				std::cout << "remove " << (*it)->get_name() << std::endl;
			}
		}
	}


	//
	//  begin and end iterator
	//
	vertices::const_iterator connection_begin(void) const
	{
		return connection_list.begin();
	}

	vertices::const_iterator connection_end(void) const
	{
		return connection_list.end();
	}
	
	void set_dist(unsigned dist)
	{
		dist_src = dist;
	}
	
	unsigned	get_dist(void) const
	{
		return dist_src;
	}
	
	void set_flag(unsigned f)
	{
		flag = f;
	}
	
	unsigned get_flag(void) const
	{
		return flag;
	}

private:
	unsigned				flag;
	unsigned				dist_src;
	std::string				name;
	mutable vertices		connection_list;
};

#if 0
class Graph {
public:
	typedef std::list<Vertex> vertices;
	Graph();
	virtual ~Graph();
	// copy and assign

	// building and traversing
	virtual void	add_vertex(Vertex& new_v);
	virtual void	del_vertex(const Vertex& v);
	virtual void	build_connection(Vertex& parent, const Vertex& child);
	virtual void	bfs_search(const Vertex& source);
private:
	// disallow the copy constructor and assign operator
	Graph(const Graph& that_g);
	Graph& operator=(const Graph& that_g);
	vertices		graph_vertices;
};
#endif
#endif // __GRAPH_H__
