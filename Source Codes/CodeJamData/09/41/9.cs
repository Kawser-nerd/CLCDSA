// made by diver_ru, made with love
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

public class Solver
{
	TextWriter Out;
	TextReader In;

	int readInt()
	{
		return int.Parse(In.ReadLine());
	}

	private void Solve()
	{
		In = new StreamReader("../../input.txt");
		Out = new StreamWriter("../../output.txt");

		int cntCases = readInt();
		for (int k = 1; k <= cntCases; ++k)
		{
			
			int N = readInt();
			List<String> a = new List<String>();
			for (int i = 0; i < N; ++i)
			{
				a.Add(In.ReadLine());
			}
			int res = 0;
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < a.Count; ++j)
				{
					bool ok = true;
					for (int t = i + 1; t < N; ++t)
						if (a[j][t] == '1')
						{
							ok = false;
							break;
						}
					if (ok)
					{
						res += j;
						a.RemoveAt(j);
						break;
					}
				}
			}
			Out.WriteLine("Case #{0}: {1}", k, res);
		}

		In.Close();
		Out.Close();
	}

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		new Solver().Solve();
	}
	// END CUT HERE
}
