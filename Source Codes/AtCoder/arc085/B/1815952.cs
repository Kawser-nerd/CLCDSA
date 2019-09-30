using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    public class AtCoder20171111D
    {
        static void Main(string[] args)
        {
            var s1 = Console.ReadLine();
            var s2 = Console.ReadLine();
            
            Console.WriteLine(funcMain(s1,s2));

            Console.ReadKey();
        }

        static public string funcMain(string arg1, string arg2)
        {
            long ret = 0;
            var list1 = arg1.Split().Select(f => long.Parse(f)).ToList();
            var list2 = arg2.Split().Select(f => long.Parse(f)).ToList();

            int N = (int)list1[0];
            long X = list1[1];
            long Y = list1[2];

            try {
                ret = Math.Max(Math.Abs(list2[N - 1] - list2[N - 2]), Math.Abs(list2[N - 1] - Y));
            }
            catch {
                ret = Math.Abs(list2[0] - Y);
            }

            return ret.ToString();
        }
    }
}