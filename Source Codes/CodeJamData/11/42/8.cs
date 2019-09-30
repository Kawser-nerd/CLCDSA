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
				string [] s = cin.ReadLine().Split(' ');
				int R = Convert.ToInt32(s[0]);
				int C = Convert.ToInt32(s[1]);
				int D = Convert.ToInt32(s[2]);
				
				for (int i = 0; i < R; i++)
				{
					string S = cin.ReadLine();
					for (int j = 0; j < C; j++)
						A[i, j] = S[j] - '0' + D;
				}
				B[0, 0] = A[0, 0];
				X[0, 0] = 0;
				Y[0, 0] = 0;
				for (int i = 1; i < R; i++)
				{
					B[i, 0] = B[i - 1, 0] + A[i, 0];
					X[i, 0] = X[i - 1, 0] + A[i, 0] * i;
					Y[i, 0] = 0;
				}
				for (int i = 1; i < C; i++)
				{
					B[0, i] = B[0, i - 1] + A[0, i];
					X[0, i] = 0;
					Y[0, i] = Y[0, i - 1] + A[0, i] * i;
				}
				for (int i = 1; i < R; i++)
					for (int j = 1; j < C; j++)
					{
						B[i, j] = B[i - 1, j] + B[i, j - 1] - B[i - 1, j - 1] + A[i, j];
						X[i, j] = X[i - 1, j] + X[i, j - 1] - X[i - 1, j - 1] + A[i, j] * i;
						Y[i, j] = Y[i - 1, j] + Y[i, j - 1] - Y[i - 1, j - 1] + A[i, j] * j;
					}
				bool f = false;
				for (int K = Math.Min(R, C) - 1; K >= 2; K--)
				{
					if (f) break;
					for (int i = 0; i < R; i++)
					{
						if (f) break;
						for (int j = 0; j < C; j++)
							if (i + K < R && j + K < R)
							{
								if (f) break;
								int M = B[i + K, j + K];
								double x = X[i + K, j + K];
								double y = Y[i + K, j + K];
								if (j > 0)
								{
									M -= B[i + K, j - 1];
									x -= X[i + K, j - 1];
									y -= Y[i + K, j - 1];
								}
								if (i > 0)
								{
									M -= B[i - 1, j + K];
									x -= X[i - 1, j + K];
									y -= Y[i - 1, j + K];
								}
								if (i > 0 && j > 0)
								{
									M += B[i - 1, j - 1];
									x += X[i - 1, j - 1];
									y += Y[i - 1, j - 1];
								}
								M -= A[i, j] + A[i + K, j] + A[i, j + K] + A[i + K, j + K];
								x -= A[i, j] * i + A[i + K, j] * (i + K) + A[i, K + j] * i + A[i + K, j + K] * (i + K);
								y -= A[i, j] * j + A[i + K, j] * j + A[i, K + j] * (j + K) + A[i + K, j + K] * (j + K);
								x /= M;
								y /= M;
								if ( Math.Abs(x - i - 0.5 * K) < 1e-6)
									if (Math.Abs(y - j - 0.5 * K) < 1e-6)
									{
										cout.WriteLine("Case #{0}: {1}", testCase, K + 1);
										f = true;
										break;
									}
							}
					}
				}
				if (!f)
					cout.WriteLine("Case #{0}: {1}", testCase, "IMPOSSIBLE");
			}
		}
		int[,] A = new int[505, 505];
		int[,] B = new int[505, 505];
		int[,] X = new int[505, 505];
		int[,] Y = new int[505, 505];
		TextReader cin;
		TextWriter cout;
	}
	class Program
	{
		static void Main(string[] args)
		{
			Solution.Run("B-small-attempt0 (1).in");
		}
	}
}
