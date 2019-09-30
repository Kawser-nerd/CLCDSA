using System;
using System.Linq;

class Program
{
    static int N;
    static int A;
    static int B;
    static long[] v;

    static void Main()
    {
        /*???????*/
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        A = input[1];
        B = input[2];
        v = Console.ReadLine().Split().Select(long.Parse).ToArray();

        /*v????????A????????*/
        Array.Sort(v);
        Array.Reverse(v); //v????
        long sum = 0;
        for (int i = 0; i < A; i++)
            sum += v[i];
        Console.WriteLine(sum / (double)A);

        /*v[0]??????A??????????????*/
        if (v[A - 1] == v[0])
        {
            int M = 1;
            for (int i = 1; ; i++)
            {
                if (i >= N || v[i] != v[i - 1])
                    break;
                M++;
            }
            long ans = 0;
            for (int i = A; i <= B; i++)
                ans += Comb(M, i);
            Console.WriteLine(ans);
            return;
        }

        /* v??v[A-1]???????p??v????????A????v[A-1]????
           ???q????????pCq???*/
        long va = v[A - 1];
        int p = v.Select(s => s == va ? 1 : 0).ToArray().Sum();
        int q = 0;
        for (int i = 0; i < A; i++)
            q += v[i] == va ? 1 : 0;
        Console.WriteLine(Comb(p, q));
    }

    static long Comb(int a, int b) //aCb???
    {
        if (b > a) return 0;
        if (b > a / 2) b = a - b;
        long v = 1;
        int k = 1;
        for (int i = 0; i < b; i++)
        {
            v *= a - i;
            while (k <= b && v % k == 0)
            {
                v /= k;
                k++;
            }
        }
        return v;
    }
}