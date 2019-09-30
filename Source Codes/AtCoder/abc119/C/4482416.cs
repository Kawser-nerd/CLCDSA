using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static int[] goals;

        static void Main(string[] args)
        {
            //[summary]C - Synthetic Kadomatsu
            var line = ReadLine();
            int n = line[0];

            //???????????
            goals = new int[] { line[1], line[2], line[3] };

            //?????????
            var materials = ReadLines(n);

            //?????????? A,B,C???,???? ??????????????????
            var numStrs = GetBase4NumberStrings(n).ToList();

            int minMp = int.MaxValue;

            foreach(var numStr in numStrs)
            {
                //??List???
                var bambooCombis = new List<List<int>>();

                for(int i = 0; i < 3; i++)
                {
                    bambooCombis.Add(new List<int>());
                }

                for(int i = 0; i < n; i++)
                {
                    if (numStr[i] != '3')
                    {
                        int index = GetIndex(numStr[i]);

                        bambooCombis[index].Add(materials[i]);
                    }
                }

                int mp = CalcMp(bambooCombis);

                if (mp < minMp)
                {
                    minMp = mp;
                }
            }

            Console.WriteLine(minMp);
        }

        static int CalcMp(List<List<int>> bambooCombis)
        {
            int sum = 0;
            int i = 0;

            foreach(var bamboos in bambooCombis)
            {
                if (bamboos.Count == 0)
                {
                    return int.MaxValue;
                }
                else
                {
                    int length = bamboos.Sum();
                    int mp = (bamboos.Count - 1) * 10;

                    mp += Math.Abs(goals[i] - length);
                    sum += mp;
                }

                i++;
            }

            return sum;
        }

        static int GetIndex(char numChar)
        {
            string s = numChar.ToString();
            return int.Parse(s);
        }

        static IEnumerable<string> GetBase4NumberStrings(int n)
        {
            //[summary]?????????? A,B,C???,???? ???????????

            int count = (int)Math.Pow(4, n);

            string s = ConvertBaseNumber(count - 1, 4);
            int digit = s.Length;

            for(int i = 0; i < count; i++)
            {
                s = ConvertBaseNumber(i, 4);
                yield return s.PadLeft(digit, '0');
            }
        }

        static string ConvertBaseNumber(int sourceNum, int n)
        {
            //[summary]10??????N?????
            //??????????????????????
            //http://manabi.matiralab.com/binary/

            var mods = new List<int>();
            int num = sourceNum;

            //?????"n"?????????????
            while (num != 0 && num != 1)
            {
                mods.Add(num % n);
                num /= n;
            }

            //????????
            mods.Add(num);

            //???????????????
            mods.Reverse();

            //??????????????????????????
            mods = mods.SkipWhile(x => x == 0).ToList();

            //List?????
            return string.Join("", mods);
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine().TrimEnd();
            var array = line.Split(' ');
            var numbers = new List<int>();

            foreach (var s in array)
            {
                int num = int.Parse(s);
                numbers.Add(num);
            }

            return numbers;
        }

        static List<int> ReadLines(int count = 0)
        {
            //[summary]????????????
            var list = new List<int>();

            //???????????????1?????"count"????
            if (count == 0)
            {
                string s = Console.ReadLine().TrimEnd();
                count = int.Parse(s);
            }

            for (int i = 0; i < count; i++)
            {
                string s = Console.ReadLine().TrimEnd();
                list.Add(int.Parse(s));
            }

            return list;
        }
    }
}