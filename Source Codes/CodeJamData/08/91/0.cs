using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemA
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\a.in");
		//		TextReader sr = Console.In;
//				TextReader sr = new StreamReader(@"c:\temp\a-small-attempt0.in");
				TextReader sr = new StreamReader(@"c:\temp\a-large.in");
				TextWriter sw = new StreamWriter(@"c:\temp\a.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		    Console.WriteLine("done");
		}
		sw.Close();
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
	    int n = int.Parse(sr.ReadLine());
	    Req[] all = new Req[n];
	    HashSet<int> uA = new HashSet<int>();
	    
	    for (int i = 0; i < n; i++)
	    {
	        string[] split = sr.ReadLine().Split(' ');
	        all[i] = new Req {A = int.Parse(split[0]), B = int.Parse(split[1]), C = int.Parse(split[2])};
	        uA.Add(all[i].A);
	    }


	    /*n = 5000;
	    uA = new HashSet<int>();
	    all = new Req[n];
	    Random rnd = new Random(0);
	    for (int i = 0; i < n; i++)
	    {
	        all[i] = new Req();
	        all[i].A = rnd.Next(0, 3000);
	        all[i].B = rnd.Next(0, 3000);
	        all[i].C = rnd.Next(0, 3000);
	        uA.Add(all[i].A);
	    }*/

	    List<int> uniqueA = new List<int>(uA);
	    uniqueA.Sort();

	    int best = 0;
	    foreach (var a in uniqueA)
	    {
	        HashSet<int> uB = new HashSet<int>();
	        List<Req> aPassed = new List<Req>();
	        foreach(Req r in all)
            {
                if (r.A <= a)
                {
                    uB.Add(r.B);
                    aPassed.Add(r);
                }
            }
            if (aPassed.Count <= best)
                continue;

	        aPassed.Sort((x, y) => (x.B - y.B));
            
	        int currently = 0, lastC = 10000;
	        int[] cCount = new int[10001];

            foreach(var r in aPassed)
            {
                int b = r.B;
                int c = 10000 - a - b;
                if (r.C > c)
                    continue;
                currently++;
                cCount[r.C]++;
                while (lastC > c)
                {
                    currently -= cCount[lastC];
                    lastC--;
                }
                if (currently > best)
                    best = currently;
            }
	    }

	    sw.WriteLine(best);
	}

    private class Req
    {
        public int A, B, C;
    }
}
