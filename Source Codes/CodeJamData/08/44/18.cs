using System;
using System.Collections.Generic;
using System.IO;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        string s;
        int K;
        bool[] b;
        int[] a;
        int res;

        void go(int i)
        {
            if (i == K)
            {
                int cost = 0;
                char c = 'A';
                for (int j = 0; j < s.Length; j++)
                {
                    if (c != s[(j / K) * K + a[j % K]]) cost++;
                    c = s[(j / K) * K + a[j % K]];
                }
                if (cost < res) res = cost;
            }
            else 
            for (int j = 0; j < K; j++) 
                if (!b[j])
                {
                    b[j] = true;
                    a[i] = j;
                    go(i + 1);
                    b[j] = false;
                }
        }

        void Run()
        {
            StreamReader sr = File.OpenText(@"d:\d-small-attempt1.in");
            int N = int.Parse(sr.ReadLine());
            
            for (int t = 0; t < N; t++)
            {
                K = int.Parse(sr.ReadLine());
                s = sr.ReadLine();
                b = new bool[K];
                a = new int[K];
                res = int.MaxValue;
                go(0);
                Console.WriteLine("Case #" + (t + 1) + ": " + res);
            }
            sr.Close();
        }
   }
}