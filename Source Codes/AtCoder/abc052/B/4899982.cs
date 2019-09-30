using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine();

        var x = 0;
        var ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I') x++;
            else x--;
            ans = Math.Max(ans, x);
        }

        Console.WriteLine(ans);
    }
}