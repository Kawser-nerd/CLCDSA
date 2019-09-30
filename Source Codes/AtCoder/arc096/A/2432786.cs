using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ARC96_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = ReadLine().Split();
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);
            int c = int.Parse(s[2]);
            int x = int.Parse(s[3]);
            int y = int.Parse(s[4]);

            long m = (long)5000 * 1000000;
            for (int i = 0; i <= Math.Max(x,y); i++)
            {
                m = Math.Min(m, c * 2 * i + a * Math.Max(x - i, 0) + b * Math.Max(y - i, 0));
            }
            WriteLine(m);
        }
    }
}