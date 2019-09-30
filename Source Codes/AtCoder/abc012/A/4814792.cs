using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();
        int temp = input[0];
        input[0] = input[1];
        input[1] = temp;
        Console.WriteLine(input[0]+" "+input[1]);
        Console.ReadLine();
    }
}