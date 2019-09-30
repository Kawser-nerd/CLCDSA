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
            var answer = "";
            double m = double.Parse(Console.ReadLine());

            double kilom = m / 1000;

            if(kilom < 0.1)
            {
                answer = "00";
            }
            else if(0.1 <= kilom && kilom <= 5.0)
            {
                answer = (kilom * 10).ToString();
                answer = kilom * 10 < 10 ? ("0" + answer) : answer;

            }
            else if(6.0 <= kilom && kilom <= 30)
            {
                answer = (kilom + 50).ToString();

            }
            else if(35 <= kilom && kilom <= 70)
            {
                answer = ((kilom - 30) / 5 + 80).ToString();
            }
            else if (70 < kilom)
            {
                answer = "89";
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