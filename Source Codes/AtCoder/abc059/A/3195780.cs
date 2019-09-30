using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        foreach(var str in input)
        {
            Console.Write(str.Substring(0, 1).ToUpper());
        }
        Console.WriteLine();
    }
}