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
		TextReader sr = new StreamReader(@"c:\temp\b-large.in");
//		TextReader sr = new StreamReader(@"c:\temp\b-small-attempt0.in");
		//		TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\b.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
            Console.WriteLine("Case #" + caseNo + ": ");
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
	    int n = int.Parse(sr.ReadLine());
	    Dictionary<string, int> colorMap = new Dictionary<string, int>();
	    List<List<Offer>> offers = new List<List<Offer>>();
	    for (int i = 0; i < n; i++)
	    {
	        string[] split = sr.ReadLine().Split(' ');
            if (!colorMap.ContainsKey(split[0]))
            {
                colorMap.Add(split[0], colorMap.Count);
                offers.Add(new List<Offer>());
            }
	        int c = colorMap[split[0]];
	        var offer = new Offer(int.Parse(split[1]) - 1, int.Parse(split[2]), c);
	        offers[c].Add(offer);
	    }

	   /* Random r = new Random(0);
	    offers = new List<List<Offer>>();
	    for (int i = 0; i < 30; i++)
	    {
	        offers.Add(new List<Offer>());
            for (int j = 0; j < 10; j++)
            {
                int a = r.Next(0, 10001);
                int b = r.Next(0, 10001);
                if (j == 0) a = 0;
                if (j == 99) b = 10000;
                offers[i].Add(new Offer(Math.Min(a, b), Math.Max(a, b), i));
            }
	    }*/

        while (offers.Count < 3)
            offers.Add(new List<Offer>());
        for (int i = 0; i < offers.Count; i++)
        {
            offers[i].Sort();
            offers[i].Add(new Offer(20000, 20000, i));
        }

	    int best = int.MaxValue;
	    for (int ca = 0; ca < offers.Count; ca++)
	    {
	        for (int cb = ca + 1; cb < offers.Count; cb++)
	        {
	            for (int cc = cb + 1; cc < offers.Count; cc++)
	            {
	                int req = 0;
	                int pa = 0, pb = 0, pc = 0, pos = 0;
	                int la = 0, lb = 0, lc = 0;
                    while (pos < 10000)
                    {
                        while (offers[ca][pa].A <= pos)
                            la = Math.Max(la, offers[ca][pa++].B);
                        while (offers[cb][pb].A <= pos)
                            lb = Math.Max(lb, offers[cb][pb++].B);
                        while (offers[cc][pc].A <= pos)
                            lc = Math.Max(lc, offers[cc][pc++].B);
                        int v = Math.Max(la, Math.Max(lb, lc));
                        if (v <= pos)
                            break;
                        req++;
                        pos = v;
                    }
                    if (pos == 10000)
	                    best = Math.Min(best, req);
	            }
	        }
	    }
        if (best == int.MaxValue)
            sw.WriteLine("IMPOSSIBLE");
	    else
            sw.WriteLine(best);
	}

    private class Offer : IComparable<Offer>
    {
        public int A, B, Color;

        public Offer(int a, int b, int color)
        {
            A = a;
            B = b;
            Color = color;
        }

        public int CompareTo(Offer other)
        {
            if (A != other.A)
                return A - other.A;
            return B - other.B;
        }
    }
}
