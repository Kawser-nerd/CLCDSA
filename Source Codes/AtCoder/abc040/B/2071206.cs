using System;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int min = int.MaxValue;
        int d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n / i; j++)
            {
                d = (i > j) ? i - j : j - i;
                min = Math.Min(min, d + n - i * j);
            }
        }
        Console.WriteLine(min);
    }
}