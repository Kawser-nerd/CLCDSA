using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
            var house = new List<int[]>();
            house.Add(new int[] { input[0], input[1] });
            house.Add(new int[] { input[2], input[3] });
            var t = input[4];
            var v = input[5];
            var n =  int.Parse(Console.ReadLine());
            var girls = new List<int[]>();
            for (int i = 0; i < n; i++)
            {
                girls.Add(Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray());
            }

            var flag = false;

            for (int i = 0; i < n; i++)
            {
                var distance1 = CalcDistance(house[0], girls[i]);
                var distance2 = CalcDistance(house[1], girls[i]);
                if (distance1 + distance2 <= t * v)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }

        static double CalcDistance(int[] rootCrd, int[] stbCrd)
        {
            var left = stbCrd[0] - rootCrd[0];
            var right = stbCrd[1] - rootCrd[1];
            var result = Math.Sqrt(Math.Pow(left, 2) + Math.Pow(right, 2));

            return result;
        }
    }
}