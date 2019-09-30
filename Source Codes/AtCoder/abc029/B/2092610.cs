using System;
using System.Collections.Generic;
using System.Linq;


namespace AtCoder
{
    class Program
    {
        public static void Main()
        {
            new Program().Solve();
        }

        void Solve()
        {
            int count = 0;
            for (int i = 0; i < 12; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < s.Length; j++)
                {
                    if(s[j]=='r')
                    {
                        count++;
                        break;
                    }
                }
            }
            Console.WriteLine(count);
        }

    }
}