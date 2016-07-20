#include<iostream>
#include<string>
#include<fstream>
#include <algorithm>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

void symbol(int j)
{
	for(int i=0;i<=j;i++)
	{
		cout<<(char)690;
	}
}

string Asterisk()
{
wr:	string a;
	char b1;
	cout<<endl<<"\t"<<"To show the Password : Y(Yes) N(No)"<<endl;
	char i=_getch();
	if(i=='Y'||i=='y')
	{
		cout<<endl<<"\t";
		goto show;
	}
	else if(i=='N'||i=='n')
	{
		goto nshow;
		cout<<endl<<"\t";
	}
nshow: cout<<"\tEnter the Password"<<endl<<"\t";
	for(;(b1=_getch())!='\r';)
	{
		if(b1=='\b'){
			goto wr;
			continue;
		}
		cout<<"*";
		a+=b1;
		
	}
	cout<<endl;
	return a;

show: cout<<"Enter the Password"<<endl<<"\t";
	for(;(b1=_getche())!='\r';)
	{
		if(b1=='\b'){
			goto wr;
			continue;
		}
		a+=b1;
		
	}
	cout<<endl;
	return a;

}

string passwordInsert(string create_password,string username)
{
		pass:	cout<<" \t Enter Your Password:  ";
		create_password=Asterisk();
		if(create_password==username)
		{
			cout<<"THE Password cannot be the same as the Username"<<endl;
			goto pass;
		}
		int count[]={0,0,0};

		for(int i=0;i<create_password.size();i++)
		{
			if(create_password.at(i)=='@' ||create_password.at(i)=='(' ||create_password.at(i)==')')
			{
				(count[0])++;
			}
			if(create_password.at(i)>='A' && create_password.at(i)<='Z')
			{
				(count[1])++;
			}
			if(create_password.at(i)>= '1' && create_password.at(i)<= '9')
			{
				(count[2])++;
			}
		}

		if(count[0]<1||count[1]<1||count[2]<1)
		{
			cout<<"The password must contain special symbols like \"@,(,),#\",1 Upper Case letter and 1 number"<<endl;
			goto pass;
		}

		if(create_password.size()<8||create_password.size()>32)
		{
			cout<<"The length of the password must be from 8 to 32"<<endl;
			goto pass;
		}
		return create_password;
}
class user
{
	
public:
	string Firstname;
	string lastname;
	string username;
	string create_password;
	string confirm_password;
	int day;
	int month;
	int year;
	string gender;
	string mobile_number;
	string country;
	string agree;
	string petname;
	string colour;
	string recoverymail;
	string fpath;
	
	user()
	{}

