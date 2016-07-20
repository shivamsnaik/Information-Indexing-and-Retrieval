/* 
 * File:   retrieval.h
 * Author: prateek
 *
 * Created on 9 April, 2016, 5:32 AM
 */

#ifndef RETRIEVAL_H
#define	RETRIEVAL_H

#include "newfile.h"

class retrieval:public node
{
protected:
    int count,count1;
    int flag,m;
    node *root;
    
    
public:
    retrieval()
    {
        flag=0;
        m=0;
        root=NULL;
    }
    
    virtual void retrieve()=0; 
    virtual void search()=0;
    
    virtual ~retrieval(){}
};



#endif	/* RETRIEVAL_H */

