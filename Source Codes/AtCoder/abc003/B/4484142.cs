using System;

namespace ABC003B
{
    class Program
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            string T = Console.ReadLine();
            bool victory = false;
            
            for(var i = 0; i < S.Length; i++)
            {

                victory = false;

                if(S[i] != T[i])
                {
                    if(S[i] == '@')
                    {
                        if(T[i] == 'a' || T[i] == 't' || T[i] == 'c' || T[i] == 'o' || T[i] == 'd' || T[i] == 'e' || T[i] == 'r')
                        {
                            victory = true;
                        }
                    }
                    else if(T[i] == '@')
                    {
                        if (S[i] == 'a' || S[i] == 't' || S[i] == 'c' || S[i] == 'o' || S[i] == 'd' || S[i] == 'e' || S[i] == 'r')
                        {
                            victory = true;
                        }
                    }
                }
                else
                {
                    victory = true;
                }

                if (!victory)
                {
                    break;
                }
            }

            if (victory)
            {
                Console.WriteLine("You can win");
            }
            else
            {
                Console.WriteLine("You will lose");
            }
        }
    }
}