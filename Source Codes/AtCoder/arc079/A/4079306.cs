using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        long[] nm = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long n = nm[0];
        long m = nm[1];

        List<long> previousroute = new List<long>();
        List<long> nextroute = new List<long>();

        for (long i = 0; i < m; i++)
        {
            string[] s = Console.ReadLine().Split();
            long a = long.Parse(s[0]);
            long b = long.Parse(s[1]);
            
            if (a == 1)
            {
                previousroute.Add(b);
            }

            if (b == n)
            {
                nextroute.Add(a);
            }
        }

        long[] cross = nextroute.ToArray();
        Array.Sort(cross);

        foreach(long prev in previousroute)
        {
            if (Array.BinarySearch(cross, prev) >= 0)
            {
                Console.WriteLine("POSSIBLE");
                return;
            }
        }

        Console.WriteLine("IMPOSSIBLE");
    }
}