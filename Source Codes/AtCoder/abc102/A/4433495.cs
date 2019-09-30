using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            Console.WriteLine(N % 2 == 0 ? N : N * 2);
        }
    }
}