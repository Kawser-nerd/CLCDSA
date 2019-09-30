using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var limit = Convert.ToInt32(input[0]);
        var buy = Convert.ToInt32(input[1]);
        var eat = Convert.ToInt32(input[2]);

        if (buy >= eat) Console.WriteLine("delicious");
        else if (eat - buy <= limit) Console.WriteLine("safe");
        else Console.WriteLine("dangerous");
    }
}