using System;

class Program
{
    static void Main(string[] args)
    {
        var nx = Console.ReadLine().Split(' ');
        var N = int.Parse(nx[0]);
        var X = int.Parse(nx[1]);

        var min = int.MaxValue;
        var ans = 0;
        for (int i = 0; i < N; i++)
        {
            var m = int.Parse(Console.ReadLine());
            min = Math.Min(min, m);
            X -= m;
            ans++;
        }

        while (min <= X)
        {
            X -= min;
            ans++;
        }

        Console.WriteLine(ans);
    }
}