	void createAccount()
	{
		system("cls");
		user b[100];
		int m=0;
		cout<<"             ";symbol(34);cout<<"      "<<endl;
		cout<<"             "<<(char)690<<"CREATE YOUR OWN GOOGLE ACCOUNT .!"<<(char)690<<"      "<<endl;
		cout<<"             ";symbol(34);cout<<"      \n\n"<<endl;

		ifstream fin("f1.txt");
		if(!fin.is_open())
		{
			ofstream fout("f1.txt");
			fout.close();
		}
		while(!fin.eof())
		{
			fin>>b[m].Firstname>>b[m].lastname>>b[m].username>>b[m].create_password>>b[m].day>>b[m].month>>b[m].year>>b[m].gender>>b[m].petname>>b[m].colour>>b[m].recoverymail>>b[m].mobile_number>>b[m].country>>b[m].fpath;
			m++;
		}
		fin.close();

		ofstream f;
		f.open("f1.txt",ios::app);//read

		// Enter your details
		cout<<" \t First Name:";
		cin>>Firstname;
//		f<<Firstname<<"\t";
		cout<<"\n";

		
		cout<<" \t Last name: ";
		cin>>lastname;
//		f<<lastname<<"\n";
		cout<<"\n";

usern:	cout<<" \t Choose a user Name: ";
		cin>>username;
		username=username+"@gmail.com";
		for(int i=0;i<m;i++)
		{
			if(b[i].username==username)
			{
				cout<<"UserName already exists. Please Choose another username"<<endl;
				goto usern;
			}
		}
//		f<<username<<"\n";
		cout<<"\n";

		create_password=passwordInsert(create_password,username);
//pass:	cout<<" \t Enter Your Password:  ";

		//cin>>create_password;
		//if(create_password==username)
		//{
		//	cout<<"THE Password cannot be the same as the Username"<<endl;
		//	goto pass;
		//}
		//int count[]={0,0,0};

		//for(int i=0;i<create_password.size();i++)
		//{
		//	if(create_password.at(i)=='@' ||create_password.at(i)=='(' ||create_password.at(i)==')')
		//	{
		//		(count[0])++;
		//	}
		//	if(create_password.at(i)>='A' && create_password.at(i)<='Z')
		//	{
		//		(count[1])++;
		//	}
		//	if(create_password.at(i)>= '1' && create_password.at(i)<= '9')
		//	{
		//		(count[2])++;
		//	}
		//}

		//if(count[0]<1||count[1]<1||count[2]<1)
		//{
		//	cout<<"The password must contain special symbols like \"@,(,),#\",1 Upper Case letter and 1 number"<<endl;
		//	goto pass;
		//}
		//f<<create_password<<"\n";
		cout<<"\n";

		  cout<<" \t Confirm Your Password:";
		 h: confirm_password=Asterisk();
		if(create_password==confirm_password)
		  {
			cout<<"  \t Password matches"<<endl;
		    cout<<"\n";
		  }
		else
		  {
			cout<<"Password doesn't match. Please try again"<<endl;
			goto h;
		  }

		cout<<"\n";

		cout<<"  \t Enter your DOB  \n";
date:		cout<<"  \t Enter day:  ";
		cin>>day;
		if(day<1||day>31)
			//f<<day<<" ";
		//else{ 
		{
			cout<<"DATE SHOULD BE B/W 01 and 31"<<endl;	
			goto date;
		}

		//cout<<"\n";
month:	cout<<"  \t Month(1-12):  ";
		cin>>month;
		if(month<1||month>12)
		{
			cout<<"Invalid Month Entered"<<endl;
			goto month;
		}
		//f<<month<<" ";

year:	cout<<"  \t Year:  ";
		cin>>year;
		if(year<1900||year>2016)
		{
			cout<<"Year Invalid"<<endl;
			goto year;
		}
		//f<<year<<"\n";
		
		
gender1:	cout<<"  \t Choose your Gender  : Male(1)   Female(2)   :  ";
		int ch;
		cin>>ch;
		if(ch==1)
		{
			gender="Male";
		}
		else if(ch==2)
		{
			gender="Female";
		}
		else
		{
			cout<<"Please Choose among the two Options."<<endl;
			goto gender1;
		}
		//f<<gender<<"\n";

		cout<<" \t Name of your First pet : ";
		cin>>petname;
		//f<<petname<<"\n";
		cout<<" \t what is your fav colour : ";
		cin>>colour;
		//f<<colour<<"\n";

rec:	cout<<"  \t Enter a recovery mail : ";
		cin>>recoverymail;
		if(recoverymail==username)
		{
			cout<<"Recovery Email cannot be same as your new Email Address."<<endl;
			goto rec;
		}
		
		int flag=0;
		for(int i=0;i<m;i++)
		{
			if(b[i].username==recoverymail)
			{
				flag=1;
				break;
			}
		}
		if(m<=1) goto mobile;
		if(flag==0)
		{
			cout<<"The Recovery Mail entered by you is not a Valid email address"<<endl;
			goto rec;
		}

		//f<<recoverymail<<endl;

mobile:	cout<<"  \t Enter your Phone number +91 ";
		cin>>mobile_number;

		if((mobile_number.size()!=10) || (mobile_number.at(0)!='9' && mobile_number.at(0)!='8' && mobile_number.at(0)!='7'))
		{
			cout<<"Please enter a valid Mobile number"<<endl;
			goto mobile;
		}

		for(int i=0;i<m;i++)
		{
			if(b[i].mobile_number==mobile_number)
			{
				cout<<"\nThis mobile number is already registered. Please enter a new mobile number"<<endl;
				goto mobile;
			}
		}
		
		
		//f<<mobile_number<<"\n";

		cout<<"  \t Enter Your Country  : ";
		cin>>country;
		//f<<country<<"\n";
	jew:cout<<"\nEnter the file path for OTP";
		cin>>fpath;
		string ne;
		ne=fpath+"\\opt.txt";
		ofstream nn(ne);

		if(!nn.is_open())
		{
			cout<<"\nInvalid filepath";
			goto jew;
		}
		int flag1=0;
		for(int i=0;i<m;i++)
		{
			if(b[i].fpath==fpath)
			{
				cout<<"\nThis file path is already registered. Please enter a new file path"<<endl;
				goto jew;
			}
		}

		f<<Firstname<<endl;
		f<<lastname<<endl;
		f<<username<<endl;
		f<<create_password<<endl;
		f<<day<<endl;
		f<<month<<endl;
		f<<year<<endl;
		f<<gender<<endl;
		f<<petname<<endl;
		f<<colour<<endl;
		f<<recoverymail<<endl;
		f<<mobile_number<<endl;
		f<<country<<endl;
		f<<fpath<<endl;


		f.close();
		cout<<"\nRedirecting to Sign In page[Please wait]"<<endl;
		Sleep(1000*60*0.05);
	}
	
};

