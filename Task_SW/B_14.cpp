#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void hacker(vector<string> &partsPass, vector<string> &Password);
bool compare_string(const string &a, const string &b);

int main()
{
	vector<string> partsPass;
	vector<string> Password;
	int n;
	string s;


	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin>>s;
		partsPass.push_back(s);
	};

	hacker(partsPass, Password);

	for(int i = 0; i < 3; ++i)
	{
		cout << Password[i] << endl;
	}
	return 0;
};

bool compare_string(const string &a, const string &b)
{
	string s1 ;
	s1.append(a).append(b);
	string s2;
	s2.append(b).append(a);
	return s1 < s2; 
}

void hacker(vector<string> &partsPass, vector<string> &Password)
{
	string s;
	sort(partsPass.begin(), partsPass.end(), compare_string);
	for(int i = 0; i < partsPass.size(); ++i)
	{
		s.append(partsPass[i]);
	};
	Password.push_back(s);

	s = "...";
	Password.push_back(s);
	s.erase();

	sort(partsPass.rbegin(), partsPass.rend(), compare_string);

	for(int i = 0; i < partsPass.size(); i++)
	{
		s.append(partsPass[i]);
	};
	Password.push_back(s);

}