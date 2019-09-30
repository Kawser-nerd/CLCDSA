using System;

namespace ABC071B
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            bool[] chk = new bool[26];

            for (int i = 0; i < str.Length; i++)
            {
                chk[str[i] - 'a'] = true;
            }

            for (int i = 0; i < 26; i++)
            {
                if (!chk[i])
                {
                    Console.WriteLine((char)('a' + i));
                    return;
                }
            }

            Console.WriteLine("None");
        }
    }
}