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

		int HOD(int a, int b)
		{
			if (a % b == 0)
				return b;
			return HOD(b, a % b);
		}

		void Solve()
		{
			int T = Convert.ToInt32(cin.ReadLine());
			for (int testCase = 1; testCase <= T; testCase++)
			{
				string[] s = cin.ReadLine().Split(' ');
				Int64 N = Convert.ToInt64(s[0]);
				int D = Convert.ToInt32(s[1]);
				int G = Convert.ToInt32(s[2]);
				if ((D != 100 && G == 100) || (D != 0 && G == 0))
				{
					cout.WriteLine("Case #{0}: Broken", testCase);
					continue;
				}
				int K = 100;
				int Q = HOD(D, K);
				D /= Q;
				K /= Q;
				if (K <= N)
					cout.WriteLine("Case #{0}: Possible", testCase);
				else
					cout.WriteLine("Case #{0}: Broken", testCase);
			}
		}

		TextReader cin;
		TextWriter cout;
	}
	class Program
	{
		static void Main(string[] args)
		{
			Solution.Run("A-large.in");
		}
	}
}
