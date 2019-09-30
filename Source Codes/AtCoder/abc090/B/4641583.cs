using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);

        var ans = 0;
        for (int i = a; i <= b; i++)
        {
            var x1 = i % 10;
            var x2 = i / 10 % 10;
            var x4 = i / 1000 % 10;
            var x5 = i / 10000;

            if (x1 == x5 && x2 == x4) ans++;
        }

        Console.WriteLine(ans);
    }
}