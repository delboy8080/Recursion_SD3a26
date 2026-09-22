#include <iostream>

using namespace std;

void question1();

int main()
{
	question1();
}

bool isPalindrome(string &s, int n = 0)
{
	if (n > s.length()/2)
	{
		return true;
	}
	if (s[n] != s[s.size()- n - 1])
		return false;
	return isPalindrome(s, n+1);
}

void question1()
{
	const int size = 7;
	string words[size] = {"level", "navan", "cavan", "derek", "deed", 
		"racecar", "gohangasalamiimalasagnahog"};
	for (int i = 0; i < size;i++)
	{
		cout << words[i] << ": " << (isPalindrome(words[i]) ? "yes" : "No") 
			<< endl;
	}
}