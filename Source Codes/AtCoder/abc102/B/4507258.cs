using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var max = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                max = Math.Max(max, Math.Abs(Math.Max(a[i], a[j]) - Math.Min(a[i], a[j])));
            }
        }

        Console.WriteLine(max);
    }
}