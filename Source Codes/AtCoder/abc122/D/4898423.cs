using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC122D
{
    static class MainClass
    {

        static int[] s;
        static long[,,,] dp = new long[101, 4, 4, 4];
        static bool[,,,] done = new bool[101, 4, 4, 4];
        static long mod = (long)Math.Pow(10,9)+7;

        public static void Main(string[] args)
        {

            s = Array.ConvertAll(Console.ReadLine().Split().ToArray(), int.Parse);
            long ptn = 0;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        done[3,i,j,k] = true;
                        if (Ok(3, i, j, k))
                        {
                            dp[3, i, j, k]++;
                        }
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        ptn += Dfs(s[0], i, j, k);
                    }
                }
            }
            Console.WriteLine(ptn%mod);

        }

        public static long Dfs(int n, int w1, int w2, int w3) {
            if (n == 0)
            {
                return 1;
            }
            else if (done[n,w1,w2,w3])
            {
                return dp[n, w1, w2, w3];
            }
            else
            {
                long ptn = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (Ok(i,w1, w2, w3))
                    {
                        //Console.WriteLine("OK:  i  : " + i + " w1 " + w1 + " w2 " + w2 + " w3 " + w3);
                        ptn += Dfs(n-1,i,w1,w2);
                    }
                    else
                    {
                        //Console.WriteLine("NG:  i  : " + i + " w1 " + w1 + " w2 " + w2 + " w3 " + w3);

                    }
                }
                done[n, w1, w2, w3] = true;
                dp[n, w1, w2, w3] = ptn%mod;
                //Console.WriteLine("ptn: " + ptn + " n " + n + " w1 " + w1 + " w2 " + w2 + " w3 " + w3);
                return dp[n, w1, w2, w3];
            }
        }

        public static bool Ok(int w1,int w2,int w3,int a)
        {
            string s1 = w1.ToString();
            string s2 = w2.ToString();
            string s3 = w3.ToString();
            string sa = a.ToString();

            if ((s1 + s2 + s3 + sa).Contains("012")) return false;
            if ((s2 + s1 + s3 + sa).Contains("012")) return false;
            if ((s1 + s3 + s2 + sa).Contains("012")) return false;
            if ((s1 + s2 + sa + s3).Contains("012")) return false;
            return true;
        }
    }
}