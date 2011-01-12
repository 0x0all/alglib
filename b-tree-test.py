import sys
import unittest
import BSTree

class TestBSTreeCase(unittest.TestCase):
  def test_insert(self):
    tree = BSTree.BinarySearchTree()
    tree.insert(15)
    tree.insert(8)
    tree.insert(22)
    tree.insert(11)
    tree.insert(5)
    tree.insert(20)
    tree.insert(27)
    tree.insert(1)
    tree.insert(7)
    self.assertEqual(tree.node(8),  tree.node(15).left)
    self.assertEqual(tree.node(22), tree.node(15).right)
    self.assertEqual(tree.node(5),  tree.node(8 ).left)
    self.assertEqual(tree.node(11), tree.node(8 ).right)
    self.assertEqual(tree.node(20), tree.node(22).left)
    self.assertEqual(tree.node(27), tree.node(22).right)
    self.assertEqual(tree.node(1),  tree.node(5 ).left)
    self.assertEqual(tree.node(7),  tree.node(5 ).right)

  def test_find(self):
    tree = BSTree.BinarySearchTree()
    tree.insert(15)
    tree.insert(8)
    tree.insert(22)
    tree.insert(11)
    tree.insert(5)
    tree.insert(20)
    tree.insert(27)
    tree.insert(1)
    tree.insert(7)
    self.assertTrue(tree.search(15))
    self.assertTrue(tree.search(8))
    self.assertTrue(tree.search(22))
    self.assertTrue(tree.search(11))
    self.assertTrue(tree.search(5))
    self.assertTrue(tree.search(20))
    self.assertTrue(tree.search(27))
    self.assertTrue(tree.search(1))
    self.assertTrue(tree.search(7))


if __name__ == '__main__':
  unittest.main()
