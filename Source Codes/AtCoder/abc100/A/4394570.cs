using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main
{
    public static class Program
    {
        static void Main(string[] arg)
        {
            var answer = "Yay!";
            var line = GetIntList(Console.ReadLine());
            int a = line[0];
            int b = line[1];

            if(a > 8 || b > 8)
            {
                answer = ":(";
            }
            

            Console.WriteLine(answer);
            Console.ReadLine();

        }
        #region libraries
        private static int[] GetIntList(string line)
        {
            return line.Split(' ').Select(x => int.Parse(x)).ToArray();

        }
        private static int SearchNearest(this IEnumerable<int> list, int target)
        {
            var min = list.Min(c => Math.Abs(c - target));
            return list.First(c => Math.Abs(c - target) == min);
        }
        public static int Gcd(int a,int b)
        {
            if(a < b)
            {
                Gcd(b, a);
            }
            while (b != 0)
            {
                var rm = a % b;
                a = b;
                b = rm;
            }
            return a;
        }
        #endregion
    }
}