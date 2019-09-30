using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split(' ');
        var n = int.Parse(s[0] + s[1]);

        var sqrt = (int)Math.Sqrt(n);
        if (sqrt * sqrt == n)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}