// made by diver_ru, made with love
using System;
using System.Collections;
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
		for (int i = 1; i <= cntCases; ++i)
		{
			Out.WriteLine("Case #{0}: {1}", i, getSmallest(In.ReadLine()));
		}

		In.Close();
		Out.Close();
	}

	private String getSmallest(string a)
	{
		for (int i = a.Length - 1; i >= -1; --i)
		{
			String s = can(a, i);
			if (s != null)
				return s;
		}
		return null;
	}

	private String can(string a, int pos)
	{
		int[] d = new int[10];
		StringBuilder res = new StringBuilder(a);
		for (int i = Math.Max(0, pos); i < a.Length; ++i)
			d[a[i] - '0']++;
		if (pos == -1)
		{
			res.Length = 0;
			++d[0];
			int f = 1;
			while (d[f] == 0)
				++f;
			res.Append(f);
			--d[f];
			for (int i = 0; i <= 9; ++i)
			{
				if (d[i] > 0)
					res.Append((char)(i + '0'), d[i]);
			}
			return res.ToString();
		}
		for (int i = a[pos] - '0' + 1; i <= 9; ++i)
		{
			if (d[i] == 0)
				continue;
			res[pos] = (char)(i + '0');
			d[i]--;
			int j = 0;
			for (int k = pos + 1; k < a.Length; ++k)
			{
				while (d[j] == 0)
					++j;
				--d[j];
				res[k] = (char)(j + '0');
			}
			return res.ToString();
		}
		return null;
	}

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		new Solver().Solve();
	}
	// END CUT HERE
}
