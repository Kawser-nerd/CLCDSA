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
            string ans = "None";
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (s.Contains(i)==false)
                {
                    ans = i.ToString();
                    break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}