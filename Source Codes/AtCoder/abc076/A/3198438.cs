using System;

class Program
{
    static void Main(string[] args)
    {
        var nowRate = Convert.ToInt32(Console.ReadLine());
        var target = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine(2 * target - nowRate);
    }
}