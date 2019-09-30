using System;

class Program
{
    static void Main(string[] args)
    {
        var money = Convert.ToInt32(Console.ReadLine());
        var priceA = Convert.ToInt32(Console.ReadLine());
        var priceB = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine(money - priceA - (money - priceA) / priceB * priceB);
    }
}