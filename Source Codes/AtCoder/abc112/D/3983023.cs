using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        var nm = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        long ans = 1;
        var list = new List<long>();
        for (int i = 1; i <= Math.Sqrt(nm[1]); i++)
        {
            if (nm[1] % i == 0) list.Add(i);
        }
        for (int i = 0; i < list.Count(); i++)
        {
            if (nm[1] % list[i] == 0 && list[i] * nm[0] <= nm[1]) ans = Math.Max(ans, list[i]);
            if (nm[1] % (nm[1] / list[i]) == 0 && (nm[1] / list[i]) * nm[0] <= nm[1]) ans = Math.Max(ans, nm[1] / list[i]);
        }
        Console.WriteLine(ans);
    }
}