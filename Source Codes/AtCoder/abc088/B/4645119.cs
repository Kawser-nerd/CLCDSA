using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine()) % 500;
        var s = Console.ReadLine().Split(' ');
        var d = new int[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(s[i]);
        }

        Array.Sort(d, (x, y) => y - x);

        var ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans += d[i];
            }
            else
            {
                ans -= d[i];
            }
        }


        Console.WriteLine(ans);
    }
}