using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    void solve()
    {
        string[] buf = Console.ReadLine().Split(' ');
        long S = long.Parse(buf[0]);
        long c = long.Parse(buf[1]);
        long ans = 0;

        if (S * 2 > c)
        {
            ans = c / 2;
        }
        else
        {
            ans = S + (c - S * 2) / 4;
        }
        Console.WriteLine(ans);
    }
    public static int Main()
    {
        bool loop = false;
#if ES_DEBUG
        loop = true;
#endif
        do
        {
            new Program().solve();
        } while (loop);
        return 0;
    }
}