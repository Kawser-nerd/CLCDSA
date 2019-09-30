using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int[] N = new int[4];
            for (int i = 0; i < input.Length; i++)
            {
                N[i] = int.Parse(input[i]);
            }
            if ((double)N[1]/N[0]>(double)N[3]/N[2])
            {
                Console.WriteLine("TAKAHASHI");
            }
            else if ((double)N[1] / N[0] < (double)N[3] / N[2])
            {
                Console.WriteLine("AOKI");
            }
            else if ((double)N[1] / N[0] == (double)N[3] / N[2])
            {
                Console.WriteLine("DRAW");
            }

        }
    }
}