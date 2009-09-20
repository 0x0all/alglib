/*
 *  graph.h
 *  Created by BRIAN PIN on 9/3/09.
 *  Copyright 2009 P. All rights reserved.
 *  We are a Puzzle Solving Company!
 *
 */
#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef enum VertexEdgeDirection {
	OUT_GOING = 0,
	IN_COMING = 1,
} EdgeDirection;


class Vertex;
typedef std::list<Vertex> vertices;
typedef vertices::iterator v_iter;

class Vertex {
public:
	Vertex() {}
	virtual ~Vertex() {std::cout<<"recycling vertex id:"<< m_id <<std::endl;}

	void		add_connect(Vertex& v, EdgeDirection direction);
	void		remove_connect(const Vertex& v, EdgeDirection direction);
	int			get_edges(EdgeDirection direction);

	// operator overloads
	bool		operator==(const Vertex& u);
	
	// connection iteration functions
	v_iter		begin(EdgeDirection direction);
	Vertex&		front(EdgeDirection direction);

	// visiting method
	virtual		void visit();
	
	void		set_id(int id);
	int			get_id(void) const;
private:
	int			m_id;
	vertices	m_outs;
	vertices	m_ins;
};


class Graph {
public:
	Graph() {}
	virtual ~Graph() {}

	static void   bfs_traversal(Vertex& startv);
};

#endif
