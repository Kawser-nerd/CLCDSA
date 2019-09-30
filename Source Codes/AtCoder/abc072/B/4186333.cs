using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Piza
{
    class Paiza
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string ans = "";
            for (int i = 0; i < s.Length; i++)
            {
                if(i % 2 == 0)
                {
                    ans += s[i].ToString();
                }
            }
            Console.WriteLine(ans);
        }
    }
}