using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemB
{
	static void Main(string[] args)
	{
		//TextReader sr = new StreamReader(@"c:\temp\b.in");
        //TextReader sr = new StreamReader(@"c:\temp\b-small-attempt0.in");
        TextReader sr = new StreamReader(@"c:\temp\b-large.in");
        //		TextReader sr = Console.In;
		TextWriter sw = new StreamWriter(@"c:\temp\b.out");
		//TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
        var parts = sr.ReadLine().Split(' ');
        int N = int.Parse(parts[0]);
        int K = int.Parse(parts[1]);
        int B = int.Parse(parts[2]);
        int T = int.Parse(parts[3]);
        var x = sr.ReadLine().Split(' ').Select(t => int.Parse(t)).ToArray();
        var v = sr.ReadLine().Split(' ').Select(t => int.Parse(t)).ToArray();
        int done = 0, swaps = 0;
        for (int i = N - 1; i >= 0 && done < K; i--)
        {
            if (x[i] + v[i] * T >= B)
            {
                done++;
            }
            else
            {
                swaps += K - done;
            }
        }
        if (done == K)
        {
            sw.WriteLine(swaps);
        }
        else
        {
            sw.WriteLine("IMPOSSIBLE");
        }
	}
}
