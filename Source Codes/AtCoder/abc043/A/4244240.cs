using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int ans = 0;
            for(int i = 1; i <= N; i++)
            {
                ans += i;
            }
            Console.WriteLine(ans);
        }
    }
}