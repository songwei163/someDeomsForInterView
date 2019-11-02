//
// Created by S on 2019/10/31.
//

#include "BinaryTree.h"
#include <fstream>
#include <iomanip>

void visit(const BinTreeNode<int> *t) {
  cout << t->data << "   ";
}

void test01();

int main() {
  test01();
}

void test01() {
  ifstream fin("data.txt");
  assert(fin);
  BinaryTree<int> binTree(0);
  assert(fin >> binTree);
  fin.close();
  cout << "The binary tree is: \n" << binTree << endl;
  binTree.Output();
  ofstream fout("output.txt");
  assert(fout);
  binTree.Output(fout);
  fout.close();
  BinaryTree<int> binTree1(binTree);
  cout << "The copy binary tree is: \n" << binTree1 << endl;
  binTree1.Output();

  cout << "\nThe preorder of the binary tree is:\n";
  binTree.PreOrder(visit);
  cout << "\n\nThe inorder of the binary tree is:\n";
  binTree.InOrder(visit);
  cout << "\n\nThe postorder of the binary tree is:\n";
  binTree.PostOrder(visit);
  cout << "\n\nThe levelOrder of the binary tree is:\n";
  binTree.levelOrder(visit);
  cout << "\n\nThe height of the binary tree is:\n";
  cout << binTree.Height();
  cout << "\n\nThe Size of the binary tree is:\n";
  cout << binTree.Size();
  cout << endl << endl;
}