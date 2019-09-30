using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - ??????
            int n = int.Parse(Console.ReadLine());

            //????????
            var meats = ReadLines(n).ToList();

            //?????????????????????????
            var patterns = CountPatterns(n);
            var numStrs = MyNumber.GetBinaryNumberStrings(patterns).ToList();

            if (n == 1)
            {
                Console.WriteLine(meats[0]);
            }
            else
            {
                int finishTime = GetFinishTimeToBakeMeat(meats, numStrs);
                Console.WriteLine(finishTime);
            }
        }

        static int GetFinishTimeToBakeMeat(List<int> meats, List<string> numStrs)
        {
            int ret = int.MaxValue;

            foreach (var numStr in numStrs)
            {
                int leftSide = meats[0];
                int rightSide = 0;

                for(int i = 0; i < numStr.Count(); i++)
                {
                    if (numStr[i] == '1')
                    {
                        leftSide += meats[i + 1];
                    }
                    else
                    {
                        rightSide += meats[i + 1];
                    }
                }

                int finishTime;

                if (leftSide > rightSide)
                {
                    finishTime = leftSide;
                }
                else
                {
                    finishTime = rightSide;
                }

                if (finishTime < ret)
                {
                    ret = finishTime;
                }
            }

            return ret;
        }

        static int CountPatterns(int n)
        {
            switch (n)
            {
                case 4:
                    return 6;
                case 3:
                    return 3;
                default:
                    return 1;
            }
        }

        static IEnumerable<int> ReadLines(int count = 0)
        {
            //[summary]????????????
            
            //???????????????1?????"count"????
            if (count == 0)
            {
                string s = Console.ReadLine().TrimEnd();
                count = int.Parse(s);
            }

            for (int i = 0; i < count; i++)
            {
                string s = Console.ReadLine().TrimEnd();
                yield return int.Parse(s);
            }
        }
    }

    class MyNumber
    {
        public static IEnumerable<string> GetBinaryNumberStrings(int count, int startNum = 0)
        {
            //[summary]????????????2???????????

            count += startNum;
            int max = count - 1;
            decimal d = ConvertNumeralSystem(max, 2);
            int digit = d.ToString().Length;

            for (int i = startNum; i < count; i++)
            {
                d = ConvertNumeralSystem(i, 2);
                string s = d.ToString().PadLeft(digit, '0');
                yield return s;
            }
        }

        static decimal ConvertNumeralSystem(decimal sourceNumber, int n)
        {
            //[summary]10??????n?????
            //??????????????????????
            //http://manabi.matiralab.com/binary/

            var list = new List<decimal>();
            decimal num = sourceNumber;

            //?????"n"?????????????
            while (num >= n)
            {
                decimal mod = num % n;
                list.Add(mod);

                num = Math.Floor(num / n);
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