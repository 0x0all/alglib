/*
 *  Copy right(c) Brian Pin 2009.
 */

#ifndef __LIARLIAR_H__
#define __LIARLIAR_H__

#include <string>
#include "graph.h"

struct ClubMember {
  std::string  _member_name;
};
/*
 *  class Club is a kind of graph
 *
 */

class Club : public std::BaseGraph<struct ClubMember> {
private:
  int _nr_members;
public:
  Club() {}
  virtual ~Club() {}

  int build_club(const char* filename);
};

#endif
