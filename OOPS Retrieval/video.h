/* 
 * File:   video.h
 * Author: prateek
 *
 * Created on 9 April, 2016, 11:30 AM
 */

#ifndef VIDEO_H
#define	VIDEO_H

#include "newfile.h"
#include "retrieval.h"

class video:public retrieval
{
protected:
    string searchword;
    char srcfilename[200];
    string link;
    string keyword;
    timeval start,stop;
    ifstream f1;
    
    public:
    video()
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
   
        for(int i=1;i<=20;i++)
        {
            flag=0;
            sprintf(srcfilename,"/home/prateek/Desktop/OOPSProject/video/Sorted/sort-%d",i);
            f1.open(srcfilename);
            count=0;
            count1=1;
            f1>>link;
                   
            search();
            
            f1.close();
        }
        disp(root);
                 
        gettimeofday(&stop,NULL);
        
        if(root!=NULL)
        {
            cout<<"Your Query Successfully Processed!!!!\n"<<endl;
            vid();
        }
        else if(root==NULL)
        {
            cout<<"No Results Found!!!!\n"<<endl;
        }
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
        cout<<"Time taken="<<stop.tv_sec-start.tv_sec<<" Seconds"<<endl;
    }
    void vid()
    {
        int i;
        char ch[50];
        printf("Enter the video count number to view the Video:");
        cin>>i;
        sprintf(ch,"mplayer  /home/prateek/Desktop/OOPSProject/video/vedio%d.mp4",i);
        system(ch);
    }
};
    
#endif	/* VIDEO_H */

