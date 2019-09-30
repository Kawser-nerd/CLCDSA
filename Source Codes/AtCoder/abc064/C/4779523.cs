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

        if (0 < a)
        {
            Console.WriteLine($"{a} {a + over}");
        }
        else
        {
            Console.WriteLine($"1 {over}");
        }
    }
}