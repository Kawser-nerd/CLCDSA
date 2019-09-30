using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MinimumScalarProduct
{
    class CaseSolver
    {
        internal static string Solve(string[] lines)
        {
            int index = 0;
            int n = int.Parse(lines[index++]);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; ++i)
            {
                int count = int.Parse(lines[index++]);
                string[] ss1 = lines[index++].Split(new char[] { ' ' }, count);
                List<long> list1 = new List<long>(count);
                foreach (string s in ss1)
                {
                    list1.Add(long.Parse(s));
                }
                string[] ss2 = lines[index++].Split(new char[] { ' ' }, count);
                List<long> list2 = new List<long>(count);
                foreach (string s in ss2)
                {
                    list2.Add(long.Parse(s));
                }
                long result = Solve(list1.ToArray(), list2.ToArray());
                sb.AppendLine(string.Format("Case #{0}: {1}", i + 1, result));
            }
            return sb.ToString();
        }

        static long Solve(long[] a, long[] b)
        {
            long result1 = SolveX((long[])a.Clone(), (long[])b.Clone());
            long result2 = SolveX((long[])b.Clone(), (long[])a.Clone());
            return Math.Min(result1, result2);
        }

        static long SolveX(long[] a, long[] b)
        {
            Array.Sort(a, (left, right) => -(int)(Math.Abs(left) - Math.Abs(right)));
            Array.Sort(b);

            int count = a.Length;
            long result = 0;
            bool[] flags = new bool[count];
            foreach (var aa in a)
            {
                if(aa > 0)
                {
                    for(int i = 0; i < count; ++i)
                    {
                        if(!flags[i])
                        {
                            flags[i] = true;
                            result += aa*b[i];
                            break;
                        }
                    }
                }
                else if(aa < 0)
                {
                    for (int i = count-1; i >= 0; --i)
                    {
                        if(!flags[i])
                        {
                            flags[i] = true;
                            result += aa*b[i];
                            break;
                        }
                    }
                }
            }
            return result;
        }
    }
}
