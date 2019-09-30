using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var dish1 = Convert.ToInt32(input[0]);
        var weight1 = Convert.ToInt32(input[1]);
        var dish2 = Convert.ToInt32(input[2]);
        var weight2 = Convert.ToInt32(input[3]);

        if (dish1 + weight1 == dish2 + weight2) Console.WriteLine("Balanced");
        else if (dish1 + weight1 > dish2 + weight2) Console.WriteLine("Left");
        else Console.WriteLine("Right");
    }
}