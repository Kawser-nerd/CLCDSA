using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
using static System.Math;

class Program
{
    static int N;
    static int A;
    static int B;
    static int[] h;

    static void Main()
    {
        /* ??????? */
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        A = input[1];
        B = input[2];
        h = new int[N];
        for (int i = 0; i < N; i++) h[i] = int.Parse(Console.ReadLine());

        /* ?????????? */
        int l = 0;
        int r = h.Max() / B + 1;
        while (r - l > 1)
        {
            int m = (r + l) / 2;
            if (Judge(m)) r = m;
            else l = m;
        }
        Console.WriteLine(r);
    }

    /* k????????? */
    static bool Judge(int k)
    {
        int[] h_ = h.Select(s => Max(0, s - k * B)).ToArray();
        long c = 0;
        foreach (var hp in h_) c += hp / (A - B) + (hp % (A - B) == 0 ? 0 : 1);
        return c <= k;
    }
}