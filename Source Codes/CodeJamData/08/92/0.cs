using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemB
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\b.in");
		//		TextReader sr = Console.In;
				TextReader sr = new StreamReader(@"c:\temp\b-small-attempt0.in");
		//		TextReader sr = new StreamReader(@"c:\temp\b-large.in");
				TextWriter sw = new StreamWriter(@"c:\temp\b.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

    private static bool[,] marked;
    private static int xsize, ysize, x1, y1, x2, y2;
	private static void Solve(TextReader sr, TextWriter sw)
	{
	    string[] split = sr.ReadLine().Split(' ');
	    xsize = int.Parse(split[0]);
	    ysize = int.Parse(split[1]);
        split = sr.ReadLine().Split(' ');
        x1 = int.Parse(split[0]);
        y1 = int.Parse(split[1]);
        split = sr.ReadLine().Split(' ');
        x2 = int.Parse(split[0]);
        y2 = int.Parse(split[1]);
        split = sr.ReadLine().Split(' ');
        int x0 = int.Parse(split[0]);
        int y0 = int.Parse(split[1]);
        marked = new bool[ysize,xsize];
	    int triggered = Go(x0, y0);

	    sw.WriteLine(triggered);
	}

    private static int Go(int x0, int y0)
    {
        if (x0 < 0 || y0 < 0 || x0 >= xsize || y0 >= ysize)
            return 0;
        if (marked[y0, x0])
            return 0;
        int sum = 1;
        marked[y0, x0] = true;
        sum += Go(x0 + x1, y0 + y1);
        sum += Go(x0 + x2, y0 + y2);
        return sum;
    }
}
