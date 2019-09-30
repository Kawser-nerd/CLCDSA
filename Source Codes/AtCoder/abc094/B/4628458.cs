using System;

class Program
{
    static void Main(string[] args)
    {
        var nmx = Console.ReadLine().Split(' ');
        var n = int.Parse(nmx[0]);
        var m = int.Parse(nmx[1]);
        var x = int.Parse(nmx[2]);

        var left = 0;
        var right = 0;

        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < m; i++)
        {
            if (x < int.Parse(s[i]))
            {
                right++;
            }
            else
            {
                left++;
            }
        }

        Console.WriteLine(Math.Min(left, right));
    }
}