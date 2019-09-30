using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            if (N % 2 == 1)
            {
                Console.WriteLine(N / 2 + 1);
            }
            else
            {
                Console.WriteLine(N / 2);
            }

            for (int i = 0; i < N/2; i++)
            {
                Console.WriteLine(2);
            }
            if (N % 2 == 1)
            {
                Console.WriteLine(1);
            }
        }
    }
}