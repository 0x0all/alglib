/*
 *  graph.h
 *  Created by BRIAN PIN on 9/3/09.
 *  Copyright 2009 P. All rights reserved.
 *  Learning points:
 *	1. Simple, simplicity
 *  2. const_iterator and iterator,
 *  3. exception types
 *
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

class Vertex;
typedef std::list<Vertex> vertices;

class Vertex {
public:

	Vertex() {}
	explicit Vertex(std::string aname)
	{
		name = aname;
	}

	virtual ~Vertex() {}
	
	//
	// copy and assign
	//
	Vertex(const Vertex& that_v)
	{
		name = that_v.name;
	}
	
	Vertex& operator=(const Vertex& that_v)
	{
		name = that_v.name;
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
	bool operator==(const Vertex& u)
	{
		if (this == &u && name == u.name)
			return true;
		else
			return false;
	}

	bool operator!=(const Vertex& u)
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
	void add_connection(const Vertex& v)
	{
		connection_list.push_back(v);
	}
	
	void del_connection(const Vertex& v)
	{
		vertices::iterator it;
		for (it = connection_list.begin(); it != connection_list.end();
				it ++) {
			if (*it == v) {
				connection_list.erase(it);
				std::cout << "remove " << it->get_name() << std::endl;
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

private:
	std::string		name;
	vertices		connection_list;
};


class Graph {
public:
	Graph();
	virtual ~Graph();
	// copy and assign

	// building and traversing
	virtual void	add_vertex(const Vertex& new_v);
	virtual void	del_vertex(const Vertex& v);
	virtual void	build_connection(const Vertex& parent, const Vertex& child);
	virtual void	bfs_search(const Vertex& source);
private:
	// disallow the copy constructor and assign operator
	Graph(const Graph& that_g);
	Graph& operator=(const Graph& that_g);
	vertices		graph_vertices;
};

#endif // __GRAPH_H__
