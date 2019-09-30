using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    private static StreamReader reader;

    static List<int> products(List<int> x)
    {
        List<int> res = new List<int> ();
        foreach (int q in Enumerable.Range(0, 8))
        {
            int prod = 1;
            foreach (int id in Enumerable.Range(0, 3))
                if ((q & (1 << id)) > 0)
                    prod *= x[id];
            res.Add(prod);
        }
        return res;
    }

    static Random random;

    static string Solve()
    {
        string[] ss = reader.ReadLine().Split();
        int r = int.Parse(ss[0]), m = int.Parse(ss[2]);

        string res = "\n";
        foreach (int c in Enumerable.Range(0, r))
        {
            List<int> a = reader.ReadLine().Split().Select(t => int.Parse(t)).ToList();
            List<List<int>> cand = new List<List<int>> ();

            foreach (int i in Enumerable.Range(2, m - 1))
                for (int j = i; j <= m; j++)
                    for (int l = j; l <= m; l++)
                    {
                        List<int> x = new List<int> (){i, j, l};
                        List<int> prd = products(x);
                        if (a.All(y => prd.Count(z => z == y) > 0))
                            cand.Add(x);
                    }

            if (cand.Count > 0)
                res += string.Join("", cand[random.Next(0, cand.Count)]);
            res += "\n";
        }
        return res;
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);
        random = new Random();

        foreach (int i in Enumerable.Range(1, int.Parse(reader.ReadLine())))
            Console.Write("Case #{0}: {1}", i, Solve());
    }
}
