using System;
using System.Linq;

namespace BeginnerContest_003_B
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string t = Console.ReadLine();

            var replace = new char[] { 'a', 't', 'c', 'o', 'd', 'e', 'r' };

            if (s == t)
            {
                Console.WriteLine("You can win");
                return;
            }

            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] != t[i])
                {
                    if ((s[i] == '@' && !replace.Contains(t[i])) ||
                        (t[i] == '@' && !replace.Contains(s[i])))
                    {
                        Console.WriteLine("You will lose");
                        return;
                    }
                    else if (s[i] != '@' && t[i] != '@')
                    {
                        Console.WriteLine("You will lose");
                        return;
                    }
                }
            }
            Console.WriteLine("You can win");
        }
    }
}