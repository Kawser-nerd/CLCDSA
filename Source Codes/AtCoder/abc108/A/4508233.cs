using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j += 2)
            {
                ans++;
            }
        }
        Console.WriteLine(ans);
    }
}