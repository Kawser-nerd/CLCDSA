using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemE
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\e.in");
		//		TextReader sr = Console.In;
				TextReader sr = new StreamReader(@"c:\temp\e-small-attempt0.in");
		//		TextReader sr = new StreamReader(@"c:\temp\e-large.in");
				TextWriter sw = new StreamWriter(@"c:\temp\e.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		    Console.WriteLine("done " + caseNo);
		}
		sw.Close();
	}

    private static int xsize, ysize;
    private static string[] cal;
    private static int[,,] memo;

	private static void Solve(TextReader sr, TextWriter sw)
	{
	    string[] split = sr.ReadLine().Split(' ');
	    ysize = int.Parse(split[0]);
	    xsize = int.Parse(split[1]);
        cal = new string[ysize];
	    for (int i = 0; i < ysize; i++)
	    {
	        cal[i] = sr.ReadLine();   
	    }

        memo = new int[1<<(xsize+1),xsize,ysize];
	    int val = Go(0, 0, 0);
	    sw.WriteLine(val);
	}

    private static int Go(int mask, int x, int y)
    {
        if (y == ysize)
            return 0;
        bool prevDayContest = (mask & (1 << xsize)) > 0;
        bool prevMonthContest = (mask & (1 << x)) > 0;
        int newMask = mask & ~(1 << x) & ~(1 << xsize);
        if (x == xsize)
            return Go(newMask, 0, y + 1);

        if (memo[mask, x, y] > 0)
            return memo[mask, x, y] - 1;

        int best = 0;
        if (cal[y][x] != '.')
        {
            // Assume contest
            int val = 4;
            if (prevDayContest) val -= 2;
            if (prevMonthContest) val -= 2;
            int nv = Go(newMask | (1 << x) | (1 << xsize), x + 1, y) + val;
            best = Math.Max(best, nv);
        }
        if (cal[y][x] != '#')
        {
            // Assume no contest
            int nv = Go(newMask, x+1, y);
            best = Math.Max(best, nv);
        }

        memo[mask, x, y] = best + 1;
        return best;
    }
}