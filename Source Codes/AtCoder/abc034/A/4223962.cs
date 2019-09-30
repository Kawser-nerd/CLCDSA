using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            if (input[0] < input[1])
            {
                Console.WriteLine("Better");
            }
            else
            {
                Console.WriteLine("Worse");
            }
        }
    }
}