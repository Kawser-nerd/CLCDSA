using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var a = Convert.ToInt32(input[0]);
        var b = Convert.ToInt32(input[1]);
        var c = Convert.ToInt32(input[2]);
        var d = Convert.ToInt32(input[3]);

        if (a * b >= c * d) Console.WriteLine(a * b);
        else Console.WriteLine(c * d);
    }
}