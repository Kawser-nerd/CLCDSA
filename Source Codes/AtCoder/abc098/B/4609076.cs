using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        Console.ReadLine();
        var s = Console.ReadLine();

        var max = 0;
        for (int i = 1; i < s.Length; i++)
        {
            max = Math.Max(max, m1(s.Substring(0, i), s.Substring(i)));
        }
        Console.WriteLine(max);
    }

    static int m1(string x, string y)
    {
        var set = new HashSet<char>();
        var ans = 0;
        for (int i = 0; i < x.Length; i++)
        {
            if (set.Add(x[i]))
            {
                for (int j = 0; j < y.Length; j++)
                {
                    if (x[i] == y[j])
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
}