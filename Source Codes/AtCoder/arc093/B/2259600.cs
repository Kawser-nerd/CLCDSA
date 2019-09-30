using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitiveProgCsLib
{
	class MainProg
	{
		static string R => Console.ReadLine();
		static int RI => int.Parse(R);
		static double RD => double.Parse(R);
		static int[] RIs => R.Split(' ').Select(int.Parse).ToArray();
		static double[] RDs => R.Split(' ').Select(double.Parse).ToArray();
		static void Out(object obj) => Console.WriteLine(obj);
		static void Outb(bool b) => Out(b ? "Yes" : "No");
		static void OutB(bool b) => Out(b ? "YES" : "NO");

		static void Main(string[] args)
		{
			var a = RIs;
			if (a[0] == 1 || a[1] == 1)
			{
				char[][] map = (new char[100][]).Select(x => new char[100]).ToArray();
				for (int i = 0;i < 100;i++)
				{
					for(int j = 0;j < 100;j++)
					{
						map[i][j] = (a[0] == 1) ? '.' : '#';
					}
				}
				char cc = (a[0] == 1) ? '#' : '.';
				int count = 0;
				int f = (a[0] == 1) ? a[1] : a[0];
				for (int i = 0;i < 100;i += 2)
				{
					for(int j = 0;j < 100;j+= 2)
					{
						map[i][j] = cc;
						count++;
						if(count == f)
						{
							output(map);
							return;
						}
					}
				}
			}
			else
			{
				char[][] map = (new char[100][]).Select(x => new char[100]).ToArray();
				{
					for (int i = 0; i < 50; i++)
					{
						for (int j = 0; j < 100; j++)
						{
							map[i][j] = '.';
						}
					}
					char cc ='#';
					int count = 0;
					int f =a[1]-1;
					for (int i = 0; i < 100; i += 2)
					{
						for (int j = 0; j < 100; j += 2)
						{
							map[i][j] = cc;
							count++;
							if (count == f)
							{
								goto NEXT;
							}
						}
					}
				}
				NEXT:
				{
					for (int i = 50; i < 100; i++)
					{
						for (int j = 0; j < 100; j++)
						{
							map[i][j] = '#';
						}
					}
					char cc = '.';
					int count = 0;
					int f = a[0] - 1;
					for (int i = 51; i < 100; i += 2)
					{
						for (int j = 0; j < 100; j += 2)
						{
							map[i][j] = cc;
							count++;
							if (count == f)
							{
								output(map);
								return;
							}
						}
					}
				}
			}
		}

		static void output(char[][] str)
		{
			Out("100 100");
			for(int i = 0;i < str.Length;i++)
			{
				Out(new String(str[i]));
			}
		}
	}
}