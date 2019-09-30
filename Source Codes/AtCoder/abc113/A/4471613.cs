using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int X = input[0];
            int Y = input[1];
            Console.WriteLine(X + (Y / 2));
        }
    }
}