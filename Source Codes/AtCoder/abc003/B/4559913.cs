using System;
using System.Linq;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var T = Console.ReadLine();
            var data = "atcoder";
            var ans = true;

            for (int i = 0; i < S.Length; i++)
            {
                if (S[i] == '@' && data.Contains(T[i]))
                {
                    ans = true;
                }
                else if (T[i] == '@' && data.Contains(S[i]))
                {
                    ans = true;
                }
                else if (S[i] == T[i])
                {
                    ans = true;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            Console.WriteLine(ans? "You can win": "You will lose");
        }
    }
}