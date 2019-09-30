using System;
using System.Linq;


namespace BC_005_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            Console.WriteLine(input[1] / input[0]);
        }
    }
}