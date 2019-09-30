using System;

class Program
{
    static void Main(string[] args)
    {
        var candy = Convert.ToInt32(Console.ReadLine());
        var child = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine((child-(candy % child))%child);
    }
}