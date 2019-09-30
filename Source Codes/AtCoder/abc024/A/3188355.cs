using System;

class Program
{
    static void Main(string[] args)
    {
        var input1 = Console.ReadLine().Split(' ');
        var chilePrice = Convert.ToInt32(input1[0]);
        var adaltPrice=Convert.ToInt32(input1[1]);
        var discount = Convert.ToInt32(input1[2]);
        var disPeople = Convert.ToInt32(input1[3]);

        var input2 = Console.ReadLine().Split(' ');
        var child = Convert.ToInt32(input2[0]);
        var adalt = Convert.ToInt32(input2[1]);

        var price = chilePrice * child + adaltPrice * adalt;
        if (adalt + child >= disPeople) price -= discount * (child + adalt);
        Console.WriteLine(price);
    }
}