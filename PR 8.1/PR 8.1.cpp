// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ... 
// 1. Визначити число входжень в послідовність групи букв “abc”.
// 2. Замінити кожну групу букв “abc” парою зірочок “ * *”

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(const char* s, const char* cs)
{
	int count = 0;
	int j, k;
	for (int i = 0; s[i] != '\0'; i++)
	{
		j = 0;
		k = i;
		while (cs[j] != '\0')
		{
			if (s[k] == cs[j] && s[k] != '\0')
			{
				j++;
				k++;
			}
			else
				break;
		}
		if (cs[j] == '\0')
			count++;
	}
	return count;
}
char* Change(char* s)
{
	size_t len = strlen(s);
	if (len < 3)
		return s;
	char* tmp = new char[len * 3/3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
	while (i < len && s[i+2] != 0)
	{
		if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c')
		{  
			strcat(t, "***");
			t += 3;
			i += 3;
		}
		else
		{
			*t++ = s[i++];
			*t = '\0';
		}
	}
	*t++ = s[i++];
	*t++ = s[i++];
	*t = '\0';
	strcpy(s, tmp);
	return tmp;
}

int main()
{
	char s[101];
	char cs[] = "abc";
	cout << "Enter string:" << endl;
	cin.getline(s, 100);
	cout << "String contained " << Count(s, cs) << " groups of 'abc'" << endl;
	char* dest = new char[151];
	dest = Change(s);
	cout << "Modified string (param) : " << s << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}