using System;

class Program
{
    static void Main(string[] args)
    {
        var R = 8;
        var n = int.Parse(Console.ReadLine());

        var d = new bool[R];
        var over = 0;

        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            var x = int.Parse(s[i]) / 400;
            if (x < R) d[x] = true;
            else over++;
        }

        var a = 0;
        for (int i = 0; i < R; i++)
        {
            if (d[i]) a++;
        }

        var min = Math.Max(1, a);
        var max = a + over;

        Console.WriteLine($"{min} {max}");
    }
}