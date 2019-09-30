using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var S = Console.ReadLine();
            int ans = 0;
            for(int i = 0; i < 4; i++)
            {
                if (S[i] == '+')
                {
                    ans++;
                }
                else
                {
                    ans--;
                }
            }
            Console.WriteLine(ans);
        }
    }
}