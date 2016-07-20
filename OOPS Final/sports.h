/* 
 * File:   sports.h
 * Author: prateek
 *
 * Created on 4 April, 2016, 6:47 PM
 */

#ifndef SPORTS_H
#define	SPORTS_H

#include"newfile.h"

class sports:public Webpages
{
    protected:
        char sportid[50];
        string type;
        int count;
        ifstream f1;
        ofstream f3,f2;
        ifstream f4;
        
    public:
        sports()
        {
            type="Sports";
            cout<<"Enter the No. of webpages you want to dump=";
            cin>>noWebpages;
            count=1;
        }
        void dumpWebpages()
        {
            
            strcpy(srcFilename,"/home/prateek/Desktop/OOPSProject/WebUrls/Sports.txt");
            f1.open(srcFilename);
            
            while(count<=noWebpages)
            {
                f1>>webURL;
                totalCount++;
                sprintf(sportid,"Sports-%d",count); 
                strcpy(destFilename,"/home/prateek/Desktop/OOPSProject/Sports/");
                strcat(destFilename,sportid);
                f2.open(destFilename);
                fileOperation();
                f2<<webURL<<endl;
                sprintf(dump,"w3m -dump http://%s >> %s",webURL,destFilename);
                system(dump);
                
                count++;
                f2.close();
            }
            f1.close(); 
        }
        void display()
        {
            f4.open("/home/prateek/Desktop/OOPSProject/Dumpedfile.txt");
            while((f4>>totalCount>>type>>webURL>>sportid)!=0)
            {
                cout<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<sportid<<endl;
            }
            f4.close();
        }
        void fileOperation()
        {
            f3.open("/home/prateek/Desktop/OOPSProject/Dumpedfile.txt",ios::app);
            f3<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<sportid<<endl;
            f3.close();
        }
        ~sports(){}
               
};


#endif	/* SPORTS_H */