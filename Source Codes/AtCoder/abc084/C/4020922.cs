using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine()) - 1;
        var c = new int[n];
        var s = new int[n];
        var f = new int[n];
        for (int i = 0; i < n; i++)
        {
            string[] cin = Console.ReadLine().Split();
            c[i] = int.Parse(cin[0]);
            s[i] = int.Parse(cin[1]);
            f[i] = int.Parse(cin[2]);
        }
        for (int i = 0; i < n; i++)
        {
            int ans = 0;
            for (int j = i; j < n; j++)
            {
                if (ans <= s[j]) ans = s[j];
                else
                {
                    int tmp = (ans - s[j]) % f[j];
                    if (tmp != 0) ans += (f[j] - tmp);
                }
                ans += c[j];
            }
            Console.WriteLine(ans);
        }
        Console.WriteLine(0);
    }
}