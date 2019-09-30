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
            long mod = 1000000007;

            for (int i = 0; i < N; i++)
            {
                long n, m, X, Y, Z;
                var sarr = sr.ReadLine().Split(' ');
                n = long.Parse(sarr[0]);
                m = long.Parse(sarr[1]);
                X = long.Parse(sarr[2]);
                Y = long.Parse(sarr[3]);
                Z = long.Parse(sarr[4]);
                List<long> A = new List<long>();
                for (int j = 0; j < m; j++)
                    A.Add(long.Parse(sr.ReadLine()));

                List<long> sLim = new List<long>();
                for (long j = 0; j < n; j++)
                {
                    int t = (int)(j % m);
                    sLim.Add(A[t]);
                    A[t] = (X * A[t] + Y * (j + 1)) % Z;
                }

                List<long> result = new List<long>();
                long res = 0;

                for(int j = 0; j < n; j++)
                {
                    long toAdd = 1;
                    for(int k = 0; k < j; k++)
                        if(sLim[k] < sLim[j])
                            toAdd = (result[k] + toAdd) % mod;
                    result.Add(toAdd);
                    res = (res + toAdd) % mod;
                }

                sw.WriteLine("Case #" + (i + 1) + ": " + res);
            }
            sw.Close();
        }
    }
}
