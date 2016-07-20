/* 
 * File:   text.h
 * Author: prateek
 *
 * Created on 9 April, 2016, 5:32 AM
 */

#ifndef TEXT_H
#define	TEXT_H

#include "newfile.h"
#include "retrieval.h"

class text:public retrieval
{
protected:
    string searchword;
    char srcfilename[200];
    string link;
    string keyword;
    timeval start,stop;
    ifstream f1;
      
public:
    text()
    {
        flag=0;
        m=0;
        root=NULL;
    }
    
    void retrieve()
    {
        
        printf("Enter a word to search:");
        cin>>searchword;
        gettimeofday(&start,NULL);
          
        for(int i=1;i<=60;i++)
        {
            flag=0;
            sprintf(srcfilename,"/home/prateek/Desktop/OOPSProject/Sorted/sort-%d",i);
            f1.open(srcfilename);
            count=0;
            count1=1;
            f1>>link;
                   
            search();
            
            f1.close();
        }
        if(root!=NULL)
        {
            cout<<"Your Query has Successfully Processed!!!!\n"<<endl;
                   
            disp(root);
        }
        else if(root==NULL)
        {
            cout<<"No Results Found!!!!\n"<<endl;
        }
       
        gettimeofday(&stop,NULL);
        display();
    }
    
    void search()
    {
        while(!f1.eof() && flag==0)
        {
            f1>>keyword;
            f1>>count;
            if(searchword==keyword)
            {
                root=insertnode(root,count,link);
                flag=1;
            }  
            
        }
    }
    
    void display()
    {
        cout<<"Time taken="<<stop.tv_sec-start.tv_sec<<" Seconds\n"<<endl;
    }
    ~text()
    {
        cout<<"Your Query Processed..!!!"<<endl;
    }
};


#endif	/* TEXT_H */

