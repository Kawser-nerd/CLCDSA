using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());
            Console.WriteLine(x < 1200 ? "ABC" : "ARC");
        }
    }
}