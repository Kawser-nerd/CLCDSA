using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.AGC015
{
    class B
    {
        public static void Main()
        {
            var s = ReadLine().Trim();
            long res = 0;
            for (var i = 0; i < s.Length; ++i) {
                switch (s[i]) {
                case 'U':
                    res += s.Length - i - 1;
                    res += 2 * i;
                    break;
                default:
                    res += 2 * (s.Length - i - 1);
                    res += i;
                    break;
                }
            }
            WriteLine(res);
        }

    }
}