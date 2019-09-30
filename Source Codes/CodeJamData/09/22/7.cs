using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GCJ20091BB {
    class Program {
        private string NextNumber(string number) {
            char[] digits = number.ToCharArray().Reverse().ToArray();
            int pFirstDecr;
            for (pFirstDecr = 1; pFirstDecr < digits.Length; ++pFirstDecr)
                if (digits[pFirstDecr] < digits[pFirstDecr - 1]) break;
            if (pFirstDecr == digits.Length) {
                // Greatest number, create a new number inserting a zero
                List<char> newDigits = digits.ToList();
                newDigits.Add('0');
                newDigits.Sort();
                digits = newDigits.ToArray();
                for (int i = 0; i < digits.Length; ++i) {
                    if (digits[i] != '0') {
                        Debug.Assert(digits[0] == '0');
                        digits[0] = digits[i];
                        digits[i] = '0';
                        break;
                    }
                }
                return new string(digits);
            }
            else {
                // Need to rearrange till first decr
                int nextBiggestAt = pFirstDecr - 1;
                for (int i = 0; i < pFirstDecr - 1; ++i) {
                    if (digits[i] > digits[pFirstDecr] && digits[i] < digits[nextBiggestAt]) nextBiggestAt = i;
                }
                char t = digits[pFirstDecr];
                digits[pFirstDecr] = digits[nextBiggestAt];
                digits[nextBiggestAt] = t;
                char[] part1 = digits.Take(pFirstDecr).ToArray();
                Array.Sort(part1);  // This part need not be reversed
                char[] part2 = digits.Skip(pFirstDecr).Reverse().ToArray();
                return new string(part2) + new string(part1);
            }
        }
        public Program() {
            int nCases = int.Parse(Console.ReadLine());
            for (int i = 0; i < nCases; ++i) {
                Console.WriteLine("Case #{0}: {1}", i + 1, NextNumber(Console.ReadLine()));
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
