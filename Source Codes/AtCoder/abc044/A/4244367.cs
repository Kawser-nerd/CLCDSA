using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int K = int.Parse(Console.ReadLine());
            int X = int.Parse(Console.ReadLine());
            int Y = int.Parse(Console.ReadLine());

            int ans = 0;
            if (N > K)
            {
                ans = X * K + Y * (N - K);
            }
            else
            {
                ans = X * N;
            }
            Console.WriteLine(ans);
        }
    }
}