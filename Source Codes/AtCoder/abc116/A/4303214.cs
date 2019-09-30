using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int b = int.Parse(input[0]);
        int c = int.Parse(input[1]);
        int d = int.Parse(input[2]);
        Console.WriteLine(b * c / 2);

    }
}