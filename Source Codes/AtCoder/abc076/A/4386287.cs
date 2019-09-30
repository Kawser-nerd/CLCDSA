using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int R = int.Parse(Console.ReadLine());
            int G = int.Parse(Console.ReadLine());
            Console.WriteLine(G * 2 - R);
        }
    }
}