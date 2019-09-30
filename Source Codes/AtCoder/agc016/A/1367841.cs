using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.AGC016
{
    class Shrinking
    {
        public static void Main()
        {
            var alphabet = "abcdefghijklmnopqrstuvwxyz";
            var prev = new Dictionary<char, int>();
            var max = new Dictionary<char, int>();
            foreach(var c in alphabet) {
                prev.Add(c, -1); max.Add(c, -1);
            }
            var s = ReadLine().Trim();
            for (var i = 0; i < s.Length; ++i) {
                if (max[s[i]] < i - prev[s[i]] - 1) {
                    max[s[i]] = i - prev[s[i]] - 1;
                }
                prev[s[i]] = i;
            }
            foreach(var c in alphabet) {
                if (max[c] < s.Length - prev[c] - 1) {
                    max[c] = s.Length - prev[c] - 1;
                }
            }
            WriteLine(max.Where(_ => _.Value >= 0).Min(_ => _.Value));

        }
    }
}