using System;
using System.Collections.Generic;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var input = new List<string> { "A", "B", "C", "D", "E" };
            string X = Console.ReadLine();
            Console.WriteLine(1+input.IndexOf(X));
        }
    }
}