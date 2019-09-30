using System;

class Program
{
    static public void Main(string[] args)
    {
        long ans = 0;
        string[] input = Console.ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int a = int.Parse(input[1]);
        int b = int.Parse(input[2]);

        int[] x = new int[n];
        input = Console.ReadLine().Split(' ');

        for(int i = 0; i < n; i++)
        {
            x[i] = int.Parse(input[i]);
        }

        for(int i = 1; i < n; i++)
        {
            ans += Math.Min((long)a*(x[i]-x[i-1]),b);
        }

        Console.WriteLine(ans);

    }
}