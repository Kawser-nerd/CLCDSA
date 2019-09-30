using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int[] cin = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();
        int n = cin[0];
        int m = cin[1];

        int[] ans = { 0, 0, 0 };
        ans[0] = (4 * n - m) / 2;
        ans[2] = n - ans[0];
        if (ans[0] >= 0 && ans[1] >= 0 && ans[2] >= 0)
        {
            if (n == ans[0] + ans[2] && m == ans[0] * 2 + ans[2] * 4)
            {
                Console.WriteLine("{0} {1} {2}", ans[0], ans[1], ans[2]);
                return;
            }
        }
        ans[1] = 1;
        ans[0] = (4 * (n - 1) - (m - 3)) / 2;
        ans[2] = n - 1 - ans[0];
        if (ans[0] >= 0 && ans[1] >= 0 && ans[2] >= 0)
        {
            if (n == ans[0] + ans[1] + ans[2] && m == ans[0] * 2 + 3 + ans[2] * 4)
            {
                Console.WriteLine("{0} {1} {2}", ans[0], ans[1], ans[2]);
                return;
            }
        }

        Console.WriteLine("{0} {1} {2}", -1, -1, -1);
    }
}