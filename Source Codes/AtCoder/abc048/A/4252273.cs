using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            string s = input[1].Substring(0,1);
            Console.WriteLine("A" + s + "C");
        }
    }
}