'''
This py code is going to implement B-Tree.
In BTree the typical considerations are the time spent on CPU and the number
of time to access disks. Since B-Tree is widely used in Disk accessing impl.
But here, I do not want to add the disk accessing part since in this time
right now, I just want to implement and practice these BTree operations.
'''


class BSTError(Exception): pass
class UnknownNodeTypeError(BSTError): pass
class ReassignError(BSTError): pass


'''
Node class has-a or has-a lot of Key class objects
'''
class TreeNode:
  def __init__(self, key = None):
    self.__key = key
    self.__parent = None
    self.__left = None
    self.__right = None

  def __getattr__(self, name):
    if name == 'left':
      return self.__left
    elif name == 'right':
      return self.__right
    elif name == 'parent':
      return self.__parent
    elif name == 'key':
      return self.__key
    else:
      raise UnknownNodeTypeError, "BST only support left, right and parent. No %s"%(name)

  def __setattr__(self, name, it):
    if name == 'left':
      if self.__left is not None:
        raise ReassignError, "The %s is already assigned to some other node"%(name)
      else:
        self.__left = it
      return
    if name == 'right':
      if self.__right is not None:
        raise ReassignError, "The %s is already assigned to some other node"%(name)
      else:
        self.__right = it
      return
    if name == 'parent':
      if self.__parent is not None:
        raise ReassignError, "The %s is already assigned to some other node"%(name)
      else:
        self.__parent = it
      return
    if name == 'key':
      self.__key = it
    raise UnknownNodeTypeError, "The assign of the node should be left, right or parent"

  def __cmp__(self, other):
    '''Delegation of comparison calls to the key's comparison method
       It is actually comparing the keys not the node'''
    return self.__key.__cmp__(other.key)

class BST(object):
  ''' The operation in the BST requires the Node object to be able to:
      1. compare with each other
      2. has left and right child pointer
  '''
  def __init__(self, r = None):
    self._root = TreeNode(r)

  def __search(self, node, key):
    if node == key:
      return node
    else:
      if node < key:
        if self.__right(self, node) is not None:
          self.__search(self, node.right, key)
        else:
          return None
      else:
        if node.left is not None:
          self.__search(self, node.left, key)
        else:
          return None

  def search(self, key):
    if self._root == key:
      return self._root
    else:
      if self._root < key:
        if self._root.right is not None:
          return self.__search(self, self._root.right, key)
        else:
          return None
      else:
        if self._root.left is not None:
          return self.__search(self, self._root.left, key)
        else:
          return None

  def insert(self, key):
    if self._root is None:
      self._root = key
    else:
      node = self._root
      while node is not None:
        if node < key:
          if node.right is None:
            node.right = key
            key.parent = node
          else:
            node = node.right
        else:
          if node.left is None:
            node.left = key
            key.parent = node
          else:
            node = node.left

  def successor(self, key):
    raise NotImplementedError

  def predecessor(self, key):
    node = self.search(self, key)
    if node is not None:
      if self.__left(self, node) is not None:
        return self.find_max(self, self.__left(self, node))
      else:
        parent = self.__parent(self, node)
        tmp = node
        while parent is not None:
          if id(self.__left(self, parent)) == id(tmp):
            return parent
          else:
            tmp = parent
            parent = self.__parent(self, parent)
        return tmp

  def find_max(self, node):

