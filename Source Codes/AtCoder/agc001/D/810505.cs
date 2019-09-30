using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var n = Int32.Parse(str[0]);
            var m = Int32.Parse(str[1]);
            var a = new List<int>();
            str = Console.ReadLine().Split();
            for (int i = 0; i < m; i++)
                a.Add(Int32.Parse(str[i]));

            var ret = Solver.Solve(n, m, a);
            if (ret == null) Console.WriteLine("Impossible");
            else
            {
                foreach (var v in ret.Item1)
                    Console.Write(v + " ");
                Console.WriteLine();
                Console.WriteLine(ret.Item2);
                foreach (var v in ret.Item3)
                    Console.Write(v + " ");
                Console.WriteLine();
            }
        }
    }

    public class Solver
    {
        public static Tuple<List<int>, int, List<int>> Solve(int n, int m, List<int> a)
        {
            if (a.Count(v => v % 2 == 1) > 2) return null;

            if (m == 1)
            {
                List<int> ret;
                if (a[0] > 2)
                    ret = new List<int>() { a[0] - 1, 1 };
                else
                    ret = a.ToList();
                return new Tuple<List<int>, int, List<int>>(a, ret.Count(), ret);
            }

            //move odd items to first and last
            if (a.Count(v => v % 2 == 1) > 0)
            {
                var fst = a.First(v => v % 2 == 1);
                a.Remove(fst);
                a.Insert(0, fst);
                var lst = a.Last(v => v % 2 == 1);
                var lstIdx = a.LastIndexOf(lst);
                a.RemoveAt(lstIdx);
                a.Add(lst);
            }

            var b = new List<int>() { a.Last() + 1 };
            for (int i = a.Count - 2; i > 0; i--)
            {
                b.Add(a[i]);
            }
            if (a[0] > 1) b.Add(a[0] - 1);
            b.Reverse();

            return new Tuple<List<int>, int, List<int>>(a, b.Count(), b);
        }
    }
}