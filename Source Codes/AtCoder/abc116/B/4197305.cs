using System;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var s = int.Parse(str);

            var aList = new List<int>();
            aList.Add(s);
            var a = s;
            var i = 2;
            while (true)
            {
                if (a % 2 == 0)
                {
                    a = a / 2;
                }
                else
                {
                    a = a * 3 + 1;
                }

                if (aList.Contains(a))
                {
                    Console.WriteLine(i);
                    return;
                }

                aList.Add(a);
                i++;
            }
        }
    }
}