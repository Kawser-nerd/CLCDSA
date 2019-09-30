using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - Otoshidama
            string s = Console.ReadLine();

            var opVariations = GetAllOpVariations(s).ToList();

            long sum = CalcSumOfAllVariations(s, opVariations);
            Console.WriteLine(sum);
        }

        static long CalcSumOfAllVariations(string s, List<string> opVariations)
        {
            var array = s.ToCharArray();
            long sum = 0;

            foreach(var op in opVariations)
            {
                string formula = "";

                for(int i = 0; i < s.Length; i++)
                {
                    formula += s[i].ToString();

                    try
                    {
                        if (op[i] == '1')
                        {
                            formula += '+';
                        }
                    }
                    catch (IndexOutOfRangeException)
                    {
                    }
                }

                sum += CalcSum(formula);
            }

            return sum;
        }

        static long CalcSum(string formula)
        {
            var list = formula.Split('+').ToList();
            return list.ConvertAll(x => long.Parse(x)).Sum();
        }

        static IEnumerable<string> GetAllOpVariations(string s)
        {
            int count = CountVariations(s);
            List<int> numbers = new List<int>();

            for(int i = 0; i < count; i++)
            {
                decimal d = ConvertNumberingFromDecimal(i, 2);
                numbers.Add((int)d);
            }

            int digits = numbers.Max().ToString().Length;
            
            foreach(int num in numbers)
            {
                yield return num.ToString().PadLeft(digits, '0');
            }
        }

        static int CountVariations(string s)
        {
            double d = s.Length - 1;
            return (int)Math.Pow(2, d);
        }

        static decimal ConvertNumberingFromDecimal(decimal sourceNumber, int bit)
        {
            //[summary]10??????n?????
            //??????????????????????
            //http://manabi.matiralab.com/binary/

            var list = new List<decimal>();
            decimal num = sourceNumber;

            //?????"n"?????????????
            while (num >= bit)
            {
                decimal mod = num % bit;
                list.Add(mod);

                num = Math.Floor(num / bit);
            }

            list.Add(num);

            //???????????????
            list.Reverse();

            //List?????????????
            string s = string.Join("", list);
            return decimal.Parse(s);
        }
    }
}