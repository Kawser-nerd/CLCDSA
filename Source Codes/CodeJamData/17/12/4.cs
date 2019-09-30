using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class R1A_2_Solution
{
    static void Main()
    {
        //----------------------------------------------------------------------
        const string INPUT_FILE = @"..\..\..\data\data\input.txt";
        const string OUTPUT_FILE = @"..\..\..\data\data\output.txt";
        //----------------------------------------------------------------------
        StreamReader sr = new StreamReader(INPUT_FILE);
        StreamWriter sw = new StreamWriter(OUTPUT_FILE);
        DateTime started = DateTime.Now;
        //----------------------------------------------------------------------
        int T = int.Parse(sr.ReadLine());
        for (int t = 0; t < T; t++)
        {
            string[] ss = sr.ReadLine().Split((char[])null, StringSplitOptions.RemoveEmptyEntries).ToArray();
            int N = int.Parse(ss[0]);
            int P = int.Parse(ss[1]);

            long[] R = sr.ReadLine().Split((char[])null, StringSplitOptions.RemoveEmptyEntries).Select(p => long.Parse(p)).ToArray();
            long[][] Q = new long[N][];
            for (int i = 0; i < N; i++)
            {
                Q[i] = sr.ReadLine().Split((char[])null, StringSplitOptions.RemoveEmptyEntries).Select(p => long.Parse(p)).ToArray();
                Array.Sort(Q[i]);
            }

            int[] ix = new int[N];
            int kx = 0;

            int K = 0;

            while (true)
            {
                kx++;
                bool done = false;

                int M = int.MaxValue;
                for (int i = 0; i < N; i++)
                {
                    long rx = R[i] * kx;
                    while (ix[i] < P && Q[i][ix[i]] < rx * 0.9) ix[i]++;
                    if (ix[i] == P) done = true;
                    int j = ix[i];
                    while (j < P && Q[i][j] >= rx * 0.9 && Q[i][j] <= rx * 1.1) j++;
                    if (j - ix[i] < M) M = j - ix[i];
                    if (M == 0) break;
                }
                if (done) break;
                if (M == 0) continue;
                K += M;
                for (int i = 0; i < N; i++) ix[i] += M;
            }
            sw.WriteLine("Case #{0}: {1}", t + 1, K);
        }
        //----------------------------------------------------------------------
        sr.Close();
        sw.Close();
        //----------------------------------------------------------------------
        Console.WriteLine();
        Console.WriteLine("Elapsed: {0} ms", (int)DateTime.Now.Subtract(started).TotalMilliseconds);
        Console.ReadLine();
        //----------------------------------------------------------------------
    }
}
