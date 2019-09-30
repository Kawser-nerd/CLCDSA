using System;
using System.CodeDom;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Problem1B
{
    class Program
    {
        static void Main(string[] args)
        {
            var testName = args[0];

            using (var reader = new StreamReader($"{testName}.in"))
            using (var writer = new StreamWriter($"{testName}.out"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var number = reader.ReadLine();

                    var tidy = GetTidyNumber(number);

                    writer.WriteLine("Case #{0}: {1}", caseId, tidy);
                    writer.Flush();
                }
            }
        }

        private static string GetTidyNumber(string number)
        {
            var digits = number.Select(c => c - '0').ToArray();

            bool adjusted;
            do
            {
                adjusted = false;
                for (var index = digits.Length - 1; index >= 1; index--)
                {
                    var digit = digits[index];
                    var prevDigit = digits[index - 1];

                    if (digit < prevDigit)
                    {
                        digits[index - 1] = prevDigit - 1;
                        for (; index < digits.Length; index++)
                        {
                            digits[index] = 9;
                        }
                        adjusted = true;
                        break;
                    }
                }
            }
            while (adjusted);


            return new string(digits.SkipWhile(d => d == 0).Select(c => (char)(c + '0')).ToArray());
        }
    }
}
