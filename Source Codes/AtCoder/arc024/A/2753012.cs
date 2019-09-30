using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var L = int.Parse(line[0]);
        var r = int.Parse(line[1]);
        var dL = setDic(L);
        var dr = setDic(r);
        var count = 0;
        foreach (var x in dL)
            if (dr.ContainsKey(x.Key)) count += Math.Min(x.Value, dr[x.Key]);
        Console.WriteLine(count);
    }
    public static Dictionary<int,int> setDic (int n)
    {
        var d = new Dictionary<int, int>();
        string[] line = Console.ReadLine().Trim().Split(' ');
        for (int i = 0; i < n; i++)
        {
            var w = int.Parse(line[i]);
            if (d.ContainsKey(w)) d[w]++;
            else d[w] = 1;
        }
        return d;
    }
}