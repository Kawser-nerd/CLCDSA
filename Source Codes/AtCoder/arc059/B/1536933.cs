using System;

namespace arc059_b
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            bool ret = false;
            for (int i = 1; i < s.Length && !ret; i++)
            {
                if (s[i - 1] == s[i])
                {
                    ret = true;
                    Console.WriteLine(i + " " + (i + 1));
                }
            }
            for (int i = 2; i < s.Length && !ret; i++)
            {
                if (s[i - 2] == s[i])
                {
                    ret = true;
                    Console.WriteLine((i - 1) + " " + (i + 1));
                }
            }
            if (!ret)
            {
                Console.WriteLine("-1 -1");
            }
        }
    }
}