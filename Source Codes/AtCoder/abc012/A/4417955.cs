using System;

namespace ABC012A
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            var A = int.Parse(input[0]);
            var B = int.Parse(input[1]);

            Console.WriteLine($"{B} {A}");
        }
    }
}