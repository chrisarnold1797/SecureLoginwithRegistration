#include <Windows.h> // For Windows, can comment out for linux compilers
#include "bcrypt.h" // Include the Bcrypt.cpp library
#include<iostream>
#include<fstream>
#include<string>

std::string usn;

int tm;

void valid(std::string str)
{
	std::string dir, user;
	std::ifstream file;
	dir = str+".txt";
	file.open(dir.c_str());
	if(!file.is_open() && file.fail())
	{
		//file.close();
		return;
	}
	else
	{
		::tm++;
		if(::tm==3)
		{
			std::cout<<"\nTHis username already exists\n Please try again.";
			//file.close()
			return;
		}
		std::cout<<"\nThis username already exists\nCreate a username:";
		std::cin>>usn;
		//file.close();
		valid(usn);
	}
}

int main()
{
	int choice,i,exit=0;
	std::string ans,psd,name,fname,bio,usern,pw,line,nusn,salt;
	std::ofstream fileo;
	std::ifstream filei;
	std::cout<<"------------------------------------Welcome to our system-----------------------------------\n";
	while(exit==0)
	{
		std::cout<<"\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
		std::cin>>choice;
		if(choice==1)
		{
			std::cout<<"Enter your username:";
			std::cin>>usn;
			std::cout<<"Enter your password:";
			std::cin>>psd;
			fname=usn+".txt";
			filei.open(fname.c_str());
			if(!filei.is_open() && filei.fail())
			{
				std::cout<<"\nYou are not registered, please register before logging in.\n";
				filei.close();
				continue;
			}
			getline(filei,usern);
			getline(filei,line);
			getline(filei,pw);
			std::string storedHash = pw;
			std::string password = psd;
			bool isValid = bcrypt::validatePassword(psd, pw);
			if(usn==usern && isValid)
			{
				std::cout<<"\nYou are successfully logged in:)\nYOUR PROFILE SAYS:\n";
				std::cout<<"Username:"<<usern<<std::endl;
				std::cout<<"Name:"<<line<<std::endl;
				getline(filei,line);
				std::cout<<"Bio:"<<line<<std::endl;
				filei.close();
			}
			else
			{
				std::cout<<"\nWrong username or password!\nPlease try again.\n";
			}
			std::cout<<std::endl;
		}
		else if(choice==2)
		{
			std::cout<<"\nEnter your name:";
			std::cin.ignore();
			std::getline(std::cin,name);
			std::cout<<"\nCreate a username:";
			std::cin>>usn;
			tm=0;
			valid(usn);
			if(tm>=3)
			{
				continue;
			}
			std::cout<<"\nCreate a password:";
			std::cin>>psd;
			std::string hash = bcrypt::generateHash(psd);
			fname=usn+".txt";
			//cout<<fname;
			fileo.open(fname.c_str());
			fileo<<usn<<std::endl<<name<<std::endl<<hash<<std::endl;
			std::cout<<"\nYou are successfully registered:)";
			std::cout<<"\nAdd to your bio and press enter when you are done.";
			std::cin.ignore();
			std::getline(std::cin,bio);
			fileo<<bio<<std::endl;
			std::cout<<"\nYour bio is saved as: "<<bio;
			fileo.close();
		}
		else
		{
			exit=1;
		}
	}
	std::cout<<"\n---------------------------------Thank you for visiting:)----------------------------------\n";
}
