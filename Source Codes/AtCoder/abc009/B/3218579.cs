using System;
using System.Collections.Generic; 

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        var prices = new SortedSet<int>();
        for(var i = 0; i < num; i++)
        {
            prices.Add(Convert.ToInt32(Console.ReadLine()));
        }
        prices.Remove(prices.Max);
        Console.WriteLine(prices.Max);
    }
}