using System;

namespace ABC063B
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            bool[] chk = new bool[26];

            for (int i = 0; i < str.Length; i++)
            {
                if (chk[str[i] - 'a'])
                {
                    Console.WriteLine("no");
                    return;
                }
                chk[str[i] - 'a'] = true;
            }

            Console.WriteLine("yes");
        }
    }
}