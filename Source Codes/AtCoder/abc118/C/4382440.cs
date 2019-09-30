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
        public static List<int> banboos = new List<int>();
        static void Main(string[] arg)
        {
            var answer = 0;
            int n = int.Parse(Console.ReadLine());
            int[] Line = GetIntList(Console.ReadLine());
            int aa = Line[0];
            for (int i = 0; i < n - 1; i++)
            {
                aa = Gcd(aa, Line[i + 1]);
            }
            answer = aa;
            Console.WriteLine(answer);
            Console.ReadLine();

        }
        private static int[] GetIntList(string line)
        {
            return line.Split(' ').Select(x => int.Parse(x)).ToArray();

        }
        private static int SearchNearest(this IEnumerable<int> self, int target)
        {
            var min = self.Min(c => Math.Abs(c - target));
            return self.First(c => Math.Abs(c - target) == min);
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
    }
}