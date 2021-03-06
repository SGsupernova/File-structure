#include "class_member.h"

using namespace std;

// an copy constructor of class "Member"
Member::Member(const string& id, const string& name, const string& phoneNumber, const string& address, const string& birthday, const string& email, const string& level, const string& password)
	: id(id), name(name), phoneNumber(phoneNumber), address(address), birthday(birthday), email(email), level(level), password(password) { }

// copy constructor
Member::Member(const Member& M) : id(M.id), name(M.name), phoneNumber(M.phoneNumber), address(M.address), birthday(M.birthday), email(M.email), level(M.level), password(M.password) { }

// an assignment operator
Member&  Member::operator = (const Member &M) {
   this->id				= M.id;
   this->name			= M.name;
   this->phoneNumber	= M.phoneNumber;
   this->address		= M.address;
   this->birthday		= M.birthday;
   this->email			= M.email;
   this->key			= M.key;
   this->level			= M.level;
   this->password		= M.password;

   return *this;
}

bool Member::operator ==(const Member &M) {
	if (id == M.id) return true;
	else			return false;
}

bool Member::operator !=(const Member &M) {
	if (id != M.id) return true;
	else			return false;
}

void Member::setId			(const string& id)		{ this->id = id; }
void Member::setName		(const string& name)	{ this->name = name; }
void Member::setPhoneNumber (const string& phoneNumber)	{ this->phoneNumber = phoneNumber; }
void Member::setAddress		(const string& address)	{ this->address = address; }
void Member::setBirthday	(const string& birthday){ this->birthday = birthday; }
void Member::setEmail		(const string& email)	{ this->email = email; }
void Member::setLevel		(const string& level)		{ this->level = level; }
void Member::setPassword	(const string& password){ this->password = password; }

istream& operator >> (istream& is, Member& M) {
	string str;
	
	is.exceptions(istream::failbit | istream::badbit);

	try {
		getline (is, str);
	} catch (istream::failure e) {
		return is;
	}

	istringstream iss (str);
	string token;


	getline (iss, token, '|');
	M.setId (token);

	getline (iss, token, '|');
	M.setName (token);

	getline (iss, token, '|');
	M.setPhoneNumber (token);

	getline (iss, token, '|');
	M.setAddress (token);

	getline (iss, token, '|');
	M.setBirthday (token);
	
	getline (iss, token, '|');
	M.setEmail (token);

	getline (iss, token, '|');
	M.setLevel (token);

	getline (iss, token, '|');
	M.setPassword (token);
	
	return is;
}

bool Member::isPassword (const string p) {
	if ((this->password).compare(p)) return false;
	else							 return true;
}

ostream& operator << (ostream& os, const Member& M) {
	os << "Member(ID, Name, Phone Number, Address, Birthday, E-mail, Level) : " << "(" << M.id;
	os << ", " << M.name;
	os << ", " << M.phoneNumber;
	os << ", " << M.address;
	os << ", " << M.birthday;
	os << ", " << M.email;
	os << ", " << M.level;
	os << ")";

	return os;
}

bool Member::Pack (IOBuffer & Buffer) const {
	int numBytes;

	Buffer.Clear ();

	numBytes = Buffer.Pack (id.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (name.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (phoneNumber.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (address.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (birthday.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (email.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (level.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (password.c_str());
	if (numBytes == -1) return false;

	return true;
}

bool Member::Unpack (IOBuffer & Buffer) {
	int numBytes;
	char buf[MEM_MAX_BUF];

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	id = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	name = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	phoneNumber = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	address = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	birthday = buf;
	
	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	email = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	level = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	password = buf;

	return true;
}

char* Member::Key() {
	key.assign (id);
	return (char*)(key.c_str());
}
