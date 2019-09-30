using System;

class Program
{
    static void Main(string[] args)
    {
        var rate = Convert.ToInt32(Console.ReadLine());
        if (rate < 1200) Console.WriteLine("ABC");
        else Console.WriteLine("ARC");
    }
}