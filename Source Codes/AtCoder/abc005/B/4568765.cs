using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int ans = 999;

            for(int i = 0; i < N; i++)
            {
                int t = int.Parse(Console.ReadLine());
                ans = Math.Min(ans, t);
            }
            Console.WriteLine(ans);
        }
    }
}