/* 
 * File:   node.h
 * Author: prateek
 *
 * Created on 6 April, 2016, 11:24 AM
 */

#ifndef NODE_H
#define	NODE_H

#include "newfile.h"

class Node
{
public:   
    string keyword;
    int height;
     int count;
    Node *rlink;
    Node *llink;
    Node *head;
 
    
public:
    Node()
    {
        count=0;
        height=0;
    }
    
    void insertNode(){}
    //virtual void insertNode(){}

     Node* getNode()
    {
	Node *temp;
	temp=new Node;
	temp->rlink=temp->llink=NULL;
	return temp;
    }
    
    ~Node()
    {
    }
};

#endif	/* NODE_H */