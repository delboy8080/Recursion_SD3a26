#include <iostream>

using namespace std;

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();

int main()
{
	srand(time(NULL));
	question7();
}

bool isPalindrome(string &s, int n = 0)
{
	if (n >= s.length()/2)
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

void findMinMax(int *arr, int size, int &min, int &max, int pos=0)
{
	if (pos == size)
		return;
	if (arr[pos] < min || pos ==0)
		min = arr[pos];
	if (arr[pos] > max || pos == 0)
		max = arr[pos];
	findMinMax(arr, size, min, max, pos + 1);
}

void print(int* arr, int size)
{
	for (int i = 0; i < size;i++)
	{
		if (i != 0)
			cout << ", ";
		cout << arr[i];
	}
	cout << endl;
}

void question2()
{
	srand(time(NULL));
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size;i++)
	{
		arr[i] = 1 + rand() % 20;
	}
	print(arr, size);
	int min = 0, max = 0;
	findMinMax(arr, size, min, max);
	cout << "Min: " << min << " & Max:" << max << endl;
}

string reverse(string &s, int n=0)
{
	if (s.length() == n)
		return "";
	return reverse(s, n+1) + s[n];
}

void question3()
{
	string word = "pots&pans";
	cout << word << " in reverse is " << reverse(word) << endl;
}

int stringToIntRec(string& s, int n = 0)
{
	if (n == s.size())
		return 0;
	return 10 * stringToIntRec(s, n + 1) 
		+ s[s.size() - n - 1] - '0';
}

void question4()
{
	cout << "Please enter a number: ";
	string num;
	cin >> num;
	cout << "As Integer: " << stringToIntRec(num) << endl;
}

int power(int x)
{
	if (x == 0)
		return 1;
	return 2 * power(x - 1);
}

void question5()
{
	for (int i = 0; i <= 10;i++)
	{
		cout << "2^" << i << " = " << power(i) << endl;
	}
}

void Hanoi(int n, int start, int destination, int open)
{
	if (n != 0)
	{
		Hanoi(n - 1, start, open, destination);
		cout << "Move Disc " << (char)(n + 64) << " From pillar "
			<< start << " to pillar " << destination << endl;
		Hanoi(n - 1, open, destination, start);
	}
}

void question6()
{
	Hanoi(3, 1, 3, 2);
}

void printForward(int* arr, int size, int n = 0)
{
	if (n == size)
	{
		cout << endl;
		return;
	}
	cout << arr[n] << ", ";
	printForward(arr, size, n+1);
}
void printReverse(int* arr, int size, int n = 0)
{
	if (n == size)
		return;
	
	printReverse(arr, size, n + 1);
	cout << arr[n] << ", ";
	if (n == 0)
		cout << endl;
}
void question7()
{
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 20;
	}
	print(arr, size);
	printForward(arr, size);
	printReverse(arr, size);
}