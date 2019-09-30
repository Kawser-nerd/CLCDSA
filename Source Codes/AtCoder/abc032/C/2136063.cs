using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] s = Enumerable.Repeat(0, nk[0]).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        long now = s[0];
        int b = -1;
        int e= 0;
        int max = 0;
        if (s.Contains(0))
        {
            max = s.Length;
        }
        else
        {
            while (b < s.Length - 1)
            {
                if (b == e || (e < s.Length - 1 && now * s[e + 1] <= nk[1]))
                {
                    e++;
                    now *= s[e];
                }
                else
                {
                    b++;
                    now /= s[b];
                }
                if (now <= nk[1])
                {
                    max = Math.Max(max, e - b);
                }
                //Console.WriteLine($"{b} {e} {now}");
            }
        }
        Console.WriteLine(max);
    }
}