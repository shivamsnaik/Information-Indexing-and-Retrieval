/* 
 * File:   hospital.h
 * Author: prateek
 *
 * Created on 4 April, 2016, 6:31 PM
 */

#ifndef HOSPITAL_H
#define	HOSPITAL_H

#include "newfile.h"

class Hospital:public Webpages
{
    protected:
        char hospitalId[100];
        int count;
        string type;
        ifstream f1;
        ofstream f2,f3;
        ifstream f4;
        
    public:
        Hospital()
        {
            type="Hospital";
            cout<<"Enter the No. of webpages you want to dump=";
            cin>>noWebpages;
            count=1;
        }
        void dumpWebpages()
        {
            strcpy(srcFilename,"/home/prateek/Desktop/OOPSProject/WebUrls/Hospital.txt");
            f1.open(srcFilename);
            
            while(count<=noWebpages)
            {
                f1>>webURL;
                totalCount++;
                sprintf(hospitalId,"Hospital-%d",count); 
                strcpy(destFilename,"/home/prateek/Desktop/OOPSProject/Hospital/");
                strcat(destFilename,hospitalId);
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
            while((f4>>totalCount>>type>>webURL>>hospitalId)!=0)
            {
                cout<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<hospitalId<<endl;
            }
            f4.close();
        }
        void fileOperation()
        {
            f3.open("/home/prateek/Desktop/OOPSProject/Dumpedfile.txt",ios::app);
            f3<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<hospitalId<<endl;
            f3.close();
        }
        ~Hospital(){}
};

#endif	/* HOSPITAL_H */