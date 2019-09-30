using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var d = new int[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(Console.ReadLine());
        }
        Array.Sort(d);

        var x = d[0];
        var ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (x < d[i])
            {
                x = d[i];
                ans++;
            }
        }

        Console.WriteLine(ans);
    }
}