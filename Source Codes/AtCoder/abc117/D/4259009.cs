using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static int n;
        static long k;
        
        static void Main(string[] args)
        {
            //[summary]D - XXOR
            var line = ReadLine().ToList();
            n = (int)line[0];
            k = line[1];

            var a = ReadLine().ToList();

            //"a"????????2?????????????????????"1"?????????
            //(???????????40)
            var digits = new int[40];

            for(int i = 0; i < n; i++)
            {
                //2???????????
                //("digits"???????????????????????)
                var binaries = ConvertToReverseChars(a[i]);

                for(int j = 0; j < binaries.Count(); j++)
                {
                    if (binaries[j] == '1')
                    {
                        digits[j]++;
                    }
                }
            }

            //????????("k"???????????)
            string result = GetMaxBinary(digits);

            long num = Convert.ToInt64(result, 2);

            while (num > k)
            {
                num = GetOtherNumber(num);
            }

            long sum = 0;

            foreach(var ai in a)
            {
                sum += ai ^ num;
            }

            Console.WriteLine(sum);
        }

        static long GetOtherNumber(long num)
        {
            string s = GetBinaryString(num);
            var kStr = GetBinaryString(k);

            for(int i = 0; i < s.Length; i++)
            {
                if (s[i] == '1' && kStr[i] == '0')
                {
                    string left = s.Substring(0, i);
                    string right = s.Substring(i + 1, s.Length - i - 1);

                    return Convert.ToInt64(left + "0" + right, 2);
                }
            }

            return 0;
        }

        static string GetMaxBinary(int[] digits)
        {
            //"k"?2?????
            var kChars = ConvertToReverseChars(k);
            string s = "";

            for (int i = 0; i < kChars.Length; i++)
            {
                int oneCount = digits[i];
                int zeroCount = n - oneCount;

                if (oneCount > zeroCount)
                {
                    s += '0';
                }
                else
                {
                    s += '1';
                }
            }

            var array = ReverseBinary(s);
            return String.Join("", array);
        }

        static char[] ConvertToReverseChars(long num)
        {
            //[summary]???2???????????

            var s = GetBinaryString(num);
            return ReverseBinary(s);
        }

        static char[] ReverseBinary(string binary)
        {
            return binary.Reverse().ToArray();
        }

        static string GetBinaryString(long num)
        {
            //[summary]???2?????

            return Convert.ToString(num, 2);
        }

        static IEnumerable<long> ReadLine()
        {
            var line = Console.ReadLine().TrimEnd();
            var array = line.Split(' ');

            foreach (var s in array)
            {
                yield return long.Parse(s);
            }
        }
    }
}