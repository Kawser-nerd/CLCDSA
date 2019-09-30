using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());

        var count = num % 2 == 0 ? num / 2 : num / 2 + 1;
        Console.WriteLine(count);
    }
}