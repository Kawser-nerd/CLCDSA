using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var f = new List<int>[n];
        for (int i = 0; i < n; i++) f[i] = new List<int>();
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]) - 1;
            var b = int.Parse(line[1]) - 1;
            f[a].Add(b);
            f[b].Add(a);
        }
        for (int i = 0; i < n; i++)
        {
            var alist = new List<int>();
            foreach (var x in f[i])
                foreach (var y in f[x])
                     alist.Add(y);
            foreach (var x in f[i])
                alist.RemoveAll(y =>y==x);
            alist.RemoveAll(y => y == i);
            var ret = alist.Distinct().Count();
            Console.WriteLine(ret);
        }
    }
}