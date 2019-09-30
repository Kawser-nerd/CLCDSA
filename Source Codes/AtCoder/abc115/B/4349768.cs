using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var vals = new int[n];
        for (int i = 0; i < n; i++)
        {
            vals[i] = int.Parse(Console.ReadLine());
        }

        var sum = vals.Sum() - vals.Max() + vals.Max() / 2.0;
        Console.WriteLine((int)sum);
    }
}