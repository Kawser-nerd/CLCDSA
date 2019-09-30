using System;
using System.Collections.Generic;

class p
{
    static void Main(string[] args)
    {
        long N = long.Parse(Console.ReadLine());
        string[] input = Console.ReadLine().Split();
        long[] A = new long[N];
        long ans = 1;

        for(long i = 0; i < N; i++)
        {
            A[i] = long.Parse(input[i]);
        }

        Array.Sort(A);//??
        Array.Reverse(A);//??

        long sum = 0;
        for(long i = 0; i < N; i++)
        {
            sum += A[i];
        }

        for (long i = 0; i < N - 1; i++)
        {
            sum -= A[i];
            if (sum * 2 >= A[i]) ans++;
            else break;
        }

        Console.WriteLine(ans);

    }   
}