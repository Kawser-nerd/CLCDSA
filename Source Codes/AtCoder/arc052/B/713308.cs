using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] nq = Console.ReadLine().Split(' ');
            int n = int.Parse(nq[0]);
            int q = int.Parse(nq[1]);
            int[] x = new int[n];
            int[] r = new int[n];
            int[] h = new int[n];
            int[] a = new int[q];
            int[] b = new int[q];

            for (int i = 0; i < n; i++)
            {
                string[] xrh = Console.ReadLine().Split(' ');
                x[i] = int.Parse(xrh[0]);
                r[i] = int.Parse(xrh[1]);
                h[i] = int.Parse(xrh[2]);
            }
            for (int i = 0; i < q; i++)
            {
                string[] ab = Console.ReadLine().Split(' ');
                a[i] = int.Parse(ab[0]);
                b[i] = int.Parse(ab[1]);
                double ans = 0;
                for (int j = 0; j < n; j++)
                {
                    int bgn = Math.Max(a[i], x[j]);
                    int end = Math.Min(b[i], x[j] + h[j]);
                    if (b[i] < bgn || end < a[i])
                    {
                        continue;
                    }
                    double low = ((double)x[j] + h[j] - bgn) / h[j];
                    double upp = ((double)x[j] + h[j] - end) / h[j];


                    ans += (Math.Pow(low,3)- Math.Pow(upp,3)) * 
                        Math.Pow(r[j],2) * h[j];
                }

                Console.WriteLine(ans * Math.PI / 3);
            }
        }
    }
}