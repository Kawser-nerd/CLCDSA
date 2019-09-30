#if !notdef
using System;
using System.Collections.Generic;
using System.Text;

public class Program
{
    static long solve(int[] a, int[] b)
    {
        long r = 0;
        Array.Sort<int>(a);
        Array.Sort<int>(b);
        for (int i = 0; i < a.Length; ++i)
            r += (long)a[i] * (long)b[b.Length - i - 1];

        return r;
    }

    static void Main()
    {
        int n = Int32.Parse(Console.ReadLine());

        for (int i = 0; i < n; ++i)
        {
            int S = Int32.Parse(Console.ReadLine());
            int[] a = new int[S];
            int[] b = new int[S];
            string[] t = Console.ReadLine().Split(' ');
            for (int j = 0; j < S; ++j)
                a[j] = Int32.Parse(t[j]);

            t = Console.ReadLine().Split(' ');
            for (int j = 0; j < S; ++j)
                b[j] = Int32.Parse(t[j]);
            
            var result = solve(a, b);
            Console.WriteLine("Case #{0}: {1}", i+1, result);
        }
    }
}
#endif
