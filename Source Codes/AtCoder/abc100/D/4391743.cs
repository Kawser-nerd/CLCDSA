using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static int N;
    static int M;
    static Cake[] c;

    static void Main()
    {
        /* ??????? */
        long[] input = Console.ReadLine().Split().Select(long.Parse).ToArray();
        N = (int)input[0];
        M = (int)input[1];
        c = new Cake[N];
        for (int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split().Select(long.Parse).ToArray();
            c[i] = new Cake(input);
        }

        long ans = 0;
        int[] f = new[] { 1, -1 };

        foreach (var f1 in f)
        {
            foreach (var f2 in f)
            {
                foreach (var f3 in f)
                {
                    long[] s = new long[N];
                    for (int i = 0; i < N; i++)
                        s[i] = c[i].Sum(f1, f2, f3);
                    Array.Sort(s);
                    Array.Reverse(s);
                    long t = 0;
                    for (int i = 0; i < M; i++)
                        t += s[i];
                    ans = Math.Max(ans, t);
                }
            }
        }

        Console.WriteLine(ans);
    }
}

struct Cake
{
    public long x { get; set; }
    public long y { get; set; }
    public long z { get; set; }

    public Cake(long[] inp)
    {
        x = inp[0];
        y = inp[1];
        z = inp[2];
    }

    public long Sum(int f1, int f2, int f3)
    {
        long v = 0;
        v += x * (f1 > 0 ? 1 : -1);
        v += y * (f2 > 0 ? 1 : -1);
        v += z * (f3 > 0 ? 1 : -1);
        return v;
    }
}