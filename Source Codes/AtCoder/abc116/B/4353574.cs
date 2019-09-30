using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            var S = int.Parse(ReadLine());
            var list = new List<long>();
            foreach (var item in Calc(S))
            {
                if (list.Contains(item))
                {
                    WriteLine(list.Count + 1);
                    break;
                }
                else list.Add(item);
            }
        }

        static IEnumerable<long> Calc(int s)
        {
            long num = s;
            for (int i = 0; ; i++)
            {
                if (i == 0) yield return s;
                num = num % 2 == 0 ? num / 2 : 3 * num + 1;
                yield return num;
            }
        }
    }
}