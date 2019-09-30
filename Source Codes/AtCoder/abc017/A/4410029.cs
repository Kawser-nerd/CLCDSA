using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] Question1 = Console.ReadLine().Split(' ');
            string[] Question2 = Console.ReadLine().Split(' ');
            string[] Question3 = Console.ReadLine().Split(' ');
            int sum = int.Parse(Question1[0]) * int.Parse(Question1[1])/10 + int.Parse(Question2[0])* int.Parse(Question2[1])/10 + int.Parse(Question3[0])* int.Parse(Question3[1])/10;

            Console.WriteLine(sum);
        }
    }
}