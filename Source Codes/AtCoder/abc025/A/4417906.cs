using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] output = new string[25];
            string likeword = Console.ReadLine();
            int N = int.Parse(Console.ReadLine());

            for (int i = 0; i < 25; i++)
            {
                        output[i] = likeword.Substring(i / 5, 1);
                        output[i] = output[i] + likeword.Substring(i % 5, 1);
            }

            Console.WriteLine(output[N-1]);
        }
    }
}