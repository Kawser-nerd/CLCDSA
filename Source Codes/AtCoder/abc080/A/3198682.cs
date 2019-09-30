using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var time = Convert.ToInt32(input[0]);
        var priceHourBasis = Convert.ToInt32(input[1]);
        var priceOverall = Convert.ToInt32(input[2]);

        var result = time * priceHourBasis < priceOverall ? time * priceHourBasis : priceOverall;
        Console.WriteLine(result);
    }
}