'''
This is a node module collective
'''


class TreeNode:
  def __init__(self, key = None):
    self.__dict__['key'] = key
    self.__dict__['parent'] = None
    self.__dict__['left'] = None
    self.__dict__['right'] = None

  def __getattr__(self, name):
    if self.__dict__.has_key(name):
      return self.__dict__[name]
    else:
      raise AttributeError, "Node has no attribute %s"%(name)

  def __setattr__(self, name, val):
    if self.__dict__.has_key(name):
      self.__dict__[name] = val
      if name != 'key':
        if name == 'parent':
          if val.key > self.__dict__['key']:
            val.__dict__['left'] = self
          else:
            val.__dict__['right'] = self
        else:
          val.__dict__['parent'] = self
    else:
      raise AttributeError, "Node has no attribute %s"%(name)

  def __cmp__(self, other):
    '''Delegation of comparison calls to the key's comparison method
       It is actually comparing the keys not the node'''
    return self.key.__cmp__(other.key)


if __name__ == '__main__':
  pass
