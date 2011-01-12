'''
This a unit test module for module node
'''
import unittest
from node import TreeNode

class TestNode(unittest.TestCase):
  def test_basic_relation(self):
    parent = TreeNode(9)
    node = TreeNode(8)
    left = TreeNode(6)
    right = TreeNode(7)
    node.parent = parent
    node.left = left
    node.right = right
    self.assertEqual(id(node.parent), id(parent))
    self.assertEqual(id(node.left), id(left))
    self.assertEqual(id(node.right), id(right))
    self.assertEqual(id(left.parent), id(node))
    self.assertEqual(id(right.parent), id(node))
    self.assertEqual(id(node.parent), id(parent))
    self.assertEqual(id(parent.left), id(node))


if __name__ == '__main__':
  unittest.main()
