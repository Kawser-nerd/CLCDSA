using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            Array.Sort(input);
            Console.WriteLine(input[0] == 5 && input[1] == 5 && input[2] == 7 ? "YES" : "NO");
        }
    }
}