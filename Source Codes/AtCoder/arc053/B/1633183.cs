using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc053_b
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int[] a = new int[26];
            for (int i = 0; i < str.Length; i++)
            {
                a[str[i] - 'a']++;
            }
            int ki = 0;
            int gu = 0;
            for (int i = 0; i < 26; i++)
            {
                gu += a[i] / 2;
                if (a[i] % 2 == 1) { ki++; }
            }
            if (ki == 0) { Console.WriteLine(str.Length);return; }
            Console.WriteLine((gu/ki)*2+1);
            Console.ReadLine();
        }
    }
}