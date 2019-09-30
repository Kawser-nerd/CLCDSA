using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemC
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\c.in");
		//		TextReader sr = Console.In;
				TextReader sr = new StreamReader(@"c:\temp\c-small-attempt0.in");
		//		TextReader sr = new StreamReader(@"c:\temp\c-large.in");
				TextWriter sw = new StreamWriter(@"c:\temp\c.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

    private static int xsize, ysize;
    private static int[,] map;
//    private static bool[,] mine;
    private static int best, middleRowCount, middleRow, lastRow;

	private static void Solve(TextReader sr, TextWriter sw)
	{
	    string[] split = sr.ReadLine().Split(' ');
	    ysize = int.Parse(split[0]);
	    xsize = int.Parse(split[1]);
        map = new int[ysize,xsize];
//        mine = new bool[ysize,xsize];
	    best = -1;
	    middleRowCount = 0;
	    middleRow = ysize/2;
	    lastRow = ysize - 1;
	    for (int i = 0; i < ysize; i++)
	    {
	        string[] split1 = sr.ReadLine().Split(' ');
	        for (int j = 0; j < xsize; j++)
	        {
	            map[i, j] = int.Parse(split1[j]);
	        }
	    }

	    Go(0, 0);
	    sw.WriteLine(best);
	}

    private static void Go(int x, int y)
    {
        if (x == xsize)
        {
            if (IsDone(x - 1, y - 1) && (y != lastRow || IsDone(x - 1, y)))
                Go(0, y + 1);
            return;
        }
        if (y == ysize)
        {
            best = Math.Max(best, middleRowCount);
            return;
        }

        if (IsDone(x - 1, y - 1) && (y != lastRow || IsDone(x - 1, y)))
        {
            Go(x + 1, y);
        }

        if (AddMine(x, y, 1) && IsDone(x - 1, y - 1) && (y != lastRow || IsDone(x - 1, y)))
        {
            Go(x + 1, y);
        }
        AddMine(x, y, -1);
    }

    private static bool IsDone(int x, int y)
    {
        if (x < 0 || y < 0 || x >= xsize || y >= ysize)
            return true;
        return map[y, x] == 0;
    }

    private static bool AddMine(int x, int y, int dir)
    {
        if (y == middleRow)
            middleRowCount += dir;
        bool valid = true;
        for (int dx = 0; dx < 3; dx++)
        {
            for (int dy = 0; dy < 3; dy++)
            {
                int nx = x + dx - 1, ny = y + dy - 1;
                if (nx >= 0 && ny >= 0 && nx < xsize && ny < ysize)
                {
                    map[ny, nx] -= dir;
                    if (map[ny, nx] < 0)
                        valid = false;
                }
            }
        }
        return valid;
    }
}
