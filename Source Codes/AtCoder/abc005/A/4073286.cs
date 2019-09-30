using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int x = input[0];
            int y = input[1];
            int ans = y / x;
            Console.WriteLine(ans);
        }
    }
}