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
            var answer = 0;
            int n = int.Parse(Console.ReadLine());
            int m = int.Parse(Console.ReadLine());
            answer = n-m;


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