/* 
 * File:   news.h
 * Author: prateek
 *
 * Created on 4 April, 2016, 6:34 PM
 */

#ifndef NEWS_H
#define	NEWS_H

#include"newfile.h"

class news:public Webpages
{
    protected:
        char newsid[50];
        int count;
        string type;
        ifstream f1;
        ofstream f3,f2;
        ifstream f4;
        
    public:
        news()
        {
            type="News";
            cout<<"Enter the No. of webpages you want to dump=";
            cin>>noWebpages;
            count=1;
        }
        void dumpWebpages()
        {
            
            strcpy(srcFilename,"/home/prateek/Desktop/OOPSProject/WebUrls/News.txt");
            f1.open(srcFilename);
            
            while(count<=noWebpages)
            {
                f1>>webURL;
                totalCount++;
                sprintf(newsid,"News-%d",count); 
                strcpy(destFilename,"/home/prateek/Desktop/OOPSProject/News/");
                strcat(destFilename,newsid);
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
            while((f4>>totalCount>>type>>webURL>>newsid)!=0)
            {
                cout<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<newsid<<endl;
            }
            f4.close();
        }
        void fileOperation()
        {
            f3.open("/home/prateek/Desktop/OOPSProject/Dumpedfile.txt",ios::app);
            f3<<totalCount<<"\t"<<type<<"\t"<<webURL<<"\t"<<newsid<<endl;
            f3.close();
        }
        ~news(){}
};

#endif	/* NEWS_H */