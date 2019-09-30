using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            double[] input = Array.ConvertAll(Console.ReadLine().Split(' '), double.Parse);
            Console.WriteLine(Math.Ceiling((input[0] + input[1]) / 2));
        }
    }
}