using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var hs = new HashSet<int>();
        var d = new Dictionary<int, int>();
        var ret = new int[n];
        for (int i = 0; i < n; i++)
        {
            var a = int.Parse(Console.ReadLine().Trim());
            ret[i] = a;
            hs.Add(a);
        }
        var ac = 0 ;
        foreach (var x in hs.OrderBy(x => x)) d[x] = ac++;
        foreach (var x in ret) Console.WriteLine(d[x]);
    }
}