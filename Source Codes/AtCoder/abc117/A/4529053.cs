using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            double[] input = Array.ConvertAll(Console.ReadLine().Split(' '), double.Parse);
            double T = input[0];
            double X = input[1];
            Console.WriteLine(T / X);
        }
    }
}