using System;

namespace agc019_b
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            long ret = (long)s.Length * (s.Length - 1) / 2;
            int[] count = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                count[s[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                ret -= (long)count[i] * (count[i] - 1) / 2;
            }
            Console.WriteLine(ret + 1);
        }
    }
}