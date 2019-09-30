using System;

class Program
{
    static void Main(string[] args)
    {
        var a = int.Parse(Console.ReadLine());
        var b = int.Parse(Console.ReadLine());
        var c = int.Parse(Console.ReadLine());
        var x = int.Parse(Console.ReadLine()) / 50;

        var ans = 0;
        for (int i = 0; i <= a; i++)
        {
            if (i * 10 <= x)
            {
                for (int j = 0; j <= b; j++)
                {
                    var n = x - i * 10 - j * 2;
                    if (0 <= n && n <= c)
                    {
                        ans++;
                    }
                }
            }
        }

        Console.WriteLine(ans);
    }
}