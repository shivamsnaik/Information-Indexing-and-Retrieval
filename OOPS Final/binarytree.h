/* 
 * File:   binarytree.h
 * Author: prateek
 *
 * Created on 1 May, 2016, 10:02 PM
 */

#ifndef BINARYTREE_H
#define	BINARYTREE_H

#include "newfile.h"
#include "node.h"
#include "sorting.h"

class BINTree:public sort,public Node
{
protected:
     
    Node *root;
    
public:
    BINTree(){root=NULL;}

    
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
        
        return root;   
    }   
};

#endif	/* BINARYTREE_H */

