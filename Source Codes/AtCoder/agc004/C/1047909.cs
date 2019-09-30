using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;

using Pair = System.Collections.Generic.KeyValuePair<int, int>;

class Program
{
	public Program() { }

	static void Main(string[] args)
	{
		new Program().prog();
	}

	Scanner cin;

	const int MOD = 1000000007;
	const int INF = int.MaxValue - 10;
	const long INFL = long.MaxValue - 10;
	const double EPS = 1e-8;
	const double PI = 3.1415926536;
	int[,] dir8;
	int[,] dir4;



	void prog()
	{
		cin = new Scanner();
		dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		int H = cin.nextInt();
		int W = cin.nextInt();
		char[][] red = new char[H][];
		char[][] blue = new char[H][];

		for (int i = 0; i < H; i++)
		{
			string str = cin.next();
			red[i] = new char[W];
			blue[i] = new char[W];
			for (int j = 0; j < W; j++)
			{
				if (str[j] == '#')
				{
					red[i][j] = blue[i][j] = '#';
				}
				else
				{
					if (i % 2 == 0)
					{
						if (j != W - 1)
						{
							red[i][j] = '#';
							blue[i][j] = '.';
						}
						else
						{
							red[i][j] = '.';
							blue[i][j] = '#';
						}
					}
					else
					{
						if (j == 0)
						{
							red[i][j] = '#';
							blue[i][j] = '.';
						}
						else
						{
							red[i][j] = '.';
							blue[i][j] = '#';
						}
					}
				}
			}
		}
		for (int i = 0; i < H; i++)
		{
			Console.WriteLine(red[i]);
		}
		Console.WriteLine();
		for (int i = 0; i < H; i++)
		{
			Console.WriteLine(blue[i]);
		}
	}
}

class Scanner
{
	string[] s;
	int i;

	char[] cs = new char[] { ' ' };

	public Scanner()
	{
		s = new string[0];
		i = 0;
	}

	public string next()
	{
		if (i < s.Length) return s[i++];
		string st = Console.ReadLine();
		while (st == "") st = Console.ReadLine();
		s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
		i = 0;
		return next();
	}

	public int nextInt()
	{
		return int.Parse(next());
	}

	public long nextLong()
	{
		return long.Parse(next());
	}

	public double nextDouble()
	{
		return double.Parse(next());
	}
}