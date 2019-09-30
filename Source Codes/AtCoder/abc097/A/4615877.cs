using System;

class Program
{
    static void Main(string[] args)
    {
        var abcd = Console.ReadLine().Split(' ');
        var a = int.Parse(abcd[0]);
        var b = int.Parse(abcd[1]);
        var c = int.Parse(abcd[2]);
        var d = int.Parse(abcd[3]);

        if (Math.Abs(a - c) <= d)
        {
            Console.WriteLine("Yes");
        }
        else if (Math.Abs(a - b) <= d &&
             Math.Abs(b - c) <= d)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}