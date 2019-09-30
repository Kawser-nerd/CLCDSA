using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - N??
            int n = int.Parse(Console.ReadLine());
            var radiuses = GetRadiuses(n);
            double r = 0;

            for(int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    r += Math.Pow(radiuses[i], 2);
                }
                else
                {
                    r -= Math.Pow(radiuses[i], 2);
                }
            }

            Console.WriteLine(r * Math.PI);
        }

        static List<int> GetRadiuses(int n)
        {
            var radiuses = new List<int>();

            for (int i = 0; i < n; i++)
            {
                int r = int.Parse(Console.ReadLine());
                radiuses.Add(r);
            }

            var query = radiuses.OrderByDescending(x => x);
            return query.ToList();
        }
    }
}