using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Recycling
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= testCases; i++)
                new Program().Solve(i);
        }

        void Solve(int testCase)
        {
            var inputs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            
            var A = inputs[0];
            var B = inputs[1];
            
            int count = 0;
            for (int n = A; n < B; n++)
            {
                var nStr = n.ToString();
                var digits = nStr.Length;
                var ms = new HashSet<int>();

                for (int j = 1; j <= digits - 1; j++)
                {
                    var mStr = (nStr.Substring(j) + nStr.Substring(0, j)).TrimStart('0');
                    var m = int.Parse(mStr);
                    if (mStr.Length == nStr.Length && n < m && m <= B)
                        ms.Add(m);
                }

                count += ms.Count;
            }

            Console.WriteLine("Case #{0}: {1}", testCase, count);
        }
    }
}
