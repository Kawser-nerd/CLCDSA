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

            if (n == 1)
            {
                Console.WriteLine(meats[0]);
                return;
            }

            //?????????????????????????
            var patterns = (int)Math.Pow(2, n);
            var numStrs = MyNumber.GetBinaryNumberStrings(patterns).ToList();
            numStrs = DeletedDoubledNumStrs(numStrs, n);

            int finishTime = GetFinishTimeToBakeMeat(meats, numStrs);
            Console.WriteLine(finishTime);
        }

        static int GetFinishTimeToBakeMeat(List<int> meats, List<string> numStrs)
        {
            int ret = int.MaxValue;

            foreach (var numStr in numStrs)
            {
                int leftSide = 0;
                int rightSide = 0;

                for(int i = 0; i < numStr.Count(); i++)
                {
                    if (numStr[i] == '1')
                    {
                        leftSide += meats[i];
                    }
                    else
                    {
                        rightSide += meats[i];
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

        static List<string> DeletedDoubledNumStrs(List<string> numStrs, int n)
        {
            var dic = new Dictionary<string, string>();

            foreach(var numStr in numStrs)
            {
                int count = numStr.Count(c => c == '1');

                if (count != 0 && count != n)
                {
                    string value = "";

                    foreach(char c in numStr)
                    {
                        if (c == '1')
                        {
                            value += "0";
                        }
                        else
                        {
                            value += "1";
                        }
                    }

                    if (!dic.ContainsValue(numStr))
                    {
                        dic.Add(numStr, value);
                    }
                }
            }

            return dic.Keys.ToList();
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