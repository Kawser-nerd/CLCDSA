using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int N = input[0];
            int A = input[1];
            int B = input[2];
            Console.WriteLine(Math.Min(A * N, B));
        }
    }
}