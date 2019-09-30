using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



class Program
{

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static string Solution(StreamReader sr)
    {
        string[] t = sr.ReadLine().Split(' ');

        int N = int.Parse(t[0]);
        int M = int.Parse(t[1]);
        int K = int.Parse(t[2]);

        if (N > M)
        {
            int v = M;
            M = N;
            N = v;
        }

        if (N < 3)
            return K.ToString();
        if (K <= 4)
            return K.ToString();

        int r = int.MaxValue;

        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < M - 1; j++)
            {
                int v = i * j + i * 2 + j * 2;
                for (int w = 0; w < 5; w++)
                {
                    if (v + w >= K)
                    {
                        int s = i * 2 + j * 2 + w;
                        r = Math.Min(s, r);
                        int b = Math.Min(i, j);
                        b /= 2;

                        int d = v + w-K;

                        int x = 2;
                        while (d >= x && b > 0)
                        {
                            b--;
                            for (int q = 0; q < 4; q++)
                            {
                                if (d >= x)
                                {
                                    d -= x;
                                    s--;
                                }
                            }
                        }
                        r = Math.Min(s, r);
                    }
                }
            }
        }


        //for (int i = N - 1; i <= N; i++)
        //{
        //    for (int j = M - 1; j <= M; j++)
        //    {
        //        int v = i * j;
        //        if (v >= K)
        //        {
        //            int s = i * 2 + j * 2 - 4;
        //            r = Math.Min(s, r);
        //            int b = Math.Min(i, j);
        //            b /= 2;

        //            int d = v-K;

        //            int x = 2;
        //            while (d > x && b > 0)
        //            {
        //                b--;
        //                for (int q = 0; q < 4; q++)
        //                {
        //                    if (d > x)
        //                    {
        //                        d -= x;
        //                        s--;
        //                    }
        //                }
        //            }
        //            r = Math.Min(s, r);
        //        }
        //    }
        //}

        return r.ToString();


    }
}