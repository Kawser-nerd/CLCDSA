using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            Parameter param = new Parameter(ReadLine());
            char[] name = ReadLine().ToCharArray();
            char[] kit = ReadLine().ToCharArray();
            int result = Calc(name, kit);
            WriteLine(result);
            ReadLine();
        }
        static int Calc(char[] name, char[] kit)
        {
            List<int> counter = new List<int>();
            foreach (var group in name.GroupBy(_ => _))
            {
                int cnt = kit.Count(_ => _ == group.Key);
                if (cnt == 0)
                    return -1;
                int max = (int)Math.Ceiling((double)group.Count() / cnt);
                counter.Add(max);
            }
            return counter.Max();
        }
    }
    class Parameter
    {
        public int N { get; set; }
        public int M { get; set; }
        public Parameter(string line)
        {
            string[] ar = line.Split(' ');
            N = int.Parse(ar[0]);
            M = int.Parse(ar[1]);
        }
    }
}