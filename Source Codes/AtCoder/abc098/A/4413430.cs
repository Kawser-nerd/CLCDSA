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
            int max1 = Math.Max(A + B, A - B);
            int max2 = Math.Max(A * B, max1);
            Console.WriteLine(max2);
        }
    }
}