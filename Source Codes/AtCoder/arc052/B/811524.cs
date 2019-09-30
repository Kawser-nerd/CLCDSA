using System;
using System.Text.RegularExpressions;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var n = Int32.Parse(str[0]);
            var q = Int32.Parse(str[1]);
            var x = new int[n];
            var r = new int[n];
            var h = new int[n];
            var a = new int[q];
            var b = new int[q];
            for (int i = 0; i < n; i++)
            {
                str = Console.ReadLine().Split();
                x[i] = Int32.Parse(str[0]);
                r[i] = Int32.Parse(str[1]);
                h[i] = Int32.Parse(str[2]);
            }
            for (int i = 0; i < q; i++)
            {
                str = Console.ReadLine().Split();
                a[i] = Int32.Parse(str[0]);
                b[i] = Int32.Parse(str[1]);
            }

            var v = new double[20001];
            for (int p = 1; p < 20001; p++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (p <= x[i]) continue;
                    var v1 = (1.0 / 3.0) * Math.PI * Math.Pow((double)r[i], 2) * (double)h[i];
                    var v2 = p >= x[i] + h[i] ? 0 : (1.0 / 3.0) * Math.PI * Math.Pow((double)r[i] * ((double)(h[i] - (p - x[i])) / (double)h[i]), 2) * (double)(h[i] - (p - x[i]));
                    v[p] += (v1 - v2);
                }
            }

            //result
            for (int i = 0; i < q; i++)
            {
                Console.WriteLine(v[b[i]] - v[a[i]]);
            }
        }
    }
}