using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int A = input[0];
            int B = input[1];
            int C = input[2];
            int D = input[3];

            if (A * B == C * D)
            {
                Console.WriteLine(A * B);
            }
            else
            {
                Console.WriteLine(Math.Max(A * B, C * D));
            }
        }
    }
}