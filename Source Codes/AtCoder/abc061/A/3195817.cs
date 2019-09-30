using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var a = Convert.ToInt32(input[0]);
        var b = Convert.ToInt32(input[1]);
        var c = Convert.ToInt32(input[2]);

        var result = c >= a && c <= b ? "Yes" : "No";
        Console.WriteLine(result);
    }
}