using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        var tempreture = input[0];
        var average = input[1];
        var heights = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

        var min = double.MaxValue;
        var point = 0;
        for (int i = 0; i < n; i++)
        {
            var buf = Conpare(Ave(tempreture, heights[i]), average);
            if (min > buf)
            {
                min = buf;
                point = i + 1;
            }
        }

        Console.WriteLine(point);
    }

    static double Ave(int temp, int height)
    {
        return temp - height * 0.006;
    }

    static double Conpare(double a, double b)
    {
        return Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    }
}