using System;

namespace arc035_a
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            bool flag = true;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] != s[s.Length - i - 1] && s[i] != '*' && s[s.Length - i - 1] != '*')
                {
                    flag = false;
                }
            }
            Console.WriteLine(flag ? "YES" : "NO");
        }
    }
}