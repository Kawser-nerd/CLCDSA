using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    public class ProblemSolver
    {
        static T Get<T>(object obj)
        {
            return (T)Convert.ChangeType(obj, typeof(T));
        }

        public void Setup()
        { 
        }

        void Break()
        { 
        }

        public double Result(List<double> list)
        { 
            var dim = new double[202, 202];
            dim[0,1] = 1-list[0];
            dim[1,1] = list[0];
            for (var i = 2;i<=list.Count;++i)
            {
                dim[0,i] = (1-list[i-1])*dim[0,i-1];
                for (var j = 1;j<=i;++j)
                {
                    dim[j,i] = list[i-1]*dim[j-1,i-1] + (1-list[i-1])*dim[j,i-1];
                }
            }
            return dim[list.Count/2,list.Count];
        }

        public void Solve(int caseNumber, TextReader input, TextWriter output)
        {
            var arr = input.ReadLine().Split(' ');
            var n = Get<int>(arr[0]);
            var k = Get<int>(arr[1]);
            arr = input.ReadLine().Split(' ');
            var list = new List<double>();
            for (var i = 1; i <= n; ++i)
            {
                list.Add(Get<double>(arr[i-1]));
            }
            list = list.OrderBy(c => c).ToList();
            double res = 0.0;
            for (int i = 0; i <= k; ++i)
            {
                var nl = list.Take(i).ToList();
                var sl = list.Skip(n-k+i).ToList();
                res = Math.Max(res, Result(nl.Concat(sl).ToList()));
            }
            Console.WriteLine("Case #{0}: {1:0.00000000}", caseNumber, res);
        }
    }

#region Launcher
    class Program
    {
        static T Get<T>(object obj)
        {
            return (T)Convert.ChangeType(obj, typeof(T));
        }

        static void Main(string[] args)
        {
#if !DEBUG
            Console.SetIn(new StreamReader("input.txt"));
            Console.SetOut(new StreamWriter("output.txt"));      
#endif
            var solver = new ProblemSolver();

            int t = Get<int>(Console.ReadLine());
            try
            {
                solver.Setup();
                for (var i = 1; i <= t; ++i)
                {
                    solver.Solve(i, Console.In, Console.Out);
                    Console.Out.Flush();
                }
            }
            finally
            {
                Console.Out.Flush();
            }
        }
    }
#endregion

}