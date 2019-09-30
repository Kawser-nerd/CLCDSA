using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] c = new int[n], s = new int[n], f = new int[n];
        for (int i = 0; i < n - 1; i++)
        {
            var T = Console.ReadLine().Split().Select(int.Parse).ToArray();
            c[i] = T[0];s[i] = T[1];f[i] = T[2];
        }
        Pos[] p = new Pos[n];
        for (int i = 0; i < n; i++) p[i].n = i;
        int t = 0;
        int N = n;
        while(true)
        {
            for (int i = N - 1; i >= 0; i--)
            {
                if (p[i].t > 0) p[i].t--;
                if (p[i].t == 0)
                {
                    if (p[i].n == n - 1) { p[i].goll = t; N--; }
                    else if (t == s[p[i].n] || (t > s[p[i].n] && (t - s[p[i].n]) % f[p[i].n] == 0))
                    { p[i].t = c[p[i].n]; p[i].n++; }
                }
            }
            t++;
            if (N == 0) break;
        }
        for (int i = 0; i < n; i++) Console.WriteLine(p[i].goll);
    }
    public struct Pos
    {
        public int n;
        public int t;
        public int goll;
    }
}