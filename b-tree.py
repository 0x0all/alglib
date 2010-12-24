'''
This py code is going to implement B-Tree.
In BTree the typical considerations are the time spent on CPU and the number
of time to access disks. Since B-Tree is widely used in Disk accessing impl.
But here, I do not want to add the disk accessing part since in this time
right now, I just want to implement and practice these BTree operations.
'''


'''
This Key class here is just used as an example or test purposes.
It can be replaced by other data object classes that is designed
and used in the BTree
'''
class Key:
  """Key in the Tree is used to sort, compare in various operations"""
  def __init__(self):
    self.value = 0
  def __lt__(self, other):
    if self.value < other.value:
      return True
    else:
      return False
  def __le__(self, other):
    if self.value <= other.value:
      return True
    else
      return False
 
'''
Node class has-a or has-a lot of Key class objects
'''
class Node:
  """The B-Tree node contains t-1 <= # of keys <= 2t-1
     and also may or may not havs child nodes downward"""
  degree_ = 0
  def __init__(self, keys = [], childs = []):
    self._keys = keys
    self._childs = childs
  @staticmethod
  def set_deg(degree):
    self._degree = degree 

class BST(object):
  ''' The operation in the BST requires the Node object to be able to:
      1. compare with each other
      2. has left and right child pointer
  '''
  def __init__(self, r = None):
    self._root = r

  def __search(self, node, key):
    if node == key:
      return node
    else:
      if node < key:
        if node.right is not None:
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
          else:
            node = node.right
        else:
          if node.left is None:
            node.left = key
          else:
            node = node.left

  def delete(self, key):


