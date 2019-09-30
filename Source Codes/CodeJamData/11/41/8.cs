using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
	class Solution
	{
		Solution(string fileName)
		{
			cin = File.OpenText(fileName);
			cout = new StreamWriter(@"D:\codejam\" + "output.txt");
			//cin = Console.In;
			//cout = Console.Out;
		}

		void Close()
		{
			cin.Close();
			cout.Close();
		}

		static public void Run(string fileName)
		{
			Solution solution = new Solution(@"D:\codejam\" + fileName);
			solution.Solve();
			solution.Close();
		}

		void Solve()
		{
			int T = Convert.ToInt32(cin.ReadLine());
			for (int testCase = 1; testCase <= T; testCase++)
			{
				string[] s = cin.ReadLine().Split(' ');
				int X = Convert.ToInt32(s[0]);
				int S = Convert.ToInt32(s[1]);
				int R = Convert.ToInt32(s[2]);
				double t = Convert.ToInt32(s[3]);
				int N = Convert.ToInt32(s[4]);
				List<int> B = new List<int>();
				List<int> E = new List<int>();
				List<int> w = new List<int>();
				for (int i = 0; i < N; i++)
				{
					s = cin.ReadLine().Split(' ');
					B.Add(Convert.ToInt32(s[0]));
					E.Add(Convert.ToInt32(s[1]));
					w.Add(Convert.ToInt32(s[2]));
				}
				for (int i = 0; i < N; i++)
					for (int j = i + 1; j < N; j++)
						if (B[i] > B[j])
						{
							int q = B[i];
							B[i] = B[j];
							B[j] = q;
							q = E[i];
							E[i] = E[j];
							E[j] = q;
							q = w[i];
							w[i] = w[j];
							w[j] = q;
						}
				double CurPoint = 0;
				double TotalTime = 0;
				for (int i = 0; i < N; i++)
				{
					if (B[i] <= CurPoint + 1e-7)
						CurPoint = E[i];
					if (B[i] > CurPoint)
					{
						if ((double)(B[i] - CurPoint) / R < t)
						{
							TotalTime += (double)(B[i] - CurPoint) / R;
							t -= (double)(B[i] - CurPoint) / R;
							CurPoint = E[i];
						}
						else
						{
							CurPoint += t * R;
							TotalTime += t;
							t = 0;
							TotalTime += (double)(B[i] - CurPoint) / S;
							CurPoint = E[i];
						}
					}
				}
				if (CurPoint < X)
				{
					if ((double)(X - CurPoint) / R < t)
					{
						TotalTime += (double)(X - CurPoint) / R;
						t -= (double)(X - CurPoint) / R;
					}
					else
					{
						CurPoint += t * R;
						TotalTime += t;
						t = 0;
						TotalTime += (double)(X - CurPoint) / S;
					}
				}
				for (int i = 0; i < N; i++)
					for (int j = i + 1; j < N; j++)
						if (w[i] > w[j])
						{
							int q = B[i];
							B[i] = B[j];
							B[j] = q;
							q = E[i];
							E[i] = E[j];
							E[j] = q;
							q = w[i];
							w[i] = w[j];
							w[j] = q;
						}
				for (int i = 0; i < N; i++)
				{
					if ((double)(E[i] - B[i]) / (R + w[i]) < t)
					{
						t -= (double)(E[i] - B[i]) / (R + w[i]);
						TotalTime += (double)(E[i] - B[i]) / (R + w[i]);
					}
					else
					{
						double x = (double)B[i] + t * (R + w[i]);
						TotalTime += (double)t + (double)(E[i] - x) / (S + w[i]);
						t = 0;
					}
				}
				cout.WriteLine("Case #{0}: {1}", testCase, TotalTime.ToString("F09").Replace(',','.'));
			}
		}

		TextReader cin;
		TextWriter cout;
	}
	class Program
	{
		static void Main(string[] args)
		{
			Solution.Run("A-large (1).in");
		}
	}
}
