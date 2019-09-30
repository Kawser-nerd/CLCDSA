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

            if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) 
            {
                Console.WriteLine("Possible");
            }
            else
            {
                Console.WriteLine("Impossible");
            }
        }
    }
}