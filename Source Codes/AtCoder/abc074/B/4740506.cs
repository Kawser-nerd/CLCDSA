using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var k = int.Parse(Console.ReadLine());
        var s = Console.ReadLine().Split(' ');

        var ans = 0;
        for (int i = 0; i < n; i++)
        {
            var x = int.Parse(s[i]);
            ans += Math.Min(x * 2,
                Math.Abs(x - k) * 2);
        }

        Console.WriteLine(ans);
    }
}