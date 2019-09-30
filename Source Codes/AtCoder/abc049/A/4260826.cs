using System;
using System.Linq;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var c = Console.ReadLine();
            var v = new string[]{ "a", "e", "i", "o", "u" };
            Console.WriteLine(v.Contains(c) ? "vowel" : "consonant");
        }
    }
}