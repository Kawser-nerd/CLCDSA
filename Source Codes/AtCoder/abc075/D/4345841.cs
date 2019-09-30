// ABC 075 D Axis-Parallel Rectangle

using System;
using System.Linq;

class Program
{
    static int N;
    static int K;
    static int[] x;
    static int[] y;

    static void Main()
    {
        /* ??????? */
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        K = input[1];
        x = new int[N];
        y = new int[N];
        for (int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            x[i] = input[0];
            y[i] = input[1];
        }

        /* a,c in x??b,d in y ??????? */
        long ans = long.MaxValue;
        foreach (var a in x)
        {
            foreach (var c in x)
            {
                foreach (var b in y)
                {
                    foreach (var d in y)
                    {
                        if (Judge(a, b, c, d))
                            ans = Math.Min(ans, (long)(c - a) * (b - d));
                    }
                }
            }
        }
        Console.WriteLine(ans);
    }

    /* ??????(a,b), ??????(c,d)??????K????????? */
    static bool Judge(int a, int b, int c, int d)
    {
        if (a >= c || d >= b) return false;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            int xi = x[i];
            int yi = y[i];
            if (a <= xi && xi <= c && d <= yi && yi <= b)
                count++;
        }
        if (count >= K) return true;
        return false;
    }
}