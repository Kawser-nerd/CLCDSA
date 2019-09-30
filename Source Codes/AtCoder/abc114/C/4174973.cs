using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Numerics;

public class Program
{
    public static void Main(string[] args)
    {
        //string[] line = Console.ReadLine().Split(' ');

        string s = Console.ReadLine();
        n = int.Parse(s);

        int ans = func("", s.Length);

        Console.WriteLine(ans);
        Console.ReadLine();
    }

    static int n;

    static int func(string s, int d)
    {
        if (d < 0) return 0;

        if (s.Contains('3') && s.Contains('5') && s.Contains('7'))
        {
            int x = int.Parse(s);

            if(x <= n)
            {
                d--;

                int r2 = 1;
                r2 += func(s + '3', d);
                r2 += func(s + '5', d);
                r2 += func(s + '7', d);

                return r2;
            }
        }

        int r = 0;

        d--;
        r += func(s + '3', d);
        r += func(s + '5', d);
        r += func(s + '7', d);

        return r;
    }
}