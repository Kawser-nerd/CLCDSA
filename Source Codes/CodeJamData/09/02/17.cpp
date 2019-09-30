#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

int map[100][100]; char ret[100][100];
int H, W;
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

int main()
{
    int T;
    cin >> T;
    for(int z = 1; z <= T; z++)
    {
	cin >> H >> W;
	for(int i = 0; i < H; i++)
	    for(int j = 0; j < W; j++)
	    {
		cin >> map[i][j];
		ret[i][j] = '-';
	    }

	char let = 'a';
	for(int i = 0; i < H; i++)
	    for(int j = 0; j < W; j++)
	    {
		bool basin = true;
		for(int k = 0; k < 4; k++)
		{
		    int ni = i + di[k], nj = j + dj[k];
		    if(ni < 0 || ni >= H || nj < 0 || nj >= W) 
			continue;
		    if(map[ni][nj] < map[i][j])
		    {
			basin = false;
			break;
		    }
		}
		    
		if(basin)
		{
		    assert(let <= 'z');
		    ret[i][j] = let++;
		}
	    }

	for(int i = 0; i < H; i++)
	    for(int j = 0; j < W; j++)
	    {
		int ci = i, cj = j, minVal = 999999999, minK;
		while(ret[ci][cj] == '-')
		{
		    for(int k = 0; k < 4; k++)
		    {
			int ni = ci + di[k], nj = cj + dj[k];
			if(ni < 0 || ni >= H || nj < 0 || nj >= W) 
			    continue;

			if(map[ni][nj] < minVal)
			{
			    minVal = map[ni][nj];
			    minK = k;
			}
		    }
		    ci += di[minK]; cj += dj[minK];
		}

		ret[i][j] = ret[ci][cj];
	    }

	let = 'a';
	char relabel[26];
	memset(relabel, 0, sizeof relabel);
	for(int i = 0; i < H; i++)
	    for(int j = 0; j < W; j++)
	    {
		assert(ret[i][j] != '-');
		if(relabel[ret[i][j] - 'a'] == 0)
		    relabel[ret[i][j] - 'a'] = let++;
	    }

	for(int i = 0; i < H; i++)
	    for(int j = 0; j < W; j++)
	    {
		assert(relabel[ret[i][j] - 'a'] != 0);
		ret[i][j] = relabel[ret[i][j] - 'a'];
	    }

	cout << "Case #" << z << ":" << endl;
	for(int i = 0; i < H; i++)
	{
	    for(int j = 0; j < W; j++)
	    {
		if(j > 0) cout << " ";
		cout << ret[i][j];
	    }
	    cout << endl;
	}
    }
}
