using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //    var data = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    var t = data[0];
            //    var s = data[1];
            //    int[,] friens = new int[t, t];
            //    int tomo = 0;

            //    for (int i = 0; i < s; i++)
            //    {
            //        var friend = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //        friens[friend[0] - 1, friend[1] - 1] = 1;
            //        friens[friend[1] - 1, friend[0] - 1] = 1;

            //    }

            //    for (int i = 0; i < t; i++)
            //    {
            //        var x = new List<int>();
            //        var y = new List<int>();
            //        var a = new List<int>();

            //        for (int j = 0; j < t; j++)
            //        {

            //            if (friens[i, j] == 1)
            //            {
            //                x.Add(j);
            //            }

            //        }

            //        foreach (var z in x)
            //        {
            //            for (int l = 0; l < t; l++)
            //            {
            //                if (friens[z, l] == 1)
            //                {
            //                    y.Add(l);
            //                }
            //            }

            //            foreach (var m in y)
            //            {
            //                if (m != i && friens[m, i] != 1)
            //                {
            //                    a.Add(m);
            //                }
            //            }
            //        }

            //        Console.WriteLine(a.Distinct().Count());

            //    }

            //    var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    var b = a[0];
            //    var c = a[1];
            //    int[] d = new int[b];
            //    int[] e = new int[b];
            //    int[] f = new int[b];
            //    int tmp = 0;
            //    int tokuten = 0;

            //    for (int i = 0; i < b; i++)
            //    {
            //        var g = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //        d[i] = g[0];
            //        e[i] = g[1];
            //        f[i] = g[2];

            //    }

            //    for (int j = 1; j <= c; j++)
            //    {
            //        for (int k = 0; k < b; k++)
            //        {
            //            if (d[k] <= j && e[k] >= j)
            //            {

            //            }
            //            else
            //            {
            //                tmp += f[k];
            //            }

            //        }
            //        tokuten = Math.Max(tokuten ,tmp);
            //        tmp = 0;
            //    }

            //    Console.WriteLine(tokuten);

            var a = int.Parse(Console.ReadLine());
            var b = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            Dictionary<int,int> c = new Dictionary<int,int>();
            int d = 0;

            int cnt = 0;

            //for (int i = 0; i < a; i++)
            //{
            //    c.Add(b[i], 1);
            //}

            for (int i = 0; i < a; i++)
            {
                d = b[i];

                while (d % 2 == 0)
                {
                    d /= 2;
                }

                if (c.ContainsKey(d))
                {

                }
                else
                {
                    c.Add(d, 1);
                    cnt++;
                }
            }
            Console.WriteLine(cnt);
        }
    }
}