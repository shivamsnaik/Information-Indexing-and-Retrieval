/* 
 * File:   avl.h
 * Author: prateek
 *
 * Created on 6 April, 2016, 11:29 AM
 */

#ifndef AVL_H
#define	AVL_H

#include "newfile.h"
#include "node.h"
#include "sorting.h"

class AVLTree:public sort,public Node
{
protected:
     
    int balFactor;
    Node *root;
    
public:
    AVLTree(){root=NULL;}

    
    int height1(Node *root)
    {
        if(root==NULL)
            return 0;
        return (root->height);
    }

    Node * rotateRight(Node *y)
    {
        Node *x=y->llink;
	Node *t3=x->rlink;
	x->rlink=y;
	y->llink=t3;
	y->height=max1(height1(y->llink),height1(y->rlink))+1;
	x->height=max1(height1(x->llink),height1(x->rlink))+1;
	return x;
    }

    Node * rotateLeft(Node *y)
    {
	Node *x=y->rlink;
	Node *t3=x->llink;
	x->llink=y;
	y->rlink=t3;
	y->height=max1(height1(y->llink),height1(y->rlink))+1;
	x->height=max1(height1(x->llink),height1(x->rlink))+1;
	return x;
    }

    int max1(int a,int b)
    {
        return a>b?a:b;
    }
    
    int balFactor1(Node *root)
    {
        if(root==NULL)
            return 0;
        else
            return height1(root->llink)-height1(root->rlink);
    }
    
    void sort1(Node *root,ofstream &f2)
    {
        if(root==NULL)
            return;
        sort1(root->llink,f2);
        f2<<root->keyword<<"\t"<<(root->count)+1<<endl;
        sort1(root->rlink,f2);
    }
    
    void sorting(int count,string input)
    {
        int n=1;
        for(i=1;i<=count;i++)
        {        
            if(input=="Web")
            {
                sprintf(srcfilename,"/home/prateek/Desktop/OOPSProject/Indexed/index-%d",i);
                f1.open(srcfilename);
                if(!f1.is_open())
                    continue;

                sprintf(destfilename,"/home/prateek/Desktop/OOPSProject/Sorted/sort-%d",i);
                f2.open(destfilename);
                m=0; 
            }
            else if(input=="Video")
            {
                sprintf(srcfilename,"/home/prateek/Desktop/OOPSProject/video/Indexed/index-%d",i);
                f1.open(srcfilename);
                if(!f1.is_open())
                    continue;

                sprintf(destfilename,"/home/prateek/Desktop/OOPSProject/video/Sorted/sort-%d",i);
                f2.open(destfilename);
                m=0; 
            }
            
            while(!f1.eof())
            {
                f1>>key;
                if((m++)==0)
                {
                    if(input=="Web")
                        f2<<key<<endl;
                    else if(input=="Video")
                    {
                        f2<<n++<<endl;
                        // n=i;
                    }
               
                }   
                else 
                    root=insertNode(root,key);
            }
            sort1(root,f2);
       
            f1.close();
            f2.close();
            root=NULL;
        }
    }
    
    Node *insertNode(Node *root,string key)
    {
        if(root==NULL)
        { 
            root=getNode();
            root->keyword=key;
            root->count=0;
        
            return root;
        }
        if(key==root->keyword)
        {
            root->count+=1;
            return root;
        }
        if((key<root->keyword))
            root->llink=insertNode(root->llink,key);
        else
            root->rlink=insertNode(root->rlink,key);
    
        root->height=max1(height1(root->llink),height1(root->rlink))+1;
        balFactor=balFactor1(root);
    
        if(balFactor>1 && key<(root->llink->keyword))            //left-left
            root=rotateRight(root);
        else if(balFactor>1 && key>root->llink->keyword)       //left-right
        {
            root->llink=rotateLeft(root->llink);
            root=rotateRight(root);
        }
        else if(balFactor<-1 && key>root->rlink->keyword)
            root=rotateLeft(root);
        else if(balFactor<-1 && key<root->rlink->keyword)
        {        
            root->rlink=rotateRight(root->rlink);
            root=rotateLeft(root);
        }
   
        return root;   
    }
    
    
    
};

#endif	/* AVL_H */