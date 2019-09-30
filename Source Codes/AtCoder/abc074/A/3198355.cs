using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        var red = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine(num * num - red);
    }
}