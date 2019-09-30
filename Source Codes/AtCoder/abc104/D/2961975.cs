using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ABC_104
{
    class D
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Console.ReadLine();

            var dp = new long[s.Length + 1, 4];//??????????????
            var keys = new char[3] { 'A', 'B', 'C' };
            int mask = 1000000000 + 7;
            for (int i = s.Length; i >= 0; i--)
            {
                for (int j = 0; j <= 3; j++)
                {
                    if (i == s.Length)//??????
                    {
                        dp[i, j] = j == 3 ? 1 : 0;
                    }
                    else
                    {
                        if (j == 3)
                        {
                            dp[i, j] = dp[i + 1, j];
                            dp[i, j] *= s[i] == '?' ? 3 : 1;
                            dp[i, j] %= mask;
                        }
                        else
                        {
                            int m1 = s[i] == '?' ? 3 : 1;
                            int m2 = s[i] == '?' || s[i] == keys[j] ? 1 : 0;
                            dp[i, j] = m1 * dp[i + 1, j] + m2 * dp[i + 1, j + 1];
                            dp[i, j] %= mask;
                        }
                    }
                }
            }
            /*for(int i = 0; i < dp.GetLength(0); i++)
            {
                string str = "";
                for(int j = 0; j < dp.GetLength(1); j++)
                {
                    str += dp[i, j].ToString() + " ";
                }
                Console.WriteLine(str);
            }*/
            Console.WriteLine(dp[0, 0]);
        }
    }
}