using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string N = Console.ReadLine();
            Console.WriteLine(N[0] == N[2] ? "Yes" : "No");
        }
    }
}