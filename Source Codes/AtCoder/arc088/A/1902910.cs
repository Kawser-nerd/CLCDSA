using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApplication2
{
    public class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(" ".ToCharArray());
            long min = long.Parse(str[0]);
            long max = long.Parse(str[1]);
            int count = Contest(min, max);

            Console.WriteLine("{0}", count);
        }

        public static int Contest(long min, long max)
        {
            int count = 0;

            for (; min <= max; count++, min *= 2) ;

            return count;
        }
    }
}