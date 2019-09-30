using System;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        string[] input = Console.ReadLine().Split(' ');
        int[] a = Array.ConvertAll(input, Int32.Parse);
        long t = 1, ans = 0;

        for(int i = 0; i < N; i++)
        {
            if (i == N - 1|| a[i] >= a[i + 1])
            {
                t = t * (t + 1) / 2;
                ans += t;
                t = 1;
            }else t++;
        }

        Console.WriteLine(ans);

    }
}