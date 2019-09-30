using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int S = input[0];
            int T = input[1];
            int ans = T - S + 1;
            Console.WriteLine(ans);
        }
    }
}