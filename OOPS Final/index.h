/* 
 * File:   index.h
 * Author: prateek
 *
 * Created on 6 April, 2016, 11:23 AM
 */

#ifndef INDEX_H
#define	INDEX_H

#include "newfile.h"

class Index
{
protected:
    char temp4[100];
    int j,count1;
    char keyword[200];
    char sourceName[200];
    char destName[200];
    ifstream f1;
    ofstream f2;
    ifstream dictionary;
    int flag,flag1;
public:
    
    Index(){}
    Index(int *total_count,char input[])
    {
        int i,m;
        cout<<"ENTER THE NO OF FILES TO BE INDEXED in "<<input<<endl;
        cin>>count1;
        flag=0,flag1=0;
        for(j=1;j<=count1;(*total_count)++,j++)
        {
            if(!strcmp(input,"video"))
            {
                sprintf(sourceName,"/home/prateek/Desktop/OOPSProject/%s/%s/%s-%d",input,input,input,j); 
                sprintf(destName,"/home/prateek/Desktop/OOPSProject/video/Indexed/index-%d",*(total_count)+1);
            }
            else
            {
                sprintf(sourceName,"/home/prateek/Desktop/OOPSProject/%s/%s-%d",input,input,j);  
                sprintf(destName,"/home/prateek/Desktop/OOPSProject/Indexed/index-%d",*(total_count)+1);
            }
            f1.open(sourceName);  
            f2.open(destName);
            m=0;
            while(!f1.eof())
            {
                f1>>keyword;
                if((m++)==0)
                    f2<<keyword<<endl;
                flag=0;
                flag1=0;
                deleteUnwanted();
                if(flag1==1)
                    continue;

                store();
                if (flag==0)
                    f2<<keyword<<endl;
                dictionary.close();
                
            }
            f1.close();
            f2.close();
        }
        
    }

    void store()
    {
        int i;
        dictionary.open("/home/prateek/Desktop/OOPSProject/verb_dictionary.txt");
        while(!dictionary.eof())
        {
            dictionary>>temp4;
            for(i=0;keyword[i]!='\0';i++)
            {
                if(keyword[i]>='A' && keyword[i]<='Z')
                {
                    keyword[i]=keyword[i]+32;
                }
            }
            for(i=0;temp4[i]!='\0';i++)
            {
                if(temp4[i]>='A' && temp4[i]<='Z')
                {
                    temp4[i]=temp4[i]+32;
                }
            }

            if(!strcmp(keyword,temp4))
            {
                flag=1;
                break;
            }
        }
    }

    void deleteUnwanted()
    {
        int i;
        for(i=0;keyword[i]!='\0';i++)
        {
            if (keyword[i]=='\0')
                continue;
            if(!isalpha(keyword[i]))
            {
                flag1=1;
                break;
            }
        }
    }
    
    ~Index()
    {
        cout<<"INDEXING HAS BEEN COMPLETED"<<endl;
    }
};

#endif	/* INDEX_H */