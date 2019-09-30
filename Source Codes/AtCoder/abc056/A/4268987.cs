using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            string a = input[0];
            string b = input[1];

            if (a == "H")
            {
                Console.WriteLine(b == "H" ? "H" : "D");
            }
            else
            {
                Console.WriteLine(b == "H" ? "D" : "H");
            }
        }
    }
}