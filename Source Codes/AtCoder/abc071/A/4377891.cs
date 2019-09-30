using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int A = Math.Abs(input[1] - input[0]);
            int B = Math.Abs(input[2] - input[0]);
            Console.WriteLine(A < B ? "A" : "B");
        }
    }
}