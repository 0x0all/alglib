/*
 *  graph.h
 *  Created by BRIAN PIN on 9/3/2009.
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

namespace std {

enum VertexState {
  WHITE = 1, // not visited
  GRAY = 2,
  BLACK = 3,
  SOURCE = 4,
};

typedef enum VertexState VertexState_e;

template <typename _Tp>
class Vertex {

  string  _vt_name;
  VertexState_e  _vt_state;
  list<_Tp*>  _vt_next;

protected:
  typedef void* _Void_pointer;

public:

  typedef _Tp value_type;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;

  // constructor/destructor
  Vertex() : _vt_name("no name")
    {}
  explicit Vertex(string name) : _vt_name(name)
    {cout << _vt_name << " created" << endl;}

  virtual ~Vertex()
    {cout << _vt_name << " deleted" << endl;}

  // copy constructor
  Vertex(const Vertex<_Tp>& that_v) {
    _vt_state = that_v._vt_state;
    _vt_name = that_v._vt_name;
    _vt_next.clear();
    typename list<_Tp*>::const_iterator cit;
    for (cit = that_v.first_child() ; cit != that_v.last_child() ; cit ++) {
      add_child(*cit);
    }
    cout << _vt_name << " copied" << endl;

  }

  Vertex<_Tp>& operator=(const Vertex<_Tp>& that_v)
  {
    _vt_state = that_v._vt_state;
    _vt_name = that_v._vt_name;
    _vt_next.clear();
    typename list<_Tp*>::const_iterator cit;
    for (cit = that_v.first_child() ; cit != that_v.last_child() ; cit ++) {
      add_child(*cit);
    }
    cout << _vt_name << " assigned" << endl;

    return *this;
  }

  bool operator==(const Vertex<_Tp>& u) const
  {
    if (this == &u && _vt_name == u._vt_name)
      return true;
    else
      return false;
  }

  bool operator!=(const Vertex<_Tp>& u) const
  {
    return !(*this==u);
  }

  // getters and setters
  string get_name(void) const {return this->_vt_name;}
  void set_name(string name) {this->_vt_name = name;}

  void set_state(VertexState_e s) {_vt_state = s;}
  VertexState_e get_state(void) const {return _vt_state;}

  //
  //  Add and Remove child vertex operation
  //
  void add_child(Vertex<_Tp>& v) {
    _vt_next.insert(_vt_next.begin(), 1, v);
  }

  void del_child(Vertex<_Tp> v) {
    typename list<_Tp*>::iterator it;
    for (it = _vt_next.begin(); it != _vt_next.end(); it ++) {
      if (*it == v) {
        _vt_next.erase(it);
        cout << "remove " << (*it)->get_name() << endl;
      }
    }
  }

  typename list<_Tp*>::const_iterator first_child(void) const {
    return _vt_next.begin();
  }

  typename list<_Tp*>::const_iterator last_child(void) const {
    return _vt_next.end();
  }

};


template<typename _T>
class BaseGraph {

  // disallow the copy constructor and assign operator
  BaseGraph(const BaseGraph<_T>& that_g);
  BaseGraph& operator=(const BaseGraph<_T>& that_g);

  list<_T*>  _g_vertices;

public:

  BaseGraph() {}
  virtual ~BaseGraph() {}
  // copy and assign

  // building and traversing
  virtual void add_vertex(Vertex<_T>* new_v)
  {
    _g_vertices.insert(_g_vertices.begin(), 1, new_v);
  }

  virtual void del_vertex(Vertex<_T>* v)
  {
	typename list<_T*>::iterator it;

	// let all other connections know v is going to disconnect
    for (it = _g_vertices.begin(); it != _g_vertices.end(); it++) {
	  if (*it != v) {
	    (*it)->del_child(v); // easy to mislead and error prone, not real delete
	  } else {
	    _g_vertices.erase(it);
	  }
    }
  }

  virtual void add_edge(Vertex<_T>* parent, Vertex<_T>* child)
  {
    parent->add_child(child);
  }

  virtual void bfs_search(Vertex<_T>* source)
  {
	list<_T*> bfs_q;
	typename list<_T*>::const_iterator cit;

	for (cit = _g_vertices.begin(); cit != _g_vertices.end(); cit++) {
	  if (*cit != source)
	    (*cit)->set_state(WHITE);
	  else
	    (*cit)->set_state(GRAY);
	}

	bfs_q.push_back(source);
	while (bfs_q.empty() != true) {
	  Vertex<_T>* u = bfs_q.front();
	  bfs_q.pop_front();
	  for (cit = u->first_child(); cit != u->last_child(); cit++) {
	    if ((*cit)->get_state()== WHITE) {
	      (*cit)->set_state(GRAY);
	      bfs_q.push_back(*cit);
	    }
	  }
	  u->set_state(BLACK);
	}
  }
};

} // end namespace std

#endif // __GRAPH_H__
