using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemC
	{
		static void Main(string[] args)
		{
			//TextReader sr = new StreamReader(@"c:\temp\c.in");
            //TextReader sr = new StreamReader(@"c:\temp\c-small-attempt1.in");
            TextReader sr = new StreamReader(@"c:\temp\c-large.in");
            //		TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\c.out");
			//TextWriter sw = Console.Out;

			int N = int.Parse(sr.ReadLine());
			for (int caseNo = 1; caseNo <= N; caseNo++)
			{
				sw.Write("Case #" + caseNo + ": ");
				Solve(sr, sw);
			}
            sw.Close();
		}

        private static void Solve(TextReader sr, TextWriter sw)
        {
            int n = int.Parse(sr.ReadLine());
            int[,] choose = new int[n + 1, n + 1];
            const int MOD = 100003;
            choose[0, 0] = 1;
            for (int i = 1; i <= n; i++)
            {
                choose[i, 0] = choose[i, i] = 1;
                for (int j = 1; j < i; j++)
                    choose[i, j] = (choose[i - 1, j - 1] + choose[i - 1, j]) % MOD;
            }
            int[,] dp = new int[n + 1,n+1];
            // dp[x,y] = number of S containing y numbers ending with x
            dp[1,0] = 1;
            for (int x = 2; x <= n; x++)
            {
                dp[x, 1] = 1;
                for (int y = 2; y < x; y++)
                {
                    int ways = 0;
                    for (int i = 1; i < y; i++)
                    {
                        // y is the i'th number
                        if (y - i - 1 <= x - y - 1)
                        {
                            long a = (long)choose[x - y - 1, y - i - 1] * dp[y, i];
                            ways += (int) (a % MOD);
                            ways %= MOD;
                        }
                    }         
                    //Console.WriteLine(string.Format("dp[{0},{1}] = {2}", x,y,ways));
                    dp[x,y] = ways;
                }                
            }

            int sum = 0;
            for (int i = 1; i < n; i++) sum = (sum + dp[n, i]) % MOD;
            sw.WriteLine(sum);
        }
    }
