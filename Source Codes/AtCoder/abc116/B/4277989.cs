using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var s = int.Parse(Console.ReadLine());
        Func<int, int> f = x => x % 2 == 0 ? x / 2 : 3 * x + 1;

        var dic = new Dictionary<int, int>();
        var m = 1;
        var a = s;
        while (!dic.ContainsKey(a))
        {
            dic.Add(a, m);
            m++;
            a = f(a);
        }
        Console.WriteLine(m);
    }
}