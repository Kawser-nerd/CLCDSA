using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var ret =    doShakutori(a);
        Console.WriteLine(ret);
    }
    public static int doShakutori(int[] a)
    {
        var n = a.Length;
        if (n == 1) return 1;
        var ret = 1; var pL = 0; var pr = 1;
        var hs = new HashSet<int>();
        hs.Add(a[0]);
        while (pr < n)
        {
            while (pr < n)
            {
                if (hs.Add(a[pr]))
                {
                    pr++;
                    ret = Math.Max(ret, pr - pL);
                }
                else break;
            }
            while (pr < n)
            {
                hs.Remove(a[pL]);
                if (hs.Add(a[pr])) { pL++; pr++; break; }
                pL++;
            }
        }
        return ret;
    }
}