//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_TREE_BINARYTREE_BINARYTREE_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_TREE_BINARYTREE_BINARYTREE_H_

#include <iostream>
#include <string>
#include <cassert>
#include <queue>
#include <stack>

using namespace std;

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
  bool Find(const T &e) const { return Find(root, e); }
  int Height() const { return Height(root); }
  int Size() const { return Size(root); }
  BinTreeNode<T> *getRoot() const { return root; }
  void PreOrder(void (*visit)(const BinTreeNode<T> *ptr)) const { PreOrder(root, visit); }
  void InOrder(void (*visit)(const BinTreeNode<T> *ptr)) const { PreOrder(root, visit); }
  void PostOrder(void (*visit)(const BinTreeNode<T> *ptr)) const { PreOrder(root, visit); }
  void levelOrder(void (*visit)(const BinTreeNode<T> *ptr)) const;
  bool Insert(const T &e) { return Insert(root, e); }
 public:
  void printBinTree(ostream &out = cout) const { printBinTree(root, out); }
  void Output(ostream &out = cout) const {
    out << "The structure of the binary tree is:\n";
    Output(root, string(" "), out);
    out << endl;
  }
  void PreOrder1(void (*visit)(const BinTreeNode<T> *ptr)) const;
  void InOrder1(void (*visit)(const BinTreeNode<T> *ptr)) const;
  void PostOrder1(void (*visit)(const BinTreeNode<T> *ptr)) const;
  void CreateCompBinTree(T *CBT, int num) { CreateCompBinTree(CBT, num, 0, root); }
  friend istream &operator>>(istream &in, BinaryTree<T> &Tree) {
    Tree.CreateBinTree(in, Tree.root);
    return in;
  }
  friend ostream &operator<<(ostream &out, BinaryTree<T> &Tree) {
    Tree.printBinTree(out);
    out << endl;
    return out;
  }
 private:
  void CreateBinTree(istream &in, BinTreeNode<T> *&subTree);
  void CreateCompBinTree(T *CBT, int num, int rt, BinTreeNode<T> *&subTree);
  void Traverse(const BinTreeNode<T> *subTree, ostream &out) const;
  void printBinTree(const BinTreeNode<T> *subTree, ostream &out = cout) const;
  void Output(BinTreeNode<T> *subTree, const string &str, ostream &out) const;
  bool Find(const BinTreeNode<T> *subTree, const T &e) const;
  BinTreeNode<T> *Copy(const BinTreeNode<T> *r) const;
  BinTreeNode<T> *Parent(const BinTreeNode<T> *subTree, BinTreeNode<T> *current) const;
  void destory(BinTreeNode<T> *subTree);
  int Height(BinTreeNode<T> *subTree) const;
  int Size(BinTreeNode<T> *subTree) const;
  void PreOrder(const BinTreeNode<T> *subTree, void (*visit)(const BinTreeNode<T> *ptr)) const;
  void InOrder(const BinTreeNode<T> *subTree, void (*visit)(const BinTreeNode<T> *ptr)) const;
  void PostOrder(const BinTreeNode<T> *subTree, void (*visit)(const BinTreeNode<T> *ptr)) const;
  bool Insert(BinTreeNode<T> *subTree, const T &e);
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
void BinaryTree<T>::PostOrder(const BinTreeNode<T> *subTree, void (*visit)(const BinTreeNode<T> *)) const {
  if (subTree != nullptr) {
    PostOrder(subTree->leftChild, visit);
    PostOrder(subTree->rightChild, visit);
    visit(subTree);
  }
}

template<typename T>
void BinaryTree<T>::InOrder(const BinTreeNode<T> *subTree, void (*visit)(const BinTreeNode<T> *)) const {
  if (subTree != nullptr) {
    InOrder(subTree->leftChild, visit);
    visit(subTree);
    InOrder(subTree->rightChild, visit);
  }
}

