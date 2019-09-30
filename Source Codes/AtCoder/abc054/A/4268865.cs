using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int A = input[0];
            int B = input[1];

            if (A == 1)
            {
                A = 14;
            }
            if(B == 1)
            {
                B = 14;
            }

            if (A > B)
            {
                Console.WriteLine("Alice");
            }
            else if (A == B)
            {
                Console.WriteLine("Draw");
            }
            else
            {
                Console.WriteLine("Bob");
            }
        }
    }
}