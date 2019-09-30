using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = new int[3];
            int[] output = new int[3];
            input[0] = int.Parse(Console.ReadLine());
            input[1] = int.Parse(Console.ReadLine());
            input[2] = int.Parse(Console.ReadLine());

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (input[i]<=input[j])
                    {
                        output[i] = output[i] + 1;
                    }
                }
            }
            Console.WriteLine(output[0]);
            Console.WriteLine(output[1]);
            Console.WriteLine(output[2]);
        }
    }
}