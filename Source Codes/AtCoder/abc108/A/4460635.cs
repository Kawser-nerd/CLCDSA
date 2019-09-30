using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int K = int.Parse(Console.ReadLine());

            if (K % 2 == 0)
            {
                Console.WriteLine((K / 2) * (K / 2));
            }
            else
            {
                Console.WriteLine(((K / 2) + 1) * (K / 2));
            }
        }
    }
}