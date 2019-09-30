using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(@"..\..\input.txt");
        StreamWriter sw = new StreamWriter(@"..\..\output.txt");
        int N = int.Parse(sr.ReadLine());
        string[] lines = new string[N];
        for (int i = 0; i < N; i++)
        {
            string[] tmp = sr.ReadLine().Split(' ');
            int n = int.Parse(tmp[0]);
            int m = int.Parse(tmp[1]);
            int X = int.Parse(tmp[2]);
            int Y = int.Parse(tmp[3]);
            int Z = int.Parse(tmp[4]);
            int[] A = new int[m];
            for (int j = 0; j < m; j++)
            {
                A[j] = int.Parse(sr.ReadLine());
            }
            int[] speedlimit = new int[n];
            for (int j = 0; j < n; j++)
            {
                speedlimit[j] = A[j % m];
                A[j % m] = (int)(((long)X * A[j % m] + (long)Y * (j + 1)) % Z);
            }
            int ans = work(n, speedlimit);

            sw.WriteLine("Case #{0}: {1}", i + 1, ans);
        }
        sw.Close();
    }

    private static int work(int n, int[] speedlimit)
    {
        checked
        {
            long ret = 0;
            long[] t = new long[n];
            for (int i = 0; i < n; i++)
            {
                t[i] = 1;
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (speedlimit[i] > speedlimit[j])
                        t[i] = (t[i] + t[j]) % 1000000007;
                }
            }
            for (int i = 0; i < n; i++)
            {
                ret = (ret + t[i]) % 1000000007;
            }
            return (int)ret;
        }
    }
}