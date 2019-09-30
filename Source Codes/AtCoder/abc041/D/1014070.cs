using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Magatro
{
    static int N, M;
    static int[] x, y;
    static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        N = int.Parse(s[0]);
        M = int.Parse(s[1]);
        int[] path = new int[N];
        for(int i = 0; i < M; i++)
        {
            s = Console.ReadLine().Split(' ');
         int x, y;
            x = int.Parse(s[0])-1;
            y = int.Parse(s[1])-1;
            path[y] |= 1<<x;
        }
        int max = 1<<N;
        ulong[] dp = new ulong[max];
        dp[0] = 1;
        for(int i = 0; i < max; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int t = 1 << j;
                if ((t & i) == 0 && (path[j] & i) == 0)
                {
                    dp[i | t] += dp[i];
                }
            }
        }
        Console.WriteLine(dp[max - 1]);
            }
}