using System;
using static System.Console;

class Program
{
    static void Main()
    {
        var N = int.Parse(ReadLine());
        int ans = int.MaxValue;

        for (var i = 0; i < N; i++)
        {
            var T = int.Parse(ReadLine());
            ans = Math.Min(ans, T);
        }
        WriteLine(ans);
    }
}