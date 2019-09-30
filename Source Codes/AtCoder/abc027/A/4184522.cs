using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            if (input[0] == input[1])
            {
                Console.WriteLine(input[2]);
            }
            else if (input[0] == input[2]) 
            {
                Console.WriteLine(input[1]);
            }
            else
            {
                Console.WriteLine(input[0]);
            }
        }
    }
}