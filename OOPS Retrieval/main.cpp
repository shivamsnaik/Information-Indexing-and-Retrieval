/* 
 * File:   main.cpp
 * Author: prateek
 *
 * Created on 9 April, 2016, 5:30 AM
 */

#include "newfile.h"
#include "node.h"
#include "retrieval.h"
#include "text.h"
#include "user.h"
#include "video.h"


int main(int argc, char** argv) 
{
    int ch;
    user u1;
    while(1)
    {
        cout<<"Select Your Category:\n1.Video\t2.Text\t3.Exit"<<endl;
        cin>>ch;
        
        if(ch==1)
        {           
            video v1;
            v1.retrieve();
        }
        else if(ch==2)
        {
            text t1;
            t1.retrieve();
        }
        else if(ch==3)
            return 0;
        else
            cout<<"Invalid Choice!!!"<<endl;
    }
    return 0;
}   



