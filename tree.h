// 컴퓨터공학부   201614912   최낙운
#pragma once
#include <cstdio>
#include <cstdlib>
#include <math.h>
#define MAX_QUEUE_SIZE 100

inline void error(const char* str) {
   printf("%s", str);
   exit(1);
}

class BinaryNode {
protected:
   int data;
   BinaryNode* left;
   BinaryNode* right;

public:
   BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) : data(val), left(l), right(r) {}
   void setData(int val) { data = val; }
   void setLeft(BinaryNode* l) { left = l; }
   void setRight(BinaryNode* r) { right = r; }
   int getData() { return data; }
   BinaryNode* getLeft() { return left; }
   BinaryNode* getRight() { return right; }
   bool isLeaf() { return left == NULL && right == NULL; }
};




class CircularQueue {
   int front;
   int rear;
   BinaryNode* data[MAX_QUEUE_SIZE];

public:
   CircularQueue() { front = rear = 0; }
   bool isEmpty() { return front == rear; }
   bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
   void enqueue(BinaryNode* n) {
      if (isFull()) error("Error : 큐가 포화상태입니다\n");
      else {
         rear = (rear + 1) % MAX_QUEUE_SIZE;
         data[rear] = n;
      }
   }
   BinaryNode* dequeue() {
      if (isEmpty())error("큐가 공백상태입니다\n");
      else {
         front = (front + 1) % MAX_QUEUE_SIZE;
         return data[front];
      }
   }
};







class BinaryTree {

   BinaryNode* root;
public:
   BinaryTree() :root(NULL) {}
   void setRoot(BinaryNode* node) { root = node; }
   BinaryNode* getRoot() { return root; }
   bool isEmpty() { return root == NULL; }

   void inorder() { printf("\n   inorder:"); inorder(root); }
   void inorder(BinaryNode* node) {
      if (node != NULL) {
         inorder(node->getLeft());
         printf("  [%c]  ", node->getData());
         inorder(node->getRight());
      }
   }
   void preorder() { printf("\n   preorder : "); preorder(root); }
   void preorder(BinaryNode* node) {
      if (node != NULL) {
         printf("  [%c]  ", node->getData());
         preorder(node->getLeft());
         preorder(node->getRight());
      }

   }
   void postorder() { printf("\n   postorder : "); postorder(root); }
   void postorder(BinaryNode* node) {
      if (node != NULL) {
         postorder(node->getLeft());
         postorder(node->getRight());
         printf("  [%c]  ", node->getData());
      }
   }
   void levelorder() {

      printf("\nLevelorder : ");
      if (!isEmpty()) {
         CircularQueue q;
         q.enqueue(root);
         while (!q.isEmpty()) {
            BinaryNode* n = q.dequeue();
            if (n != NULL) {
               printf("  [%c]  ", n->getData());
               q.enqueue(n->getLeft());
               q.enqueue(n->getRight());
            }
         }
         printf("\n");

      }

   }

   int getCount() { return isEmpty() ? 0 : getCount(root); }
   int getCount(BinaryNode* node) {
      if (node == NULL) return 0;
      return 1 + getCount(node->getLeft()) + getCount(node->getRight());
   }


   int getHeight() { return isEmpty() ? 0 : getHeight(root); }
   int getHeight(BinaryNode* node) {
      if (node == NULL)return 0;
      int hLeft = getHeight(node->getLeft());
      int hRight = getHeight(node->getRight());
      return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
   }


   int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
   int getLeafCount(BinaryNode *node) {
      if (node == NULL) return 0;
      if (node->isLeaf()) return 1;
      else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
   }

   bool isFull() {
      if (!(getCount() >= pow(2, getHeight() - 1) && getCount() <= (pow(2, getHeight()) - 1))) {
         return false;
      }
      else return isFull(root); }
   bool isFull(BinaryNode* node) {
      if (node == NULL) return true;
      if (node->getLeft() == NULL && node->getRight() != NULL)return false;
      else if (node->isLeaf()) return true;
      else return isFull(node->getLeft()) && isFull(node->getRight());
   }

   int level(BinaryNode* node) {
      if (node == NULL) return 0;
      else {
         return getHeight() - getHeight(node) + 1;
      }
   }


   bool isBalanced() { return isEmpty() ? 0 : isBalanced(root); }
   bool isBalanced(BinaryNode* node) {
      int diff;
      if (node == NULL) return true;
      int hLeft = getHeight(node->getLeft());
      int hRight = getHeight(node->getLeft());
      diff = hLeft > hRight ? hLeft-hRight : hRight-hLeft;
      if (diff >= 2) return false;
      return isBalanced(node->getLeft()) && isBalanced(node->getRight());


   };

   bool reverse() {return isEmpty() ? 0 :reverse(root); }
   bool reverse(BinaryNode* node) {
      BinaryNode* temp;

      if (node != NULL) {

         if (!(node->isLeaf())) {
            temp = node->getLeft();
            node->setLeft(node->getRight());
            node->setRight(temp);
         }

         reverse(node->getLeft());
         reverse(node->getRight());
      }
      return 1;
   }

};


class BinSrchTree : public BinaryTree {
public:
    BinSrchTree(void) {}
    ~BinSrchTree(void) {}

    BinaryNode* search(int key){
        
    }
    BinaryNode* search(BinaryNode *n, int key) {


    }

    void insert(BinaryNode *n) {
        if(n==NULL)return;
        if(isEmpty())root = n;
        else insertRecur(root,n);
    }

    void remove(int key) {
        if(isEmpty())return;
        BinaryNode *parent = NULL;
        BinaryNode *node = root;
        while(node != NULL && node->getData() != key) {
            parent = node;
            node = (ket < node->getData())
        }
        
    }
    void remove(BinaryNode *parent, BiaryNode *node) {

    }

    void insertRecur(BinaryNode *r, BinaryNode *n) {
        if(n->getData() == r->getData())return ;
        else if(n->getData() < r->getData()) {
            if(r->getLeft() == NULL)r->setLeft(n);
            else insertRecur(r->getLeft(),n);

        }
        else {
            if(r->getRight() == NULL)r->getRight(n);
            else insertRecur(r->getRight(),n);
        }
    }


    BinaryNode* search(int key) {
        BinaryNode *node = searchRecur(root, key);
        if(node != NULL)printf("탐색 성공 : 키값이 %d인 노드 = 0x%x\n", node->getData(), node);
        else printf("탐색 실페 : 키값이 %d인 노드 없음 \n", key);
        return node;
    }

    BinaryNode* searchRecur(BinaryNode *n, int key) {
        if(n==NULL) return NULL;
        if(key==n->getData()) return n;
        else if (key < n->getData()) return searchRecur(n->getLeft(), key);
        else return searchRecur(n->getRight(), key);
    }


};








