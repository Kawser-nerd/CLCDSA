using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int X = input[0];
            int t = input[1];
            Console.WriteLine(X >= t ? X - t : 0);
        }
    }
}