#ifndef __LIARLIAR_H__
#define __LIARLIAR_H__

#include "graph.h"

enum PeopleTypes {
	e_Default = 0,
	e_Liar = 1,
	e_Trusty = 2,
};

// each liar is a vertex on a graph
class Liar : public Graph {
private:
	enum PeopleTypes		m_personality;
public:
    Liar()					{ m_personality = e_Default; }
	virtual ~Liar()			{ }

};

#endif
