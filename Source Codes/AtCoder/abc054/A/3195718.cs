using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var alice = Convert.ToInt32(input[0]);
        var bob = Convert.ToInt32(input[1]);

        var result = "";
        if (alice == bob) result = "Draw";
        else if (alice == 1 || (alice > bob&&bob!=1)) result = "Alice";
        else result = "Bob";

        Console.WriteLine(result);
    }
}