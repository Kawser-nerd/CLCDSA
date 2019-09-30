using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int n = input[0];
            int m = input[1];
            Console.WriteLine((n - 1) * (m - 1));
        }
    }
}