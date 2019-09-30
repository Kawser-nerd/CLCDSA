using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var p = new long[n];
        var existOnLefts = new bool[n + 1];
        var chained = new bool[n + 1];
        for (int i = 0; i < n; i++)
        {
            var v = int.Parse(Console.ReadLine());
            p[i] = v;
            existOnLefts[v] = true;

            if (v > 1)
            {
                if (existOnLefts[v - 1])
                {
                    chained[v] = true;
                }
            }
        }

        var maxChain = 1;
        var curChain = 1;
        for (int v = 1; v <= n; v++)
        {
            if (chained[v])
            {
                curChain++;
                if (maxChain < curChain)
                {
                    maxChain = curChain;
                }
            }
            else
            {
                curChain = 1;
            }
        }

        Console.WriteLine(n - maxChain);
    }
}