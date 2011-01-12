'''
This py code is going to implement B-Tree.
In BTree the typical considerations are the time spent on CPU and the number
of time to access disks. Since B-Tree is widely used in Disk accessing impl.
But here, I do not want to add the disk accessing part since in this time
right now, I just want to implement and practice these BTree operations.
'''
from node import TreeNode

'''
Node class has-a or has-a lot of Key class objects
'''
class BST(object):
  ''' The operation in the BST requires the Node object to be able to:
      1. compare with each other
      2. has left and right child pointer
  '''
  def __init__(self, r_key = None):
    if r_key is not None:
      self._root = TreeNode(r_key)

  def node(self, key):
    return self.search(self, key)

  def _search(self, node, key):
    if node.key == key:
      return node
    else:
      if node.key < key:
        if self._right(self, node) is not None:
          self._search(self, node.right, key)
        else:
          return None
      else:
        if node.left is not None:
          self._search(self, node.left, key)
        else:
          return None

  def search(self, key):
    if self._root.key == key:
      return self._root
    else:
      if self._root.key < key:
        if self._root.right is not None:
          return self._search(self, self._root.right, key)
        else:
          return None
      else:
        if self._root.left is not None:
          return self._search(self, self._root.left, key)
        else:
          return None

  def insert(self, key):
    if self._root is None:
      self._root = TreeNode(key)
    else:
      node = self._root
      while node is not None:
        if node.key < key:
          if node.right is None:
            node.right = TreeNode(key)
          else:
            node = node.right
        else:
          if node.left is None:
            node.left = TreeNode(key)
          else:
            node = node.left
  def _subtree_max(self, node):
    nd = node
    while nd is not None:
      nd = nd.right
    if nd is None:
      return None
    else:
      return nd.key

  def _subtree_min(self, node):
    nd = node
    while nd is not None:
      nd = nd.left
    if nd is None:
      return None
    else:
      return nd.key

  def succ(self, node):
    ''' Assume node is already in the tree
        returns the key that is the successor of the node
    '''
    if node.right is not None:
      nd = node.right
      return self._subtree_min(nd)
    else:
      if id(node.parent.left) == id(node):
        return node.parent.key
      else:
        return None

  def pred(self, node):
    '''
    The node is already in the tree
    '''
    if node.left is not None:
      return node.left.key
    else:
      if node.parent is None:
        return None
      else:
        if id(node) == id(node.parent.right):
          return node.parent.key
        else: # node is the left of its parent
          pt = node.parent
          nd = node
          while pt is not None:
            if id(pt.right) == id(nd):
              return pt.key
            else:
              nd = pt
              pt = pt.parent

