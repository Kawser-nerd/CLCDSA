using System;

class Program
{
    static void Main(string[] args)
    {
        var whn = Console.ReadLine().Split();
        var w = int.Parse(whn[0]);
        var h = int.Parse(whn[1]);
        var n = int.Parse(whn[2]);

        var x = new int[n];
        var y = new int[n];
        var a = new int[n];
        for (int i = 0; i < n; i++)
        {
            var xya = Console.ReadLine().Split();
            x[i] = int.Parse(xya[0]);
            y[i] = int.Parse(xya[1]);
            a[i] = int.Parse(xya[2]);
        }

        var x1 = 0;
        var y1 = 0;
        var x2 = w;
        var y2 = h;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                x1 = Math.Min(x2, Math.Max(x1, x[i]));
            }
            else if (a[i] == 2)
            {
                x2 = Math.Max(x1, Math.Min(x2, x[i]));
            }
            else if (a[i] == 3)
            {
                y1 = Math.Min(y2, Math.Max(y1, y[i]));
            }
            else
            {
                y2 = Math.Max(y1, Math.Min(y2, y[i]));
            }
        }

        Console.WriteLine((x2 - x1) * (y2 - y1));
    }
}