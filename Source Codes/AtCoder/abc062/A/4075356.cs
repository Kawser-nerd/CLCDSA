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
            int[] one = { 1, 3, 5, 7, 8, 10, 12 };
            int[] two = { 4, 6, 9, 11 };
            string[] s = Console.ReadLine().Split(' ');
            int x = int.Parse(s[0]);
            int y = int.Parse(s[1]);

            string ans = "No";
            if (one.Contains(x) && one.Contains(y))
            {
                ans = "Yes";
            }
            if (two.Contains(x) && two.Contains(y))
            {
                ans = "Yes";
            }
            if(x == y && x == 2)
            {
                ans = "Yes";
            }
            Console.WriteLine(ans);
        }
    }
}