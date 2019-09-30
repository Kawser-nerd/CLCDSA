using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class A : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();
            var p = NextInts(n);

            int sum = p.Sum();

            List<string> result = new List<string>();

            while (sum >0)
            {
                int max = 0;
                List<int> max_i = new List<int>();
                for (int i = 0; i < n; i++)
                {
                    if (max == p[i])
                    {
                        max_i.Add(i);
                    }
                    if (max < p[i])
                    {
                        max = p[i];
                        max_i = new List<int>();
                        max_i.Add(i);
                    }
                }

                if (max_i.Count == 1 || sum == 3)
                {
                    sum -= 1;
                    p[max_i[0]]--;
                    result.Add("" + alphabet[max_i[0]]);
                }
                else if (max_i.Count > 1)
                {
                    sum -= 2;
                    p[max_i[0]]--;
                    p[max_i[1]]--;
                    result.Add("" + alphabet[max_i[0]] + alphabet[max_i[1]]);
                }
                else
                {
                    throw new Exception();
                }
            }

//            string remaining = "";
//            for (int i = 0; i < n; i++)
//            {
//                if (p[i] > 1)
//                {
//                    throw new Exception();
//                }
//                if (p[1] == 1)
//                {
//                    remaining += alphabet[i];
//                }
//            }
//            result.Add(remaining);

            return string.Join(" ", result);
        }

        char[] alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray();

        private bool isWrong(int[] p)
        {
            int sum = p.Sum();
            foreach (var x in p)
            {
                if (x * 2 > sum) return false;
            }
            return true;
        }

    }
}
