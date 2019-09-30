using System;
using System.Linq;

class Program
{
    static int N;
    static long A;
    static long B;
    static int[] X;

    static void Main()
    {
        long[] input = Console.ReadLine().Split().Select(long.Parse).ToArray();
        N = (int)input[0];
        A = input[1];
        B = input[2];
        X = Console.ReadLine().Split().Select(int.Parse).ToArray();

        long ans = 0;
        for (int i = 1; i < N; i++)
        {
            ans += Math.Min(B, A * (X[i] - X[i - 1]));
        }
        Console.WriteLine(ans);
    }
}