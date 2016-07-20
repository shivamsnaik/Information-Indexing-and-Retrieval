/* 
 * File:   web.h
 * Author: prateek
 *
 * Created on 4 April, 2016, 6:24 PM
 */

#ifndef WEB_H
#define	WEB_H

#include "newfile.h"

class Webpages
{
protected:
    char srcFilename[100];
    int noWebpages;
    char destFilename[100];
    char webURL[100];
    char dump[100];
    static int totalCount;
    
public:
    Webpages()
    {
        installW3m();
    }
    void installW3m()
    {
        system("sudo apt-get install w3m");
    }
    virtual void dumpWebpages()=0;
    virtual void display()=0;
    virtual void fileOperation()=0;
    virtual ~Webpages(){}
};

int Webpages::totalCount=0;
#endif	/* WEB_H */