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
            var data = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            var t = data[0];
            var s = data[1];
            int[,] friens = new int[t, t];
            int tomo = 0;

            for (int i = 0; i < s; i++)
            {
                var friend = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                friens[friend[0] - 1, friend[1] - 1] = 1;
                friens[friend[1] - 1, friend[0] - 1] = 1;

            }

            for (int i = 0; i < t; i++)
            {
                var x = new List<int>();
                var y = new List<int>();
                var a = new List<int>();

                for (int j = 0; j < t; j++)
                {

                    if (friens[i, j] == 1)
                    {
                        x.Add(j);
                    }

                }

                foreach (var z in x)
                {
                    for (int l = 0; l < t; l++)
                    {
                        if (friens[z, l] == 1)
                        {
                            y.Add(l);
                        }
                    }

                    foreach (var m in y)
                    {
                        if (m != i && friens[m, i] != 1)
                        {
                            a.Add(m);
                        }
                    }
                }

                Console.WriteLine(a.Distinct().Count());

            }
        }
    }
}