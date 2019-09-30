using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        Console.WriteLine(Math.Max(input[0],input[1]));
        Console.ReadLine();
    }
}