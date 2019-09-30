using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        var ta = Console.ReadLine().Split(' ');
        var t = int.Parse(ta[0]);
        var a = int.Parse(ta[1]);

        var s = Console.ReadLine().Split(' ');
        var h = new int[n];
        for (int i = 0; i < n; i++)
        {
            h[i] = int.Parse(s[i]);
        }

        var min = double.MaxValue;
        var min_i = 0;
        for (int i = 0; i < n; i++)
        {
            var m = Math.Abs(a - (t - h[i] * 0.006));
            if (m < min)
            {
                min = m;
                min_i = i;
            }
        }
        Console.WriteLine(min_i + 1);
    }
}