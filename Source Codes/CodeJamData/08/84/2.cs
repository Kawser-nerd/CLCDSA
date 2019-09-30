using System;
using System.Collections.Generic;
using System.Text;

public class D
{
    static int N, K, P;
    public static void Main(string[] args)
    {
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            string[] p = Console.ReadLine().Split();
            N = int.Parse(p[0]);
            K = int.Parse(p[1]);
            P = int.Parse(p[2]);
            mem = new int[N + 1, 1 << (P + 1)];
            done = new bool[N + 1, 1 << (P + 1)];
            Console.WriteLine("Case #" + CASE + ": " + rec(0, (1 << K) - 1));
        }
    }

    static int[,] mem;
    static bool[,] done;

    static int rec(int n, int bitmask)
    {
        if (n == N - K && (bitmask == (1 << K) - 1)) return 1;
        if (done[n, bitmask]) return mem[n, bitmask];
        done[n, bitmask] = true;
        mem[n, bitmask] = 0;
        int newbitmask = 0;
        for (int i = 1; i <= P; i++)
        {
            if ((bitmask & (1 << i)) > 0)
            {
                newbitmask |= 1 << (i - 1);
            }
        }
        for (int i = 1; i <= P && (n + i <= N); i++)
        {
            if ((bitmask & (1 << i)) > 0) continue;
            mem[n, bitmask] += rec(n + 1, newbitmask | (1 << (i - 1)));
            mem[n, bitmask] %= 30031;
        }
        return mem[n, bitmask];
    }
}
