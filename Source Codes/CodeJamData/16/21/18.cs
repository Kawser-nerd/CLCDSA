using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016R1
{
    class R1A
    {
        public static object Solve()
        {
            var str = new[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
            var s = Console.ReadLine();
            var ar = new int[256];
            foreach (var c in s)
                ar[c]++;
            var num = new int[10];
            num[0] = ar['Z'];
            num[2] = ar['W'];
            num[4] = ar['U'];
            num[6] = ar['X'];
            foreach (var i in new[] { 0, 2, 4, 6 })
                foreach (var c in str[i])
                    ar[c] -= num[i];
            num[3] = ar['R'];
            num[5] = ar['F'];
            foreach (var i in new[] { 3, 5 })
                foreach (var c in str[i])
                    ar[c] -= num[i];
            num[7] = ar['V'];
            num[8] = ar['T'];
            foreach (var i in new[] { 7, 8 })
                foreach (var c in str[i])
                    ar[c] -= num[i];
            num[1] = ar['O'];
            num[9] = ar['I'];
            var ret = "";
            for (var i = 0; i < 10; i++)
                ret += new string((char)('0' + i), num[i]);
            return ret;
        }
    }
}