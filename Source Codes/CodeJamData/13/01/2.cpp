#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

bool checkX(vector <char> sets)
{
	for(int i = 0; i < sets.size(); i++)
		if(sets[i] == '.' || sets[i] == 'O')
			return false;
	return true;
}

bool checkO(vector <char> sets)
{
	for(int i = 0; i < sets.size(); i++)
		if(sets[i] == '.' || sets[i] == 'X')
			return false;
	return true;
}

void solve()
{
	string board[4];
	for(int i = 0; i < 4; i ++)
		cin >> board[i];
	bool XWin = false, OWin = false;
	for(int i = 0; i < 4; i++)
	{
		vector <char> cells;
		for(int j = 0; j < 4; j++)
			cells.push_back(board[i][j]);
		XWin |= checkX(cells);
		OWin |= checkO(cells);
	}
	for(int i = 0; i < 4; i++)
	{
		vector <char> cells;
		for(int j = 0; j < 4; j++)
			cells.push_back(board[j][i]);
		XWin |= checkX(cells);
		OWin |= checkO(cells);
	}
	{
		vector <char> cells;
		for(int j = 0; j < 4; j++)
			cells.push_back(board[j][j]);
		XWin |= checkX(cells);
		OWin |= checkO(cells);
	}
	{
		vector <char> cells;
		for(int j = 0; j < 4; j++)
			cells.push_back(board[j][3-j]);
		XWin |= checkX(cells);
		OWin |= checkO(cells);
	}
	if(XWin == true && OWin == false)
		cout << "X won" << endl;
	else if(XWin == false && OWin == true)
		cout << "O won" << endl;
	else 
	{
		int cnt = 0;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				cnt += (board[i][j] == '.');
		if(cnt == 0)
			cout << "Draw" << endl;
		else
			cout << "Game has not completed" << endl;
	}
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cout << "Case #" << CaseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}

