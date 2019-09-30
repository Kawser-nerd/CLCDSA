using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var start = Convert.ToInt32(input[0]);
        var time = Convert.ToInt32(input[1]);

        var result = start - time >= 0 ? start - time : 0;
        Console.WriteLine(result);
    }
}