void valid()
{
	int temp,var;
	string a,aa;
	user b[10];
	int count=0,j,m=0;
	char c[20],newpass[20];
	string z;
	ifstream fin("f1.txt");
	
	while(!fin.eof())
	{
		fin>>b[m].Firstname>>b[m].lastname>>b[m].username>>b[m].create_password>>b[m].day>>b[m].month>>b[m].year>>b[m].gender>>b[m].petname>>b[m].colour>>b[m].recoverymail>>b[m].mobile_number>>b[m].country>>b[m].fpath;
		m++;
	}
	system("cls");
	fin.close();
sym:cout<<"        ";symbol(19);cout<<"        "<<endl;
	cout<<"        "<<(char)690<<"    "<<"Login Page"<<"    "<<(char)690<<"        "<<endl;
	cout<<"        ";symbol(19);cout<<"        \n\n"<<endl;

an:	cout<<"\nEnter the User Name : ";
	cin>>a;
	string ccc;
	ccc=a+"@gmail.com";
	int flag=0;
	for(int i=0;i<m;i++)
	{
		if(b[i].username==a||b[i].username==ccc)
		{
			flag=1;
			am:	cout<<"Enter Password : ";
			z=Asterisk();
				if(b[i].create_password==z)
				{
					if(count==0)
					{
						Sleep(1000*60*0.03);
						system("cls");
					cout<<"\nLOGGED IN!";
					}

				else if(count>0)
					{
							system("cls");
						
							b[temp].create_password=passwordInsert(b[temp].create_password,b[temp].username);
							b[temp].confirm_password=b[temp].create_password;
							cout<<"\nPassword has been changed";
							//cout<<"\nLOGGED IN";
							count=0;
							ofstream fout("f1.txt");
							for(int kk=0;kk<m;kk++)
							{
								fout<<endl<<b[kk].Firstname<<endl<<b[kk].lastname<<endl<<b[kk].username<<endl<<b[kk].create_password<<endl<<b[kk].day<<endl<<b[kk].month<<endl<<b[kk].year<<endl<<b[kk].gender<<endl<<b[kk].petname<<endl<<b[kk].colour<<endl<<b[kk].recoverymail<<endl<<b[kk].mobile_number<<endl<<b[kk].country<<endl<<b[kk].fpath;
							}
							fout.close();
							cout<<"Redirecting to Login Page"<<endl;
							Sleep(1000*60*0.05);
							system("cls");
							goto sym;
					}
				else if(count==0)
				{
					system("cls");
						
newpass:					b[i].create_password=passwordInsert(b[i].create_password,b[i].username);
							b[i].confirm_password=b[i].create_password;
							cout<<"\nPassword has been changed";
							//cout<<"\nLOGGED IN";
							count=0;
							ofstream fout("f1.txt");
							m=m-1;
							for(int kk=0;kk<m;kk++)
							{
								fout<<endl<<b[kk].Firstname<<endl;
								fout<<b[kk].lastname<<endl;
								fout<<b[kk].username<<endl;
								fout<<b[kk].create_password<<endl;
								fout<<b[kk].day<<endl;
								fout<<b[kk].month<<endl;
								fout<<b[kk].year<<endl;
								fout<<b[kk].gender<<endl;
								fout<<b[kk].petname<<endl;
								fout<<b[kk].colour<<endl;
								fout<<b[kk].recoverymail<<endl;
								fout<<b[kk].mobile_number<<endl;
								fout<<b[kk].country<<endl;
								fout<<b[kk].fpath;
							}
							fout.close();
							cout<<"Redirecting to Login Page"<<endl;
							Sleep(1000*60*0.05);
							system("cls");
							goto sym;
				}


				}
				else
				{
		ch:			system("cls");
					cout<<"\nEnter your option \n1)try again   \n2)forgot password   :";
					cin>>temp;
					switch(temp)
					{
					case 1:goto am;
						break;
					case 2:
						system("cls");
				ma:		cout<<"\nEnter your option  \n1)Answer questions  \n2)recovery mail\n3. OTP Through Mobile Number";
						cin>>var;
						switch(var)
						{
						case 1:cout<<"\n\nEnter your first pet name";
							cin>>aa;
							if(b[i].petname==aa)
							{
							//	cout<<"\n\nenter your new password";
							//cin>>newpass;
								b[i].create_password=passwordInsert(b[i].create_password,b[i].username);
							cout<<"\nPassword has been changed";
							ofstream fout("f1.txt");
							for(int kk=0;kk<m-1;kk++)
							{
								fout<<b[kk].Firstname<<"\n"<<b[kk].lastname<<"\n"<<b[kk].username<<"\n"<<b[kk].create_password<<"\n"<<b[kk].day<<"\n"<<b[kk].month<<"\n"<<b[kk].year<<"\n"<<b[kk].gender<<"\n"<<b[kk].petname<<"\n"<<b[kk].colour<<"\n"<<b[kk].recoverymail<<"\n"<<b[kk].mobile_number<<"\n"<<b[kk].country<<"\n"<<b[kk].fpath<<endl;
							}
							fout.close();
							cout<<"\n\nRedirecting to Login Page"<<endl;
							Sleep(1000*60*0.05);
							system("cls");
							goto sym;
							}
							else
							{
								cout<<"\n\nWrong answer";
								goto ma;
							}
							break;
						case 2:
							for(j=0;j<m;j++)
								if(b[i].recoverymail==b[j].username)
								{
									temp=i;
									i=j;
									cout<<"\n\nYour recovery mail is "<<b[i].username<<"\n";;
									count++;
									goto am;
									break;
								}
						case 3:
							int ch;
							cout<<"\nSend an OTP to file path ?  Yes(1)  No(2)  ->   ";
							cin>>ch;
							if(ch==1)
							{
								cout<<"\nSending OTP to "<<b[i].fpath<<endl;
								Sleep(1000*60*0.05);
								b[i].fpath=b[i].fpath;
								string cccc;
								cccc=b[i].fpath+"//opt.txt";
								ofstream otp(cccc);
							//	int a=rand()%50*rand()%30,otp1;
								int a=clock(),otp1;
								otp<<a<<endl;
								otp.close();
								cout<<"Enter the OTP HERE --->>  ";
								cin>>otp1;
								if(otp1==a)
								{
									ofstream otp(b[i].fpath);
									otp.close();
									goto newpass;
								}
								else{
									ofstream otp(b[i].fpath);
									otp.close();
									cout<<"OTP INCORRECT"<<endl;
									goto ma;
								}
							}
							else if(ch==2)
							{
								goto ma; 
							} break;
						default: cout<<"Invalid Entry"<<endl; system("pause");goto ma;
					}
						default: cout<<"Invalid Entry"<<endl; system("pause");goto ch;
					
				}
			}
		}
		
		}
		if(flag==0)
		{
			cout<<"\nUSERNAME NOT FOUND";
			goto an;
		}
		cout<<"\n\n";
		system("pause");
}

int main()
{
	int a, b, c, d;
//	cout<<"-------------------Welcome to GMAIL----------------------"<<endl;
	
	while(1)
	{
		system("cls");
		cout<<"-------------------Welcome to GMAIL----------------------"<<endl;
		cout<<"\n\n         1- Create Account  2- Sign in  3-Exit                \n\n "<<endl; 
		cin>>a;
		if(a==1)
		{
		user u;
		u.createAccount();
		goto signin;
		}
		else if(a==2)
		{
	signin:		valid();
		}
		else if(a==3)
		{
			return 0;
		}
		else{
			cout<<"Invalid Entry"<<endl;
			system("pause");
		}
	}
	system("pause");

}