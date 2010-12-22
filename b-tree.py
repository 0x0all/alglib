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

class BST:
  pass
class BTree(BST):
