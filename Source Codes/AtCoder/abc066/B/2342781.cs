using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.Globalization;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            String S = Console.ReadLine();
            int ans = 0;

            for (int i = 1; i < S.Count(); i++)
            {
                if ((S.Count() - i )% 2 == 0)
                {
                    int Length = ((S.Count() - i) / 2) -1;
                    if (S.Substring(0, Length) == S.Substring(Length + 1, Length))
                    {
                        ans = S.Count() - i;
                        break;
                    }
                }
            }
            Console.WriteLine(ans);
        }
    }
}