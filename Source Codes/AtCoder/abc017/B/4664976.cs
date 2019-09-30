using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string X = Console.ReadLine();
            Console.WriteLine(CheckChoku(X) ? "YES" : "NO");

        }

        public static bool CheckChoku(string X)
        {
            if (X == "")
            {
                return true;
            }

            int i = 0;
            while(i < X.Length)
            {
                if (X[i] == 'o' || X[i] == 'k' || X[i] == 'u')
                {
                    i++;
                }
                else if (X[i] == 'c' && i == X.Length - 1)
                {
                    return false;
                }
                else if (X[i] == 'c' && X[i + 1] == 'h')
                {
                    i += 2;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    }
}