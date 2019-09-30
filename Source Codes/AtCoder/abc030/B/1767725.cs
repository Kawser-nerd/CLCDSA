using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = input[0] % 12;
        int m = input[1];
        double a = n * 30.0 + (30.0 / 60.0 * m);
        double b = m * 6.0;
        if (a > b)
        {
            double t = a;
            a = b;
            b = t;
        }
        double ans = Math.Min((b - a), (360 - b) + a);
        Console.WriteLine(ans);
    }
}