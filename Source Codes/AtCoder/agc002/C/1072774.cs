using System;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int L = int.Parse(input[1]);

        input = Console.ReadLine().Split(' ');
        int[] a = new int[N];
        for(int i = 0; i < N; i++)
        {
            a[i] = int.Parse(input[i]);
        }

        int d = -1;

        for(int i = 0; i < N-1; i++)
        {
            if (a[i] + a[i + 1] >= L)
            {
                d = i+1;
                break;
            }
        }

        if (d == -1) Console.WriteLine("Impossible");
        else
        {
            Console.WriteLine("Possible");
            for (int i = 1; i < d; i++) Console.WriteLine(i);
            for (int i = N - 1; i > d; i--) Console.WriteLine(i);
            Console.WriteLine(d);
        }

    }
}