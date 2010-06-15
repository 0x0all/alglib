/*
 *  graph.h
 *  Created by BRIAN PIN on 9/3/2009.
 *  Copyright 2009 P. All rights reserved.
 *  Learning points:
 *  1. Simple, simplicity
 *  2. const_iterator and iterator,
 *  3. exception types
 *  4. mutable keyword
 *  5. STL containers insert,erase,push_back,pop, will all use a copy of T
 */
#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<iostream>
#include<sstream>
#include<fstream>
#include<list>

namespace graph_impl {
  
  typedef enum _GRAPH_STATUS {
    FOUND = 1,
    SUCCESS = 0,
    NOT_FOUND = -1,
  } GRAPH_STATUS_e;

  //
  // Vertex is a node inside a graph
  // Vertex implementation here is a utilization of STL::list<T> class
  // Every thing Graph should do against the Vertex neighbor or "child"
  // should delegate to the Vertex class
  //
  template <class T>
    class Vertex {
    private:
      /*
       * Data sectors of a node
       */
      std::list<Vertex<T>*>   _neighbors;
      T*                      _self;
      bool                    _is_directed;
      
      // forbidden copy and assign
      Vertex(const Vertex<T>& v){}
      Vertex<T>& operator=(const Vertex<T>& v){}

    public:
      // convenient typenames
      typedef typename std::list<Vertex<T>*>::iterator         v_iterator;
      typedef typename std::list<Vertex<T>*>::const_iterator   v_const_iterator;
      typedef typename std::list<Vertex<T>*>::size_type        size_type;
      
      // ctor/dtor
      Vertex() {
        _self = NULL;
        _is_directed = true;
      }

      Vertex(T* vptr, bool directed=true) {
        _self = vptr;
        _is_directed = directed;
      }
      
      virtual ~Vertex() {
        if (_neighbors.size() != 0) {
          std::cout << "vertex deleting when size != 0" << std::endl;
        }
        
        if (_self)
          delete _self;
      }

      // getters
      T* get_node() {
        return _self;
      }
      
      // fake iterator (because we are not doing our own iterator)
      
      v_iterator begin() {
        return _neighbors.begin();
      }
      
      v_iterator end() {
        return _neighbors.end();
      }
      
      v_const_iterator begin() const {
        return _neighbors.begin();
      }
      
      v_const_iterator end() const {
        return _neighbors.end();
      }
      
      // overload operators ...
      bool operator==(const Vertex<T>& other_vertex) {
        if (this->_self != NULL) {
          return (this->_self == other_vertex.get_node());
        } else {
          return false;
        }
      }

      bool operator==(const Vertex<T>* other_vertex) {
        if (this->_self != NULL) {
          return (this->_self == other_vertex->get_node());
        } else {
          return false;
        }
      }
      
      bool operator!=(const Vertex<T>& other_vertex) {
        if (this->_self != NULL) {
          return (this->_self != other_vertex.get_node());
        } else {
          return true;
        }
      }
      
      bool operator!=(const Vertex<T>* other_vertex) {
        if (this->_self != NULL) {
          return (this->_self != other_vertex->get_node());
        } else {
          return true;
        }
      }
      
      size_type size() const { return _neighbors.size(); }

      //
      //  Add and Remove child vertex operation
      //
      void insert(Vertex<T>* vptr) {
        _neighbors.push_back(vptr);
      }

      void remove(Vertex<T> *vptr) {
        if (FOUND == search(vptr)) {
          typename std::list<Vertex<T>*>::iterator i;
          for (i = _neighbors.begin(); i != _neighbors.end(); i++) {
            if (vptr == *i) {
              _neighbors.erase(i);
            }
          }
        }
      }

      void show_each_info() const {
        _self->show_obj();
      }
  
      void show_vertex() const {
        // this means every class T should have a show_info method
        typename std::list<Vertex<T>*>::const_iterator ci;
        this->show_each_info();
        std::cout << ": ";
        for (ci = _neighbors.begin(); ci != _neighbors.end(); ci++) {
          (*ci)->show_each_info();
        }
        std::cout << std::endl;
      }
  
      v_iterator erase(v_iterator i) {
        return _neighbors.erase(i);
      }

      GRAPH_STATUS_e search(Vertex<T>* vptr) {
        typename std::list<Vertex<T>*>::iterator itr;
        for (itr = _neighbors.begin(); itr != _neighbors.end(); itr++) {
          if (vptr == *itr) {
            return FOUND;
          }
        }
        return NOT_FOUND;
      }
    }; // end of class Vertex


  // I think it is a kind of container
  template<class _Tp>
    class Graph {
    public:
      typedef Vertex<_Tp>*                         node_pointer;
      typedef Vertex<_Tp>&                         node_reference;
      typedef const Vertex<_Tp>&                   const_node_reference;
      typedef std::list<node_pointer>              vertices;
      typedef size_t                               size_type;
      typedef typename vertices::iterator          iterator;
      typedef typename vertices::const_iterator    const_iterator;
    private:
      // disallow the copy constructor and assign operator
      Graph(const Graph<_Tp>& that_g);
      Graph& operator=(const Graph<_Tp>& that_g);
      // members
      vertices    _graph_vertex;
      int         _count;
      int         _is_directed;

    public:
      Graph() {}
      virtual ~Graph() {}

      void insert(Vertex<_Tp> *vt) {
        _graph_vertex.push_back(vt);
        // FIXME do we have to check if there is a replica of the vertex?
      }

      void remove(Vertex<_Tp> *vt) {
        iterator i;
        for (i = _graph_vertex.begin(); i != _graph_vertex.end(); i++) {
          if (vt == *i) {
            i = _graph_vertex.erase(i);
          } else {
            (*i)->remove(vt);
          }
        }
      }

      void show_graph(void) {
        iterator i;
        for (i = _graph_vertex.begin(); i != _graph_vertex.end(); i++) {
          (*i)->show_vertex();
        }
      }

    }; // end of class Graph

} // end namespace sg

#endif // __GRAPH_H__
