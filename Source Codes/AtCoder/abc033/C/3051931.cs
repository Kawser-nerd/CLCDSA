using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_033
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Console.ReadLine();
            string[] sections = s.Split('+');
            int cnt = 0;
            for (int i = 0; i < sections.Length; i++)
            {
                if (!sections[i].Contains("0")) cnt++;
            }
            Console.WriteLine(cnt);
        }
    }
}