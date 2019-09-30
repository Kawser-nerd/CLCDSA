using System;

namespace agc016_a
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int[] ret = new int[26];
            for (int i = 'a'; i <= 'z'; i++)
            {
                int max = 0;
                int now = 0;
                for (int j = 0; j < s.Length; j++)
                {
                    if (s[j] == (char)i)
                    {
                        max = Math.Max(max, now); now = 0;
                    }
                    else
                    {
                        now++;
                    }
                }
                max = Math.Max(max, now);
                ret[i - 97] = max;
            }
            Array.Sort(ret);
            Console.WriteLine(ret[0]);
        }
    }
}