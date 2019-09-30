using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var N = int.Parse(sr.ReadLine());

            for (int z = 0; z < N; z++)
            {
                int modulo = 10007;
                string[] sarr = sr.ReadLine().Split(' ');
                int H,W,R;
                H = int.Parse(sarr[0]);
                W = int.Parse(sarr[1]);
                R = int.Parse(sarr[2]);
                List<int> x = new List<int>();
                List<int> y = new List<int>();
                for(int i = 0; i < R; i++)
                {
                    sarr = sr.ReadLine().Split(' ');
                    y.Add(int.Parse(sarr[0]));
                    x.Add(int.Parse(sarr[1]));
                }

                int[,] dp = new int[103, 103];
                dp[1,1] = 1;

                for(int i = 1; i <= W; i++)
                    for(int j = 1; j <= H; j++)
                    {
                        int ni = i + 2;
                        int nj = j + 1;
                        bool flag = false;
                        for(int k = 0; k < x.Count; k++)
                            if(ni == x[k] && nj == y[k])
                                flag = true;

                        if (!flag)
                        {
                            dp[nj, ni] += dp[j, i];
                            dp[nj, ni] %= modulo;
                        }

                        ni = i + 1;
                        nj = j + 2;
                        flag = false;
                        for (int k = 0; k < x.Count; k++)
                            if (ni == x[k] && nj == y[k])
                                flag = true;
                        if (!flag)
                        {
                            dp[nj, ni] += dp[j, i];
                            dp[nj, ni] %= modulo;
                        }
                    }

                
                sw.WriteLine("Case #" + (z + 1) + ": " + dp[H,W]);
            }
            sw.Close();
        }
    }
}
