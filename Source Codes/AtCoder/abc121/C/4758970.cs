using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            label:
            var sp = ReadLine().Split();
            int n = Parse(sp[0]);
            int m = Parse(sp[1]);
            var sort = new SortedList<int, int>();
            for (int i = 0; i < n; ++i)
            {
                sp = ReadLine().Split();
                int a = Parse(sp[0]);
                int b = Parse(sp[1]);
                int val;
                if (sort.TryGetValue(a, out val))
                {
                    sort[a] = val + b;
                }
                else
                {
                    sort[a] = b;
                }
            }
            long result = 0;
            foreach (var pair in sort)
            {
                if (pair.Value < m)
                {
                    m -= pair.Value;
                    result += (long)(pair.Key) * pair.Value;
                }
                else
                {
                    result += (long)(pair.Key) * m;
                    break;
                }
            }
            WriteLine(result);
            //goto label;
        }
    }
}