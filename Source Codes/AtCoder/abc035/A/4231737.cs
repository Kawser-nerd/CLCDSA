using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int W = input[0];
            int H = input[1];

            if (W % 16 == 0 && H % 9 == 0)
            {
                Console.WriteLine("16:9");
            }
            else
            {
                Console.WriteLine("4:3");
            }
        }
    }
}