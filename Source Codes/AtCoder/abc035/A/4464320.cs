using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int W = int.Parse(input[0]);
            int H = int.Parse(input[1]);

            if (W/4*3==H)
            {
                Console.WriteLine("4:3");
            }
            else if (W/16*9==H)
            {
                Console.WriteLine("16:9");
            }


        }
    }
}