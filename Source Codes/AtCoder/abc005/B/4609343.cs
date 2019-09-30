using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - ????????????
            var times = ReadLines();

            Console.WriteLine(times.Min());            
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