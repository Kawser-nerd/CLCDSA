using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int ans = N / 2;
            if (N % 2 != 0)
            {
                ans += 1;
            }
            Console.WriteLine(ans);
        }
    }
}