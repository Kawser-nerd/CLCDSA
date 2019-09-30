using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemD
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\d.in");
		TextReader sr = new StreamReader(@"c:\temp\d-small-attempt0.in");
		//		TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\d.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

    private static int n, k, p;
	private static void Solve(TextReader sr, TextWriter sw)
	{
	    string[] split = sr.ReadLine().Split(' ');
	    n = int.Parse(split[0]);
	    k = int.Parse(split[1]);
	    p = int.Parse(split[2]);
	    int startMask = (1 << k) - 1;
        if (p > n - 1)
            p = n - 1;
        memo = new int[n+1,1<<p];
	    int ans = Go(k, startMask);
	    sw.WriteLine(ans);
	}

    private const int MOD = 30031;

    private static int[,] memo;
    static int Go(int cur, int mask)
    {
        if (cur == n)
        {
            if (mask == (1<<k)-1)
                return 1;
            return 0;
        }
        if (memo[cur, mask] > 0)
            return memo[cur, mask] - 1;
        int sum = 0;
        for (int i = 0; i < p; i++)
        {
            if (((1<<i)&mask) > 0)
            {
                int nmask = mask - (1 << i);
                nmask *= 2;
                nmask++;
                if ((nmask & (1<<p)) == 0)
                {
                    sum += Go(cur + 1, nmask);
                    sum %= MOD;
                }
            }
        }
        memo[cur, mask] = sum + 1;
        return sum;
    }
}