using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split('/');
        if (int.Parse(input[0]) > 2019
            || (int.Parse(input[1]) > 4
                && int.Parse(input[0]) == 2019)
        )
            Console.WriteLine("TBD");
        else
            Console.WriteLine("Heisei");
        Console.Read();
    }
}