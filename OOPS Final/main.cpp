/* 
 * File:   main.cpp
 * Author: prateek
 * Created on 3 April, 2016, 3:33 PM
 */

#include "newfile.h"
#include "web.h"
#include "hospital.h"
#include "news.h"
#include "sports.h"
#include "entertainment.h"
#include "index.h"
#include "sorting.h"
#include "binarytree.h"
#include "linkedlist.h"
#include "avl.h"
#include "node.h"
#include "video.h"
#include "quicksort.h"

timeval start,stop;
void display()
{
    cout<<"Time Taken="<<stop.tv_sec-start.tv_sec<<" Seconds"<<endl;
}

int main(int argc, char** argv) 
{
    int count=0;
    int count1=0;
    Webpages *p[4];
    int ch,i=0,ch1;
    
    
    while(1)
    {
        cout<<"***********************************Welcome****************************************\n \nSelect category for dumping:\n1.Video\t2.Webpages\t3.Exit"<<endl;
        cin>>ch1;
        
        if(ch1==1)
        {
            gettimeofday(&start,NULL);
            video v1;
            gettimeofday(&stop,NULL);
            display();
        }
        else if(ch1==2)
        {
            gettimeofday(&start,NULL);
            while(1)
            {
                 cout<<"Select Your Category to dump Webpage data:\n1.Hospital\n2.News\n3.Sports\n4.Entertainment\n5.Display History\n6.Exit"<<endl;
                 cin>>ch;
        
            switch(ch)
            {
                case 1: p[i]=new Hospital;
                p[i]->dumpWebpages();
                break;

                case 2: p[++i]=new news;
                p[i]->dumpWebpages();
                break;

                case 3: p[++i]=new sports;
                p[i]->dumpWebpages();
                break;

                case 4: p[++i]=new entertainment;
                p[i]->dumpWebpages();
                break;

                case 5:p[i]->display();
                break;

                case 6:break;

                default:cout<<"INVALID CHOICE...!!!!!"<<endl;

                }
                if(ch==6)
                    break;
            }
            gettimeofday(&stop,NULL);
            display();
        }
        else if(ch1==3)
        {
            
            cout<<"Redirecting to Indexing part!!!\n"<<endl;
            break;
        }
        else
            cout<<"Invalid Choice!!!\n"<<endl;
    }
    for(int i=0;i<4;i++)
        delete p[i];
    
    gettimeofday(&start,NULL);
    Index in(&count,"Hospital");
    Index in1(&count,"Sports");
    Index in2(&count,"Entertainment");
    Index in3(&count,"News");
    Index in4(&count1,"video");
    sort *s1;
    s1=new AVLTree;
    s1->sorting(count,"Web");
    s1->sorting(count1,"Video");    
    gettimeofday(&stop,NULL);
    cout<<"Time Taken for Indexing and Sorting:";
    display();
    return 0;
}