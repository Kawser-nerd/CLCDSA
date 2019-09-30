using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Array.ConvertAll(Console.ReadLine().Split().ToArray(), int.Parse);
        Console.WriteLine(input[1]%input[0]==0?input[1]/input[0]:input[1]/input[0]);
        Console.ReadLine();
    }
}