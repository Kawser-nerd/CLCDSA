using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] n = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int X = n[0];
            int Y = n[1];
            Console.WriteLine(Math.Max(X, Y));
        }
    }
}