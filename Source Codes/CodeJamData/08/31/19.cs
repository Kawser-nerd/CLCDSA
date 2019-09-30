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

        void Run()
        {
            StreamReader sr = File.OpenText(@"d:\A-large.in");
            int N = int.Parse(sr.ReadLine());
            for (int t = 0; t < N; t++)
            {
                string[] ss = sr.ReadLine().Split();
                int P = int.Parse(ss[0]), K = int.Parse(ss[1]), L = int.Parse(ss[2]);
                int[] a = new int[L];
                ss = sr.ReadLine().Split();
                for (int i = 0; i < L; i++)
                    a[i] = int.Parse(ss[i]);
                Array.Sort(a);
                Array.Reverse(a);
                long[] count = new long[P];
                for (int i = 0; i < P; i++) count[i] = K;
                long res = 0;
                int start = 0;
                for (int i = 0; i < L; i++)
                {
                    res += a[i] * (start + 1);
                    count[start]--;
                    if (count[start] == 0) start++;
                }
                                        
                Console.WriteLine("Case #" + (t + 1) + ": " + res);
            }
            sr.Close();
        }
    }
}