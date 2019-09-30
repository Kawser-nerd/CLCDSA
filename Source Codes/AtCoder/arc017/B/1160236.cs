using System;
using System.Collections.Generic;
using System.Collections;


class p
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split();
        long N = long.Parse(input[0]);
        long K = long.Parse(input[1]);
        long[] A = new long[N];
        long temp = 1;
        long ans = 0;
        for(int i = 0; i < N; i++)
        {
            A[i] = long.Parse(Console.ReadLine());
        }

        if (K == 1) ans = N;
        else {
            for (int i = 0; i < N - 1; i++)
            {
                if (A[i] < A[i + 1])
                {
                    temp++;
                }else
                {
                    ans += Math.Max(0, temp - K + 1);
                    temp = 1;
                }
                if (i == N - 2)
                {
                    ans += Math.Max(0, temp - K + 1);
                }
            }
        }

        Console.WriteLine(ans);
    }   
}