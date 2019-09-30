using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var price1 = Convert.ToInt32(input[0]);
        var price2 = Convert.ToInt32(input[1]);
        var money = Convert.ToInt32(input[2]);

        var min = Math.Min(price1, price2);
        Console.WriteLine(money / min);
        
    }
}