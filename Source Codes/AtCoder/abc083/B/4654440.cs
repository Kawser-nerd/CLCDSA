using System;

class Program
{
    static void Main(string[] args)
    {
        var nab = Console.ReadLine().Split(' ');
        var n = int.Parse(nab[0]);
        var a = int.Parse(nab[1]);
        var b = int.Parse(nab[2]);

        var ans = 0L;
        for (int i = 1; i <= n; i++)
        {
            var sum =
                i / 10000 +
                i / 1000 % 10 +
                i / 100 % 10 +
                i / 10 % 10 +
                i % 10;

            if (a <= sum && sum <= b)
            {
                ans += i;
            }
        }
        Console.WriteLine(ans);
    }
}