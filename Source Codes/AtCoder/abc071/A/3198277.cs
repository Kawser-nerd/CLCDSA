using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var x = Convert.ToInt32(input[0]);
        var a = Convert.ToInt32(input[1]);
        var b = Convert.ToInt32(input[2]);

        var result = Math.Abs(x - a) > Math.Abs(x - b) ? "B" : "A";
        Console.WriteLine(result);
    }
}