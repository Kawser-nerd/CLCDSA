using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var k = int.Parse(Console.ReadLine());

        var ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (ans < k)
            {
                ans *= 2;
            }
            else
            {
                ans += k;
            }
        }

        Console.WriteLine(ans);
    }
}