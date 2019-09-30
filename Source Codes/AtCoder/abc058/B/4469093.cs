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
            string O = Console.ReadLine();
            string E = Console.ReadLine();
            string ans = "";
            for (int i = 0; i < O.Length+E.Length; i++)
            {
                if (i%2==0)
                {
                    ans += O[i/2];
                }
                else
                {
                    ans += E[i/2];
                }
            }
            Console.WriteLine(ans);
        }

    }
}