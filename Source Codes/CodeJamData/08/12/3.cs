/*
 * Created by SharpDevelop.
 * User: Tim
 * Date: 7/25/2008
 * Time: 10:00 PM
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.IO;

namespace ProblemB
{
	class Program
	{
		public string getResult(int n, int m, List<int>[] unmalted, List<int>[] malted)
		{
			bool[] malt = new bool[n + 1];
			bool cont = true;
			for (int k = 0; k < 2 * n; k++)
			{
				for (int i = 0; i < m; i++) {
					if (unmalted[i].Count == 0 && malted[i].Count == 0)
						return "IMPOSSIBLE";
					if (unmalted[i].Count == 0 && !malt[malted[i][0]])
					{
						int mm = malted[i][0];
						malt[mm] = true;
						for (int j = 0; j < m; j++)
							if (unmalted[j].Contains(mm))
								unmalted[j].Remove(mm);
						break;
					}
				}
			}
			string ret = "";
			for (int i = 1; i < malt.Length; i++)
				ret += malt[i] ? "1 " : "0 ";
			return ret;
		}
		
		public static void Main(string[] args)
		{
		StreamReader input = File.OpenText(@"F:\b-large.in");
		StreamWriter output = File.CreateText(@"F:\b-large.out");
		int c = Convert.ToInt32(input.ReadLine());
		for (int i = 1; i <= c; i++)
		{
			int n = Convert.ToInt32(input.ReadLine());
			int m = Convert.ToInt32(input.ReadLine());
			List<int>[] unmalted = new List<int>[m];
			List<int>[] malted = new List<int>[m];
			for (int j = 0; j < m; j++)
			{
				unmalted[j] = new List<int>();
				malted[j] = new List<int>();
				string[] s = input.ReadLine().Split(' ');
				int k = Convert.ToInt32(s[0]);
				for (int x = 0; x < k; x++)
				{
					int y = Convert.ToInt32(s[x * 2 + 1]);
					if (s[x * 2 + 2].Equals("1"))
						malted[j].Add(y);
					else
						unmalted[j].Add(y);
				}
			}
			Program test = new Program();
			string ret = test.getResult(n, m, unmalted, malted);
			output.WriteLine("Case #" + i + ": " + ret);
		}
		input.Close();
		output.Close();
		}
	}
}
