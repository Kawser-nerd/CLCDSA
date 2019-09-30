using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);
        if (b == 100)
        {
            var ans = Math.Pow(100, a) * 101;
            Console.WriteLine(ans);
        }
        else
        {
            var ans = Math.Pow(100, a) * b;
            Console.WriteLine(ans);
        }
    }
}