using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            Console.WriteLine(N % 10 == 9 || N >= 90 ? "Yes" : "No");
        }
    }
}