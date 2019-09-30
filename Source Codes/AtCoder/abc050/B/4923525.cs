using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var T = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

        var m = int.Parse(Console.ReadLine());
        var P = new int[m];
        var X = new int[m];
        for (int i = 0; i < m; i++)
        {
            var px = Console.ReadLine().Split();
            P[i] = int.Parse(px[0]);
            X[i] = int.Parse(px[1]);
        }

        var sum = 0;
        for (int i = 0; i < n; i++) sum += T[i];

        for (int i = 0; i < m; i++)
        {
            Console.WriteLine(sum - T[P[i] - 1] + X[i]);
        }
    }
}