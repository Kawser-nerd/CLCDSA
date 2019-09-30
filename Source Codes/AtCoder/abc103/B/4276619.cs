using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class AtCodeeeeeeeeeeeeeeeeeeeer
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string t = Console.ReadLine();
            string ans = "No";
            for (int i = 0; i < s.Length; i++)
            {
                s = s.Substring(1, s.Length - 1) + s[0];
                if (s == t)
                {
                    ans = "Yes";
                }
            }
            Console.WriteLine(ans);
        }
    }
}