using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B.Time_Limit_Exceeded
{
    class Program
    {
        static void Main(string[] args)
        {
            var NT = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var Ci = new List<int>();
            var Ti = new List<int>();
            var min = int.MaxValue;

            for (int i = 0; i < NT[0]; i++)
            {
                var CiTi = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                Ci.Add(CiTi[0]);
                Ti.Add(CiTi[1]);
            }

            foreach (var item in Ti.Where(x => x <= NT[1]))
                min = Math.Min(min, Ci[Array.IndexOf(Ti.ToArray(), item)]);

            if (min != int.MaxValue)
                Console.WriteLine(min);
            else
                Console.WriteLine("TLE");
        }
    }
}