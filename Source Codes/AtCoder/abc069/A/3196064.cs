using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var n = Convert.ToInt32(input[0]);
        var m = Convert.ToInt32(input[1]);

        Console.WriteLine((n - 1) * (m - 1));
    }
}