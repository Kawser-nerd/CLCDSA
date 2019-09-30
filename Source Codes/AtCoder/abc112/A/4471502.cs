using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            if (N == 1)
            {
                Console.WriteLine("Hello World");
            }
            else
            {
                int A = int.Parse(Console.ReadLine());
                int B = int.Parse(Console.ReadLine());
                Console.WriteLine(A + B);
            }
        }
    }
}