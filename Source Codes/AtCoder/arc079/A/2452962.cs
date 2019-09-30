using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;
class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int> reacheableFromS = new List<int>();
        List<int> reacheableFromE = new List<int>();
        for (int i = 0; i < nm[1]; i++)
        {
            int[] ab = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
            if (ab[0] == 1) reacheableFromS.Add(ab[1]);
            if (ab[1] == nm[0]) reacheableFromE.Add(ab[0]);
        }
        if (reacheableFromS.Intersect(reacheableFromE).Count() == 0) Console.WriteLine("IMPOSSIBLE");
        else Console.WriteLine("POSSIBLE");
    }
}