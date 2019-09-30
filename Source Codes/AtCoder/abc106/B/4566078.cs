using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var ans = 0;
        for (int i = 1; i <= n; i += 2)
        {
            var x = 0;
            for (int j = 1; j <= i; j++)
            {
                if (i % j == 0)
                {
                    x++;
                }
            }
            if (x == 8)
            {
                ans++;
            }
        }

        Console.WriteLine(ans);
    }
}