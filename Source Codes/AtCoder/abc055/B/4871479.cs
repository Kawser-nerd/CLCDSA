using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var p = 1000000007;

        long ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans = ans * i % p;
        }

        Console.WriteLine(ans);
    }
}