using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            int[] IntSides = new int[4];
            for (int i = 0; i < 4; i++)
            {
                IntSides[i] = int.Parse(input[i]);
            }
            if (IntSides[0]* IntSides[1]>= IntSides[2] * IntSides[3])
            {
                Console.WriteLine(IntSides[0] * IntSides[1]);
            }
            else
            {
                Console.WriteLine(IntSides[2] * IntSides[3]);
            }

        }  
    }
}