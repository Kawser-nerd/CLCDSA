using System;

class Program
{
    static void Main(string[] args)
    {
        var str = Console.ReadLine();
        var num = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine(str.Substring(num - 1, 1));
    }
}