using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] input = Console.ReadLine().Split();
            int[] IntInput = new int[3];

            for (int i = 0; i < 3; i++)
            {
                IntInput[i] = int.Parse(input[i]);
            }
            if (IntInput[0]== IntInput[1]&& IntInput[0]== IntInput[2])
            {
                Console.WriteLine(1);
            }
            else if (IntInput[0]== IntInput[1]|| IntInput[0]== IntInput[2]|| IntInput[1]== IntInput[2])
            {
                Console.WriteLine(2);
            }
            else
            {
                Console.WriteLine(3);
            }

        }
    }
}