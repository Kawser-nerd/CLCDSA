using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine(num*800 - (num / 15) * 200);
    }
}