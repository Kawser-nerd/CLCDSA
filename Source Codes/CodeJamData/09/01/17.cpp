#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> words;

vector<string> split(string str)
{
    vector<string> retVal;
    for(int i = 0; i < str.size(); i++)
    {
	if(str[i] != '(') retVal.push_back(string(1, str[i]));
	else
	{
	    int next = str.find(")", i);
	    retVal.push_back(str.substr(i + 1, next - i - 1));
	    i = next;
	}
    }
    return retVal;
}

bool match(string a, vector<string> pat)
{
    if(a.size() != pat.size()) return false;
    for(int i = 0; i < a.size(); i++)
    {
	if(pat[i].find(a[i]) == string::npos)
	    return false;
    }
    return true;
}


int main()
{
    int L, D, N;
    cin >> L >> D >> N;
    for(int i = 0; i < D; i++)
    {
	string temp;
	cin >> temp;
	words.push_back(temp);
    }

    for(int i = 0; i < N; i++)
    {
	int ret = 0;
	string temp;
	cin >> temp;

	for(int j = 0; j < D; j++)
	    ret += match(words[j], split(temp));

	cout << "Case #" << i + 1 << ": " << ret << endl;
    }

    return 0;
}
