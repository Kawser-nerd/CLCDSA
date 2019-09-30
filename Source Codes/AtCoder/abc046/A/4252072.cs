using System;
using System.Linq;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            Console.WriteLine(input.Distinct().Count());
        }
    }
}