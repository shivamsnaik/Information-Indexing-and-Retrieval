/* 
 * File:   user.h
 * Author: prateek
 *
 * Created on 9 April, 2016, 11:09 AM
 */

#ifndef USER_H
#define	USER_H


#include"newfile.h"

class user
{
	string ssn;
	string city;
	string country;
	string username;
	      
public:
	ofstream f;
	user()
	{
            cout<<"*****************************Welcome to Search Engine********************************\n"<<endl;
		
		cout<<"Enter your Name=";
		cin>>username;
                cout<<"Enter your SSN=";
		cin>>ssn;
                cout<<"Enter your city=";
		cin>>city;
		cout<<"Country=";
		cin>>country;
                
		f.open("/home/prateek/Desktop/OOPSProject/User_History",ios::app);
                disp();
        }

	void disp()
	{
		//cout<<"username="<<username<<"\nlogin status="<<loginstatus<<"\nssn="<<ssn<<"\ncity="<<city<<"\ncountry="<<country<<endl<<endl;
		f<<"Username="<<username<<"\nSSN="<<ssn<<"\nCity="<<city<<"\nCountry="<<country<<"\n"<<endl;
	}
};


#endif	/* USER_H */
