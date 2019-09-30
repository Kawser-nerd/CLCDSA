using System;
using System.Collections.Generic;

namespace Beginner003B
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var T = Console.ReadLine();

            bool canWin = Jadge(S, T);
            if (canWin)
            {
                Console.WriteLine("You can win");
            }
            else
            {
                Console.WriteLine("You will lose");
            }
        }

        private static bool Jadge(string S, string T)
        {
            var wildCards = "atcoder@";

            for (int i = 0; i < S.Length; i++)
            {
                var sChar = S[i];
                var tChar = T[i];

                if (sChar == tChar)
                {
                    continue;
                }

                if (sChar != '@' && tChar != '@')
                {
                    return false;
                }

                if (!wildCards.Contains(sChar.ToString()) || !wildCards.Contains(tChar.ToString()))
                {
                    return false;
                }
            }

            return true;
        }
    }
}