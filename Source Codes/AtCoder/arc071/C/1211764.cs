using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

class P
{
    static void Main(string[] _)
    {
        StringBuilder ans = new StringBuilder();
        StringBuilder S = new StringBuilder(Console.ReadLine());
        StringBuilder T = new StringBuilder(Console.ReadLine());
        int q = int.Parse(Console.ReadLine());
        int[] s = new int[S.Length + 1];
        int[] t = new int[T.Length + 1];
        s[0] = 0;
        for (int i = 0; i < S.Length; i++)
        {
            s[i + 1] = 'A' == S[i] ? s[i] + 1 : s[i] + 2;
        }
        t[0] = 0;
        for (int i = 0; i < T.Length; i++)
        {
            t[i + 1] = 'A' == T[i] ? t[i] + 1 : t[i] + 2;
        }
        for (int i = 0; i < q; i++)
        {
            _ = Console.ReadLine().Split(' ');
            int a = int.Parse(_[0]);
            int b = int.Parse(_[1]);
            int c = int.Parse(_[2]);
            int d = int.Parse(_[3]);
            Console.WriteLine((s[b] - s[a - 1]) % 3 == (t[d] - t[c - 1]) % 3 ? "YES" : "NO");
        }
    }
}