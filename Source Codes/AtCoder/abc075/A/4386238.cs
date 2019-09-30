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

            if (A == B)
            {
                Console.WriteLine(C);
            }
            else if (A == C)
            {
                Console.WriteLine(B);
            }
            else
            {
                Console.WriteLine(A);
            }
        }
    }
}