using System;

namespace agc015_b
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            long ret = 0;
            int n = s.Length;
            for (int i = 0; i < n; i++)
            {
                ret += n - 1;
                if (s[i] == 'U') ret += i;
                else ret += n - i - 1;
            }
            Console.WriteLine(ret);
        }
    }
}