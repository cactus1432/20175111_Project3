#include <iostream>
#include <cstring> //strcpy,strcmp
using namespace std;

class String
{
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	bool operator==(const String& str)const
	{
		return strcmp(_chars, str._chars) == 0; //true
	}
	bool operator>(const String& str)const
	{
		return strcmp(_chars, str._chars) > 0; //true
	}
	bool operator<=(const String& str)const
	{
		return strcmp(_chars, str._chars) <= 0; //true
	}
};

int main()
{
	string str0{ "abc" };
	string str1{ "cde" };

	if (str0 == str1)//str0.operator==(str1)
		cout << "equal" << endl;
	if (str0 > str1)//str0.operator>(str1)
		cout << "str0>str1" << endl;
	if (str0 <= str1)//str0.operator<=(str1)
		cout << "str0<=str1" << endl;
}