using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC113
{
    class Location
    {
        public int index;
        public double height;
        public Location(int idx, double h)
        {
            index = idx;
            height = h;
        }
    }
    class Program
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string[] s = Console.ReadLine().Split(' ');
            double T = double.Parse(s[0]);
            double A = double.Parse(s[1]);
            s = Console.ReadLine().Split(' ');
            List<Location> H = new List<Location>();
            for (int i = 0; i < N; i++)
            {
                H.Add(new Location(i + 1, Math.Abs(T - double.Parse(s[i]) * 0.006 - A)));
            }
            H = H.OrderBy(x => x.height).ToList();
            Console.WriteLine(H[0].index);
        }
    }
}