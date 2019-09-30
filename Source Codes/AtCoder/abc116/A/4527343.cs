using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int AB = input[0];
            int BC = input[1];
            Console.WriteLine(BC * AB / 2);
        }
    }
}