using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var x = new int[N];
            var y = new int[N];
            var c = new int[N];
            for (int i = 0; i < N; i++)
            {
                var buffer = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                x[i] = buffer[0];
                y[i] = buffer[1];
                c[i] = buffer[2];
            }

            var cTop = 1000.0;  //  OK
            while(!subSolve(x, c, cTop) || !subSolve(y, c, cTop)) { cTop *= 2; }
            var cBottom = 0.0;  //  NG
            while (cTop - cBottom > 0.00001)
            {
                var newc = (cTop + cBottom) / 2;
                if (subSolve(x, c, newc) && subSolve(y, c, newc))
                {
                    cTop = newc;
                }
                else
                {
                    cBottom = newc;
                }
            }
            Console.WriteLine(cBottom);
        }

        static bool subSolve(int[] x, int[] c, double C)
        {
            var r = C / c[0];
            double left = x[0] - r, right = x[0] + r;
            for (var j = 0; j < x.Length; j++)
            {
                var i = x[j];
                r = C / c[j];
                left = left < i - r ? i - r : left;
                right = right > i + r ? i + r : right;
                if (left > right) { return false; }
            }
            return true;
        }
    }
}