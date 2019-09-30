using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int[] A = I();
        int[] B = I();
        int[] C = I();
        int[] b = new int[N];
        long[] bb = new long[N + 1];
        int index = 0;
        for (int i = 0; i < B.Length; i++)
        {
            while (index < N && B[i] >= C[index])
            {
                index++;
            }
            b[i] = N - index;
        }
        bb[N - 1] = b[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            bb[i] = bb[i + 1] + b[i];
        }
        long res = 0;
        index = 0;
        for (int i = 0; i < N; i++)
        {
            while (index < N && A[i] >= B[index])
            {
                index++;
            }
            res += bb[index];
        }
        Console.WriteLine(res);
    }
    static int[] I()
    {
        return Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
    }
}