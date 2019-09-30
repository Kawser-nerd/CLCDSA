using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static int L, X, Y, S, D;
        static void Main(string[] args)
        {

            var ret = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            L = ret[0];
            X = ret[1];
            Y = ret[2];
            S = ret[3];
            D = ret[4];

            double a=0.0;
            if (D > S)
            {
                double a1, a2=-1;
                a1 = (double)(D - S) / (X + Y);
                if (X < Y) a2 = (double)(L + S - D) / (Y - X);
                a = (a1 < a2) ? a1 : (a2 > 0) ? a2 : a1;
            }else if (D < S)
            {
                double a1, a2 = -1;
                a1 = (double)(D + L - S) / (X + Y);
                if (X < Y) a2 = (double)(S - D) / (Y - X);
                a = (a1 < a2) ? a1 : (a2 > 0) ? a2 : a1;
            }

            Console.WriteLine(a);
        }
    }
}