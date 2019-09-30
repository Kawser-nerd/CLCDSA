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
			K = 0;
			for (int i = 2; i < P; i++)
			{
				bool f = true;
				for (int j = 0; j < K; j++)
					if (i % prime[j] == 0)
					{
						f = false;
						break;
					}
				if (f)
					prime[K++] = i;
			}
			int T = Convert.ToInt32(cin.ReadLine());
			for (int testCase = 1; testCase <= T; testCase++)
			{
				Int64 N = Convert.ToInt64(cin.ReadLine());
				Int64 ans = N > 1 ? 1 : 0;
				for (int i = 0; i < K; i++)
				{
					Int64 X = prime[i];
					int p = 0;
					while (X <= N)
					{
						X *= prime[i];
						p++;
					}
					if (p < 2)
						break;
					ans += p - 1;
				}
				cout.WriteLine("Case #{0}: {1}", testCase, ans);
			}
		}

		const int P = 1000000;
		int K;
		int[] prime = new int[100000];
		TextReader cin;
		TextWriter cout;
	}
	class Program
	{
		static void Main(string[] args)
		{
			Solution.Run("C-large.in");
		}
	}
}
