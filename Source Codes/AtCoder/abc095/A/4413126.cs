using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var S = Console.ReadLine();
            int ans = 700;
            for(int i = 0; i < 3; i++)
            {
                if (S[i] == 'o')
                {
                    ans += 100;
                }
            }
            Console.WriteLine(ans);
        }
    }
}