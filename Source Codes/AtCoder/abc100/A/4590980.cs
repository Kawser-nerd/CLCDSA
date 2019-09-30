using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);

        if (a <= 8 && b <= 8) Console.WriteLine("Yay!");
        else Console.WriteLine(":(");
    }
}