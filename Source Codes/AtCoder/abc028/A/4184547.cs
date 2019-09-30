using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            if (N == 100)
            {
                Console.WriteLine("Perfect");
            }
            else if (N >= 90 && N <= 99)
            {
                Console.WriteLine("Great");
            }
            else if (N >= 60 && N <= 89)
            {
                Console.WriteLine("Good");
            }
            else
            {
                Console.WriteLine("Bad");
            }
        }
    }
}