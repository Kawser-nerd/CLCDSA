using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var a = int.Parse(input[0]);
        var b = int.Parse(input[1]);
        var c = int.Parse(input[2]);

        int res;
        if (b > c)
        {
            res = b + c;
        }
        else
        {
            res = b * 2;
            c = c - b;
            res += Math.Min(a, c);
            if (c - a > 0)
            {
                res++;
            }
        }
        Console.WriteLine(res);
    }
}