using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int n = input[0];
            int x = input[1];
            Console.WriteLine(Math.Min(x - 1, n - x));
        }
    }
}