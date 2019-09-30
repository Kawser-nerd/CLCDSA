using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }
        static void MainStream()
        {
            char[] s = Console.ReadLine().ToCharArray();
            if(Judge(s))
            {
                Console.WriteLine("AC");
            }
            else
            {
                Console.WriteLine("WA");
            }

        }
        static bool Judge(char[] s)
        {
            int C_count = 0;
            int C_index = 0;
            if (s[0] != 'A')
            {
                return false;
            }
            for (int i = 2; i < s.Length - 1; i++)
            {
                if (s[i] == 'C')
                {
                    C_count += 1;
                    C_index = i;

                    if(C_count > 1)//C?????
                    {
                        return false;
                    }

                }
            }
            if(C_count != 1)
            {
                return false;
            }
            for (int i = 1;i<s.Length;i++)
            {
                if (i != C_index)
                {
                    if (Char.IsUpper(s[i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }


    }
}