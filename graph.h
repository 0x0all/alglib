/*
 *  graph.h
 * 
 *
 *  Created by BRIAN PIN on 9/3/09.
 *  Copyright 2009 PuzzleLogicInc. All rights reserved.
 *  We are a Puzzle Solving Company!
 *
 */


typedef enum VertexEdgeDirection {
	OUT_GOING = 0,
	IN_COMING = 1,
} EdgeDirection;


class Vertex;
typedef std::list<Vertex *> vertices;

class Vertex {
public:
	Vertex();
	virtual		~Vertex();

	void		add_connect(Vertex* v, EdgeDirection direction);
	void		remove_connect(Vertex* v, EdgeDirection direction);
	Vertex*		front(EdgeDirection direction);
	int		get_edges(EdgeDirection direction);
	
	// iteration functions
	vertices::iterator get_begin(EdgeDirection direction);

	void		set_id(int id);
	int		get_id(void) const;
private:
	int		m_id;
	vertices	m_outs;
	vertices	m_ins;
};
