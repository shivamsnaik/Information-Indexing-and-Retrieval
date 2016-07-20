/* 
 * File:   sorting.h
 * Author: prateek
 *
 * Created on 7 April, 2016, 11:54 AM
 */

#ifndef SORTING_H
#define	SORTING_H

#include "newfile.h"    
         

class sort
{
protected:
    ifstream f1;
    ofstream f2;
    char srcfilename[200];
    char destfilename[200];
    string key;
    int i,m;
public:
    
    sort(){}
    
   virtual void sorting(int count,string input){};

    
};


#endif	/* SORTING_H */