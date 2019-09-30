using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int[] ls = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                ls[s[i] - 'a']++;
            }
            int odd = 0;
            int even = 0;
            for (int i = 0; i < ls.Length; i++)
            {
                odd += ls[i] % 2;
                even += ls[i] / 2;
            }
            if (odd < 2) Console.WriteLine(s.Length);
            else
            {
                Console.WriteLine(1 + even / odd * 2);
            }
        }
    }
}