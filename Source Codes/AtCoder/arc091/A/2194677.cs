using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp15
{
    class Program
    {
        static void Main(string[] args)
        {
            ulong[] NM = Console.ReadLine().Split().Select(ulong.Parse).ToArray();
            var n = NM[0];
            var m = NM[1];
            ulong ans = 0;
            if (n == 1)
            {
                if (m==1)
                {
                    ans = 1;
                }else
                {
                    ans = m - 2;
                }
            }else
            {
                if (m==1)
                {
                    ans = n - 2;
                } else
                {
                    ans = (n - 2) * (m - 2);
                }
            }
            Console.WriteLine(ans);
        }
    }
}