using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int L = input[0] + input[1];
            int R = input[2] + input[3];

            if (L > R)
            {
                Console.WriteLine("Left");
            }
            else if (L == R)
            {
                Console.WriteLine("Balanced");
            }
            else
            {
                Console.WriteLine("Right");
            }
        }
    }
}