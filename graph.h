/*
 *  graph.h
 * 
 *
 *  Created by BRIAN PIN on 9/3/09.
 *  Copyright 2009 PuzzleLogiceInc. All rights reserved.
 *  We are a Puzzle Solving Company!
 *
 */


typedef enum VertexEdgeDirection {
	OUT_GOING = 0,
	IN_COMING = 1,
} VEDirection;


class Vertex;
typedef std::list<Vertex *> vertices;

class Vertex {
public:
	Vertex();
	virtual		~Vertex();

	void		add_connect(Vertex& v, VEDirection direction);
	void		remove_connect(Vertex& v, VEDirection direction);
	Vertex&		pop_first(VEDirection direction);
	unsigned	get_edges(enum VertexEdgeDirection direction);

	void		set_id(int id);
	int			get_id(void) const;
private:
	int			identifier_;
	vertices	outs_;
	vertices	ins_;
};
