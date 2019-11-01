//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_TREE_BINARYTREE_BINARYTREE_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_TREE_BINARYTREE_BINARYTREE_H_

template<typename T>
struct BinTreeNode {
  T data;
  BinTreeNode<T> *leftChild;
  BinTreeNode<T> *rightChild;

  BinTreeNode() : leftChild(nullptr), rightChild(nullptr) {}
  explicit BinTreeNode(T e, BinTreeNode<T> *l = nullptr, BinTreeNode<T> *r = nullptr)
      : leftChild(l), rightChild(r), data(e) {}
};

template<typename T>
class BinaryTree {
 public:
  BinaryTree() : root(nullptr) {}
  explicit BinaryTree(T value) : root(nullptr), RefValue(value) {}

  ~BinaryTree(){}

 private:
  BinTreeNode<T> *root;
  T RefValue;
};

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_TREE_BINARYTREE_BINARYTREE_H_
