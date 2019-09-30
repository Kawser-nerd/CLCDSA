using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

public class Program
{
    public static void Main(string[] args)
    {
        long[] line = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

        Console.WriteLine(solve(line[1]) - solve(line[0] - 1));
        Console.ReadLine();
    }

    static long solve(long n)
    {
        string S = n.ToString();

        var dp = new long[S.Length + 1, 2, 2];
        dp[0, 0, 0] = 1;

        for (int i = 0; i < S.Length; i++)
        {
            int C = int.Parse(S[i].ToString());
            for (int small = 0; small < 2; small++)
            {
                bool isSmaller = small == 1;
                for (int d = 0; d <= (isSmaller ? 9 : C); d++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        dp[i + 1, (isSmaller || d < C) ? 1 : 0, (j == 1 || d == 4 || d == 9) ? 1 : 0] += dp[i, small, j];
                    }
                }
            }
        }

        return dp[S.Length, 0, 1] + dp[S.Length, 1, 1];
    }
}