template<typename T>
void BinaryTree<T>::PreOrder(const BinTreeNode<T> *subTree, void (*visit)(const BinTreeNode<T> *)) const {
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
void BinaryTree<T>::levelOrder(void (*visit)(const BinTreeNode<T> *)) const {
  if (root == nullptr) return;
  queue<BinTreeNode<T> *> Q;
  BinTreeNode<T> *p = root;
  visit(p);
  Q.push(p);
  while (!Q.empty()) {
    p = Q.front();
    Q.pop();
    if (p->leftChild != nullptr) {
      visit(p->leftChild);
      Q.push(p->leftChild);
    }
    if (p->rightChild != nullptr) {
      visit(p->rightChild);
      Q.push(p->rightChild);
    }
  }
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

template<typename T>
bool BinaryTree<T>::Find(const BinTreeNode<T> *subTree, const T &e) const {
  if (subTree == nullptr) {
    return false;
  }

  if (subTree->data == e) {
    return true;
  }

  bool p = false;
  p = Find(subTree->leftChild, e);
  if (p) {
    return true;
  } else {
    return Find(subTree->rightChild, e);
  }
}

template<typename T>
bool BinaryTree<T>::Insert(BinTreeNode<T> *subTree, const T &e) {
  if (subTree == nullptr) {
    subTree = new BinTreeNode<T>(e);
    assert(subTree);
    return true;
  } else {
    return Insert(subTree->leftChild, e) || Insert(subTree->rightChild, e);
  }
}

template<typename T>
void BinaryTree<T>::printBinTree(const BinTreeNode<T> *subTree, ostream &out) const {
  if (subTree != nullptr) {
    out << subTree->data;
    if (subTree->leftChild || subTree->rightChild) {
      out << "(";
      printBinTree(subTree->leftChild, out);
      if (subTree->rightChild) {
        out << ",";
      }
      printBinTree(subTree->rightChild, out);
      out << ")";
    }
  }
}

template<typename T>
void BinaryTree<T>::Output(BinTreeNode<T> *subTree, const string &str, ostream &out) const {
  if (subTree == nullptr) {
    return;
  }
  out << str << subTree->data;
  if (subTree->leftChild) {
    out << "©¤©´" << endl;
    if (subTree->rightChild) {
      Output(subTree->leftChild, str + "©¦¡¡", out);
    } else {
      Output(subTree->leftChild, str + "¡¡¡¡", out);
    }
  }
  if (subTree->rightChild) {
    out << endl << str << "©¸©¤©´" << endl;
    Output(subTree->rightChild, str + "¡¡¡¡", out);
  }
}

template<typename T>
void BinaryTree<T>::PostOrder1(void (*visit)(const BinTreeNode<T> *)) const {

}

template<typename T>
void BinaryTree<T>::InOrder1(void (*visit)(const BinTreeNode<T> *)) const {
  stack<BinTreeNode<T> *> S;
  BinTreeNode<T> *ptr = root;

  do {
    while (ptr != nullptr) {
      S.push(ptr);
      ptr = ptr->leftChild;
    }
    if (!S.empty()) {
      ptr = S.top();
      S.pop();
      visit(ptr);
      ptr = ptr->rightChild;
    }
  } while (ptr != nullptr || !S.empty());
}

template<typename T>
void BinaryTree<T>::PreOrder1(void (*visit)(const BinTreeNode<T> *)) const {
  stack<BinTreeNode<T> *> S;
  BinTreeNode<T> *ptr = root;

  S.push(nullptr);
  while (ptr != nullptr) {
    visit(ptr);
    if (ptr->rightChild != nullptr) {
      S.push(ptr->rightChild);
    }
    if (ptr->leftChild != nullptr) {
      ptr = ptr->leftChild;
    } else {
      ptr = S.top();
      S.pop();
    }
  }
}

template<typename T>
void BinaryTree<T>::Traverse(const BinTreeNode<T> *subTree, ostream &out) const {
  if (subTree != nullptr) {
    out << subTree->data << ' ';
    Traverse(subTree->leftChild, out);
    Traverse(subTree->rightChild, out);
  }
}

template<typename T>
void BinaryTree<T>::CreateCompBinTree(T *CBT, int num, int rt, BinTreeNode<T> *&subTree) {
  if (rt >= num) {
    subTree = nullptr;
  } else {
    subTree = new BinTreeNode<T>(CBT[rt]);
    assert(subTree != nullptr);
    CreateCompBinTree(CBT, num, 2 * rt + 1, subTree->leftChild);
    CreateCompBinTree(CBT, num, 2 * rt + 2, subTree->rightChild);
  }
}

template<typename T>
void BinaryTree<T>::CreateBinTree(istream &in, BinTreeNode<T> *&subTree) {
  T item;
  if (in >> item) {
    if (item != RefValue) {
      subTree = new BinTreeNode<T>(item);
      assert(subTree);
      CreateBinTree(in, subTree->leftChild);
      CreateBinTree(in, subTree->rightChild);
    } else {
      subTree = nullptr;
    }
  }
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_TREE_BINARYTREE_BINARYTREE_H_
