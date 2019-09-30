using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var ans = 0;
        for (int i = 0; i < n; i++)
        {
            var ab = Console.ReadLine().Split(' ');
            ans += int.Parse(ab[1]) - int.Parse(ab[0]) + 1;
        }
        Console.WriteLine(ans);
    }
}