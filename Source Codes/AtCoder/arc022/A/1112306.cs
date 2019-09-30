using System;

namespace arc022_1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            s = s.ToUpper();
            int I = 0;
            int C = 0;
            int T = 0;
            bool i = false;
            bool c = false;
            bool t = false;
            for (int j = 0; j < s.Length && !i; j++)
            {
                if (s[j] == 'I')
                {
                    I = j;
                    i = true;
                }
            }
            for (int j = I; j < s.Length && !c; j++)
            {
                if (s[j] == 'C')
                {
                    C = j;
                    c = true;
                }
            }
            for (int j = C; j < s.Length && !t; j++)
            {
                if (s[j] == 'T')
                {
                    T = j;
                    t = true;
                }
            }
            Console.WriteLine(i && c && t ? "YES" : "NO");
        }
    }
}