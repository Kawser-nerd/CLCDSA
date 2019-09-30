using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int X = input[0];
            int A = input[1];
            int B = input[2];

            if (B<=A)
            {
                Console.WriteLine("delicious");
            }
            else if (B > A && B <= (A + X))
            {
                Console.WriteLine("safe");
            }
            else
            {
                Console.WriteLine("dangerous");
            }
        }
    }
}