using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var asum = a.Sum();
        var ret = new List<int>();
        for (int i = 0; i <= 3; i++)
            for (int j = i + 1; j <= 4; j++)
                ret.Add(asum - a[i] - a[j]);
        ret.Sort();
        Console.WriteLine(ret[7]);
    }
}