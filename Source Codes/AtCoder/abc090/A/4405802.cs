using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string line1 = Console.ReadLine();
            string line2 = Console.ReadLine();
            string line3 = Console.ReadLine();
            Console.WriteLine($"{line1[0]}{line2[1]}{line3[2]}");
        }
    }
}