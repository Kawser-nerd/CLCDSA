using System;

namespace ABC076C
{
    class Program
    {
        static void Main(string[] args)
        {
            string Sp = Console.ReadLine();
            string T = Console.ReadLine();
            string S = "UNRESTORABLE";

            for (int i = Sp.Length - T.Length; i >= 0; i--)
            {
                bool match = true;

                for (int j = 0; j < T.Length; j++)
                {
                    if (Sp[i + j] != '?' && Sp[i + j] != T[j])
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                {
                    S = string.Empty;
                    for (int j = 0; j < Sp.Length; j++)
                    {
                        char c = '?';
                        if (Sp[j] == '?')
                        {
                            int k = j - i;
                            if (0 <= k && k < T.Length)
                            {
                                c = T[k];
                            }
                            else
                            {
                                c = 'a';
                            }
                        }
                        else
                        {
                            c = Sp[j];
                        }
                        S += c;
                    }
                    break;
                }
            }

            Console.WriteLine(S);
        }
    }
}