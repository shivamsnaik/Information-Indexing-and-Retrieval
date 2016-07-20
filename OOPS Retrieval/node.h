/* 
 * File:   node.h
 * Author: prateek
 *
 * Created on 9 April, 2016, 5:42 AM
 */

#ifndef NODE_H
#define	NODE_H

#include "newfile.h"

class node
{
protected:
    int count;
    string a;
    node *rlink,*llink;
    node *temp;
    
public:
    node(){}
    
    node* getnode()
    {
        temp=new node;
        temp->rlink=temp->llink=NULL;
        return temp;
    }

    node* insertnode(node *root,int c,string key)
    {
        if(root==NULL)
        {    
            root=getnode();
            root->a=key;
            root->count=c;
            return root;
        }
    
        if(c<root->count)
            root->llink=insertnode(root->llink,c,key);
        else
            root->rlink=insertnode(root->rlink,c,key);
        return root;   
    }
    
    void disp(node *root)
    {
        if(root==NULL)
            return;
        disp(root->rlink);
        cout<<"Count="<<root->count<<"\tLINK="<<root->a<<endl;
        disp(root->llink);
    }
};


#endif	/* NODE_H */

