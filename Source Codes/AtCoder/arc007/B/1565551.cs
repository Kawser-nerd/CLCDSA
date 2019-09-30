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
            List<int> cases = Enumerable.Range(1, param.N).ToList();
            int current = 0;
            for (int m = 0; m < param.M; m++)
            {
                int play = int.Parse(ReadLine());
                int index = cases.IndexOf(play);
                if (index >= 0)
                {
                    int buf = cases[index];
                    cases[index] = current;
                    current = buf;
                }
            }

            foreach(int c in cases)
                 WriteLine(c);
            ReadLine();
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