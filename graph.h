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
            
      void show_info() const {
        // this means every class T should have a show_info method
        _self->show_info();
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

#if 0
  template<class _Tp>
    class Graph {
    public:
      typedef Vertex<_Tp>*                         node_pointer;
      typedef Vertex<_Tp>&                         node_reference;
      typedef const Vertex<_Tp>&                   const_node_reference;
      typedef list<node_pointer>                   vertices;
      typedef size_t                               size_type;
      typedef typename vertices::iterator          iterator;
      typedef typename vertices::const_iterator    const_iterator;
    private:
      // disallow the copy constructor and assign operator
      Graph(const Graph<_Tp>& that_g);
      Graph& operator=(const Graph<_Tp>& that_g);
      // members
      vertices    graph_vertex_;
      int         count;

    public:
      Graph() {}
      virtual ~Graph() {}
      // building and traversing
      virtual void add_vertex(node_pointer vertex) {
        graph_vertex_.insert(graph_vertex_.begin(), 1, vertex);
      }

      virtual void del_vertex(node_pointer vertex) {
        iterator it;

        // let all other connections know v is going to disconnect
        for (it = graph_vertex_.begin(); it != graph_vertex_.end(); it++) {
          if (*it != vertex) {
            (*it)->remove_child(*vertex);
          } else {
            graph_vertex_.erase(it);
          }
        }
      }

      virtual void add_edge(node_reference parent, const node_pointer child) {
        parent.insert_child(child);
      }

      // Breadth First Traversal
      void bfs_search(node_pointer source) {
        vertices bfs_queue;
        const_iterator cit;

        for (cit = graph_vertex_.begin(); cit != graph_vertex_.end(); cit++) {
          if (*cit != source)
            (*cit)->set_state(WHITE);
          else
            (*cit)->set_state(GRAY);
        }

        bfs_queue.push_back(source);
        while (bfs_queue.empty() != true) {
          node_pointer u = bfs_queue.front();
          bfs_queue.pop_front();
          for (cit = u->begin_child(); cit != u->end_child(); cit++) {
            if ((*cit)->state()== WHITE) {
              (*cit)->set_state(GRAY);
              bfs_queue.push_back(*cit);
            }
          }
          u->set_state(BLACK);
        }
      }
      
      // Depth First Search (DFS) impl.
      void dfs_search(node_pointer source) {
      }

      bool in_graph(const string& name){
        const_iterator cit;
        for (cit = graph_vertex_.begin(); cit != graph_vertex_.end(); cit++) {
          if (name == (*cit)->name())
            return true;
        }
        return false;
      }
    }; // end of class Graph
#endif
} // end namespace sg

#endif // __GRAPH_H__
