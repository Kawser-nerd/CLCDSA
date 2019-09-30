using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        if ((input[0] == input[1])) Console.WriteLine("H");
        else Console.WriteLine("D");
    }
}