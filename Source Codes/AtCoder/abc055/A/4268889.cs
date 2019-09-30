using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int ans = 800 * N - 200 * (N / 15);
            Console.WriteLine(ans);
        }
    }
}