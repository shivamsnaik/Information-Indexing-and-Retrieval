/* 
 * File:   entertainment.h
 * Author: prateek
 *
 * Created on 5 April, 2016, 4:16 PM
 */

#ifndef ENTERTAINMENT_H
#define	ENTERTAINMENT_H

#include"newfile.h"

class entertainment:public Webpages
{
protected:
    char entid[50];
    int count;
    string type;
    ifstream f1;
    ofstream f3,f2;
    ifstream f4;
    
public:
    entertainment()
    {
        type="Hospital";
        cout<<"Enter the No. of webpages you want to dump=";
        cin>>noWebpages;
        count=1;
    }
    void dumpWebpages()
        {
            strcpy(srcFilename,"/home/prateek/Desktop/OOPSProject/WebUrls/Entertainment.txt");
            f1.open(srcFilename);
            
            while(count<=noWebpages)
            {
                f1>>webURL;
                totalCount++;
                sprintf(entid,"Entertainment-%d",count); 
                strcpy(destFilename,"/home/prateek/Desktop/OOPSProject/Entertainment/");
                strcat(destFilename,entid);
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
            while((f4>>totalCount>>type>>webURL>>entid)!=0)
            {
                cout<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<entid<<endl;
            }
            f4.close();
        }
        void fileOperation()
        {
            f3.open("/home/prateek/Desktop/OOPSProject/Dumpedfile.txt",ios::app);
            f3<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<entid<<endl;
            f3.close();
        }
        
    ~entertainment(){}
};

#endif	/* ENTERTAINMENT_H */