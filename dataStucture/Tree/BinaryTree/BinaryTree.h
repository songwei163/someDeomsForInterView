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
  BinaryTree(const BinaryTree<T> &s) {
    if (this != &s) {
      root = Copy(s.root);
    }
  }
  ~BinaryTree() { destory(root); }

 public:
  bool IsEmpty() const { return root == nullptr; }
  BinTreeNode<T> *Parent(const BinTreeNode<T> *current) const;
  BinTreeNode<T> *LeftChild(const BinTreeNode<T> *current) const {
    return current != nullptr ? current->leftChild : nullptr;
  }
  BinTreeNode<T> *RightChild(const BinTreeNode<T> *current) const {
    return current != nullptr ? current->rightChild : nullptr;
  }
  int Height() const { return Height(root); }
  int Size() const { return Size(root); }
  BinTreeNode<T> *getRoot() const { return root; }
  void preOrder(void (*visit)(BinTreeNode<T> *ptr)) const { preOrder(root, visit); }
  void inOrder(void (*visit)(BinTreeNode<T> *ptr)) const { preOrder(root, visit); }
  void postOrder(void (*visit)(BinTreeNode<T> *ptr)) const { preOrder(root, visit); }
  void levelOrder(void (*visit)(BinTreeNode<T> *ptr)) const;

 private:
  BinTreeNode<T> *Copy(const BinTreeNode<T> *r) const;
  BinTreeNode<T> *Parent(const BinTreeNode<T> *subTree, BinTreeNode<T> *current) const;
  void destory(BinTreeNode<T> *subTree);
  int Height(BinTreeNode<T> *subTree) const;
  int Size(BinTreeNode<T> *subTree) const;
  void preOrder(const BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *ptr)) const;
  void inOrder(const BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *ptr)) const;
  void postOrder(const BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *ptr)) const;
  int Insert(const T &item);
  BinTreeNode<T> *Find(T &item) const;
 private:
  BinTreeNode<T> *root;
  T RefValue;
};

template<typename T>
BinTreeNode<T> *BinaryTree<T>::Parent(const BinTreeNode<T> *current) const {
  return {
      (root == nullptr || root == current)
      ? nullptr
      : Parent(root, current)
  };
}

template<typename T>
int BinaryTree<T>::Insert(const T &item) {
  return 0;
}

template<typename T>
BinTreeNode<T> *BinaryTree<T>::Find(T &item) const {
  return nullptr;
}
template<typename T>
void BinaryTree<T>::postOrder(const BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *)) const {
  if (subTree != nullptr) {
    PostOrder(subTree->leftChild, visit);
    PostOrder(subTree->rightChild, visit);
    visit(subTree);
  }
}

template<typename T>
void BinaryTree<T>::inOrder(const BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *)) const {
  if (subTree != nullptr) {
    InOrder(subTree->leftChild, visit);
    visit(subTree);
    InOrder(subTree->rightChild, visit);
  }
}

template<typename T>
void BinaryTree<T>::preOrder(const BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *)) const {
  if (subTree != nullptr) {
    visit(subTree);
    PreOrder(subTree->leftChild, visit);
    PreOrder(subTree->rightChild, visit);
  }
}

template<typename T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree) const {
  if (subTree == nullptr) {
    return 0;
  } else {
    return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
  }
}

template<typename T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree) const {
  if (subTree == nullptr) {
    return 0;
  } else {
    int i = Height(subTree->leftChild);
    int j = Height(subTree->rightChild);
    return (i < j) ? j + 1 : i + 1;
  }
}

template<typename T>
void BinaryTree<T>::levelOrder(void (*visit)(BinTreeNode<T> *)) const {

}

template<typename T>
void BinaryTree<T>::destory(BinTreeNode<T> *subTree) {
  if (subTree != nullptr) {
    destory(subTree->leftChild);
    destory(subTree->rightChild);
    delete subTree;
  }
}

template<typename T>
BinTreeNode<T> *BinaryTree<T>::Parent(const BinTreeNode<T> *subTree, BinTreeNode<T> *current) const {
  if (subTree == nullptr) {
    return nullptr;
  }

  if (subTree->leftChild == current || subTree->rightChild == nullptr) {
    return subTree;
  }
  BinTreeNode<T> *ptr;
  if ((ptr = Parent(subTree->leftChild, current)) != nullptr) {
    return ptr;
  } else {
    return Parent(subTree->rightChild, current);
  }
}

template<typename T>
BinTreeNode<T> *BinaryTree<T>::Copy(const BinTreeNode<T> *r) const {
  if (r == nullptr) {
    return nullptr;
  }
  BinTreeNode<T> *ptr = new BinTreeNode<T>(r->data);
  ptr->leftChild = Copy(r->leftChild);
  ptr->rightChild = Copy(r->rightChild);
  return ptr;
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_TREE_BINARYTREE_BINARYTREE_H_
