using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int rgb = input[0] * 100 + input[1] * 10 + input[2];
            Console.WriteLine(rgb % 4 == 0 ? "YES" : "NO");
        }
    }
}