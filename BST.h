/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 *
 * Aaron Crandall - 2016 - Added / updated: Ngoc Duong
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *
 */

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <queue>
#include <iomanip> // std::setw
using namespace std;

/*
 *  Node datastructure for single tree node
 */ 
template <class T>
struct Node {
    T nodeData;
    Node *pLeftNode;
    Node *pRightNode;
    
    //Node constructor
    Node(T val)
    {
        nodeData = val;
        pLeftNode = nullptr;
        pRightNode = nullptr;
    }
};


/*
 * Binary Search Tree (BST) class implementation
 */
template <class T>
class BST {

    private:
    Node<T> *root;

    /* HEPER FUNCTIONS */

    //This function uses recursive to add a node to the tree
    void add(T val, Node<T> *&tempRoot)
    {
        if (!tempRoot)     //if tree is empty then make a node to store val a root
            tempRoot = new Node<T>(val);
        else if (val < tempRoot->nodeData) //insert val to the left if val < current node
            add(val, tempRoot->pLeftNode);
        else
            add(val, tempRoot->pRightNode); //insert val to the right if val < current node
    }

    //This function uses recursive to help printPreOrder() in public
    void helpPrintPreOrder(Node<T> *&tempRoot)
    {
        if (tempRoot)
        {
            cout << tempRoot->nodeData << " ";
            helpPrintPreOrder(tempRoot->pLeftNode);
            helpPrintPreOrder(tempRoot->pRightNode);
        }
    }
    
    //This function uses recursive to help nodesCount() in public
    void nodesCount(Node<T> *&tempRoot, int & count)
    {
        if (tempRoot)
        {
            count++;
            nodesCount(tempRoot->pLeftNode, count);
            nodesCount(tempRoot->pRightNode, count);
        }
    }

    //This function returns height of a given node of the tree
    int height(Node<T> *node, int & h)
    {
        if (!node) //a tree without node has height = 0, with one node has height = 1
            h = 0;
        else
        {
            int hLeft = height(node->pLeftNode, h); //get height of left branch
            int hRight = height(node->pRightNode, h); //get height of right branch

            if (hLeft > hRight) //height of tree = heigh of higher branch + 1
                h = hLeft + 1;
            else
                h = hRight + 1;    
        }
        return h;        
    }

    public:
    void add(T val) {
			//cout << " BST::inserting " << setw(7) << val << " to the tree." << endl;
            add(val, root); //call private helper add()make 
    }

    void print() {
			this->printPreOrder();
    }

    void printPreOrder() {
        helpPrintPreOrder(root); //call private helper printpreOrder()
    }

    int nodesCount() {
        int count = 0;
        nodesCount(root, count); //call private helper nodesCount()
        return count;
    }

    int height() {
        int h = 0;
        height(root, h); //call private helper height()
        return h;
    }
};

#endif
