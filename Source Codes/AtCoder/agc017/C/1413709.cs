using System.Linq;
using System;

class Program
{
    static void Main()
    {
        C();
    }

    static void C()
    {
        // ??
        var NM = Console.ReadLine().Split(' ').Select(x => long.Parse(x));
        var N = NM.ElementAt(0);
        var M = NM.ElementAt(1);
        var A = Console.ReadLine().Split(' ').Select(x => long.Parse(x) - 1).ToArray();
        var X = new long[M];
        var Y = new long[M];
        for (int i = 0; i < M; i++)
        {
            var XY = Console.ReadLine().Split(' ').Select(x => long.Parse(x) - 1);
            X[i] = XY.ElementAt(0);
            Y[i] = XY.ElementAt(1);
        }

        // i???????????
        var num = new long[N];
        for (int i = 0; i < N; i++)
        {
            num[A[i]]++;
        }

        // x????????
        var range = new long[N];
        for (int i = 0; i < N; i++)
        {
            for (long j = i; j > i - num[i] && j >= 0; j--)
            {
                range[j]++;
            }
        }

        // ???????????
        long count = 0;
        for (int i = 0; i < N; i++)
        {
            if (range[i] == 0) count++;
        }

        // ???
        for (int i = 0; i < M; i++)
        {
            // ???
            if (A[X[i]] - num[A[X[i]]] + 1 >= 0)
            {
                if (range[A[X[i]] - num[A[X[i]]] + 1] > 0) 
                {
                    range[A[X[i]] - num[A[X[i]]] + 1]--;
                    if (range[A[X[i]] - num[A[X[i]]] + 1] == 0) count++;
                }
            }
            num[A[X[i]]]--;

            if (Y[i] - num[Y[i]] >= 0)
            {
                range[Y[i] - num[Y[i]]]++;
                if (range[Y[i] - num[Y[i]]] == 1) count--;
            }
            num[Y[i]]++;

            A[X[i]] = Y[i];

            Console.WriteLine(count);
        }
    }
}