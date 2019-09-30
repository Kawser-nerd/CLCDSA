using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrr
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int obj = int.Parse(s[0] + s[1]);

            string ans = "No";
            for (int i = 0; i <317; i++)
            {
                if(i * i == obj)
                {
                    ans = "Yes";
                    break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}