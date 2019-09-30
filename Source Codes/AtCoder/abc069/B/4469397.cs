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
            Console.WriteLine(
                s[0] +""+ s.Substring(1, s.Length - 2).Length + s[s.Length - 1]
                );
        }

    }
}