using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Increasing_Speed_Limits
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("D:\\in.txt");
            StreamWriter sw = new StreamWriter("D:\\out.txt");
            int vv = int.Parse(sr.ReadLine());
            for (int w = 0; w < vv; )
            {
                w++;
                
                string[] g = sr.ReadLine().Split(' ');
                int n = int.Parse(g[0]);
                long M = long.Parse(g[1]);
                long X = long.Parse(g[2]);
                long Y = long.Parse(g[3]);
                long Z = long.Parse(g[4]);
                long[] A = new long[M];
                int[] S = new int[n];
                for (long i = 0; i < M; i++)
                {
                    A[i] = int.Parse(sr.ReadLine());
                }
                for (long i = 0; i < n; i++)
                {
                    S[i] = (int)A[i % M];
                    A[i % M] = (X * A[i % M] + Y * (i + 1)) % Z;
                }
                long mm=1000000007;
                long r = 0;
                long[] R = new long[n];
                for (int i = 0; i < n; i++)
                {
                    long t = 0;
                    int u=S[i];
                    for (int j = 0; j < i; j++)
                    {
                        if (u > S[j])
                        {
                            t += R[j];
                            t %= mm;
                        }
                    }
                    t++;
                    t %= mm;
                    r += t;
                    r %= mm;
                    R[i] = t;
                }
                string outs = "Case #" + w.ToString() + ": ";
                sw.WriteLine(outs + r.ToString());
            }
            sr.Close();
            sw.Close();
        }
    }
}
