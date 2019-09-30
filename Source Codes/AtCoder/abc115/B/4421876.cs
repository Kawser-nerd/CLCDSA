using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var d = new int[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(Console.ReadLine());
        }

        var max_i = 0;
        var sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += d[i];
            if (d[max_i] < d[i])
            {
                max_i = i;
            }
        }

        var ans = sum - d[max_i] + d[max_i] / 2;
        Console.WriteLine(ans);
    }
}