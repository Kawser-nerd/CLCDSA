using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace R1_2
{
    class Program
    {
        static void Main(string[] args)
        {
            string filePath = @"C:\B-large (1).in";

            string[] results = null;
            using (StreamReader reader = new StreamReader(filePath))
            {
                int T = int.Parse(reader.ReadLine());
                results = new string[T];
                for (int i = 1; i <= T; i++)
                {
                    var number = reader.ReadLine();
                    results[i-1] = NextNumber(number);
                }
            }

            using (StreamWriter writer = new StreamWriter(@"C:\result.txt"))
            {
                for (int i = 0; i < results.Length; i++)
                    writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, results[i].ToString()));
            }
        }

        public static string NextNumber(string CurrentNumber)
        {
            var digits = CurrentNumber.ToList();

            if (IsSorted(digits))
            {
                var lowest = digits.Where(d => d > '0').Min();
                digits.Remove(lowest);
                return lowest.ToString() + "0" + new string(digits.OrderBy(c => c).ToArray());
            }

            int indexToSwap = -1;

            for (indexToSwap = CurrentNumber.Length; indexToSwap > 0; indexToSwap--)
            {
                var remaining = CurrentNumber.Skip(indexToSwap).ToList();
                if (!IsSorted(remaining))
                    break;
            }

            string digitsBeforeSwap = "";
            for (int i = 0; i < indexToSwap; i++)
            {
                digitsBeforeSwap += digits[0];
                digits.RemoveAt(0);
            }

            var newLowest = digits.Skip(1).Where(d => d > digits[0]).Min();
            digits.Remove(newLowest);
            return digitsBeforeSwap + newLowest.ToString() + new string(digits.OrderBy(c => c).ToArray());
        }

        public static bool IsSorted(IList<char> Digits)
        {
            char currentDigit = '9';
            for (int i = 0; i < Digits.Count; i++)
            {
                if (Digits[i] > currentDigit) return false;
                currentDigit = Digits[i];
            }

            return true;
        }
    }
}
