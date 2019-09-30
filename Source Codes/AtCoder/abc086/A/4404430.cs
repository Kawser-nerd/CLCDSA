using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int a = input[0];
            int b = input[1];
            Console.WriteLine((a * b) % 2 == 0 ? "Even" : "Odd");
        }
    }
}