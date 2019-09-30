using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            double[] input = Array.ConvertAll(Console.ReadLine().Split(' '), double.Parse);
            double teamT = input[1] / input[0];
            double teamA = input[3] / input[2];

            if (teamT > teamA)
            {
                Console.WriteLine("TAKAHASHI");
            }
            else if (teamA > teamT)
            {
                Console.WriteLine("AOKI");
            }
            else
            {
                Console.WriteLine("DRAW");
            }
        }
    }
}