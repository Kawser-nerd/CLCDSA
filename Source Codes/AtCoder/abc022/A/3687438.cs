using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static int s;
        static int t;

        static void Main(string[] args)
        {
            //[summary]A - Best Body
            var line = ReadLine();
            int n = line[0];
            s = line[1];
            t = line[2];

            int w = int.Parse(Console.ReadLine());
            int count = 0;

            if (IsBestBody(w))
            {
                count++;
            }

            for (int i = 1; i < n; i++)
            {
                int a = int.Parse(Console.ReadLine());
                w += a;

                if (IsBestBody(w))
                {
                    count++;
                }
            }

            Console.WriteLine(count);
        }

        static bool IsBestBody(int w)
        {
            if (w >= s && w <= t)
            {
                return true;
            }
            else
            {
                return false;
            }
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
    }
}