#ifndef __CLASS_MEMBER__
#define __CLASS_MEMBER__

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../../include/packing/delim.h"

using namespace std;

#define LEN_BIRTHDAY 9
#define MEM_MAX_BUF 256

class Member {
	private:
		string	id;
		string	name;
		string	phoneNumber;
		string	address;
		string	birthday;
		string	email;
		string	key;
		string	level;

	public:
		// defualt 
		Member () { };
		Member (const string& id, const string& name, const string& phoneNumber, const string& address, const string& birthday, const string& email);
		// copy constructor
		Member (const Member& M);

		// operators (assignment, comparision)
		Member& operator = (const Member &M);
		bool	operator ==(const Member &M);
		bool	operator !=(const Member &M);

		// iostream operators
		friend istream& operator >> (istream& is, Member& M);
		friend ostream& operator << (ostream& is, const Member& M);

		// make member functions that set member variables.
		void setId			(const string& id);
		void setName		(const string& name);
		void setPhoneNumber (const string& address);
		void setAddress		(const string& address);
		void setBirthday	(const string& birthday);
		void setEmail		(const string& email);

		string getId() const { return id; };

		bool Pack (IOBuffer & Buffer) const;
		bool Unpack (IOBuffer & Buffer);
		char* Key();
};


#endif
