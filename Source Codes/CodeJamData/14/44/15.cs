using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemD
{
	class Program
	{
		static int M;
		static int N;
		static int[] A;
		static List<string> S;
		static int MaxSum;
		static int MaxPerm;
		static void Main(string[] args)
		{
			using (var inp = new StreamReader(new FileStream("D.in", FileMode.Open, FileAccess.Read)))
			{
				using (var oup = new StreamWriter(new FileStream("D.out", FileMode.Create, FileAccess.Write)))
				{
					var line = inp.ReadLine();
					var n = int.Parse(line);
					for (int i = 0; i < n; i++)
					{
						line = inp.ReadLine();
						var parts = line.Split(' ').Select(x => int.Parse(x)).ToArray();
						M = parts[0];
						N = parts[1];
						S = new List<string>();
						for (int j = 0; j < M; j++)
						{
							string s = inp.ReadLine();
							S.Add(s);
						}
						A = new int[M];
						MaxSum = 0;
						MaxPerm = 0;
						Assign(0);
						oup.WriteLine("Case #" + (i + 1).ToString() + ": " + MaxSum + " " + MaxPerm);
					}
					oup.Close();
				}
			}
		}

		static void Assign(int SNo)
		{
			if (SNo >= M)
			{
				Check();
				return;
			}
			for (int i = 0; i < N; i++)
			{
				A[SNo] = i;
				Assign(SNo + 1);

			}
		}
		static void Check()
		{
			int Sum = 0;
			for (int t = 0; t < N; t++) // for every server
			{
				HashSet<string> HS = new HashSet<string>();
				for (int i = 0; i < M; i++) // for all strings 
					if (A[i] == t) // that belong to this server Add Substrings
					{
						for (int j = 1; j <= S[i].Length; j++)
							if (!HS.Contains(S[i].Substring(0, j)))
								HS.Add(S[i].Substring(0, j));
					}
				if (HS.Count == 0)
					return;
				Sum += HS.Count + 1;
			}
			if (Sum > MaxSum)
			{
				MaxSum = Sum;
				MaxPerm = 1;
			}
			else if (Sum == MaxSum)
				MaxPerm++;
		}
	}
}