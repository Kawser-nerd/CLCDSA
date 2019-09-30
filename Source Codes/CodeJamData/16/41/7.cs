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

        int NewW(int a, int b, int c)
        {
            var e = a + b - c;
            if (e < 0 || e % 2 == 1)
                return -1;
            return e / 2;
        }

        string Generate(char current, int cnt)
        { 
            var news = new StringBuilder();
            if (cnt == 0)
            {
                news.Append(current);
                return news.ToString();
            }
            if (current == 'P')
            {
                var a = Generate('P', cnt - 1);
                var b = Generate('R', cnt - 1);
                if (a.CompareTo(b) == -1)
                    return a + b;
                return b + a;
            }
            if (current == 'R')
            {
                var a = Generate('S', cnt - 1);
                var b = Generate('R', cnt - 1);
                if (a.CompareTo(b) == -1)
                    return a + b;
                return b + a;
            }
            if (current == 'S')
            {
                var a = Generate('P', cnt - 1);
                var b = Generate('S', cnt - 1);
                if (a.CompareTo(b) == -1)
                    return a + b;
                return b + a;
            }
            return null;
        }

        public void Solve(int caseNumber, TextReader input, TextWriter output)
        {
            var arr = input.ReadLine().Split(' ');
            var n = Get<int>(arr[0]);
            var r = Get<int>(arr[1]);
            var p = Get<int>(arr[2]);
            var s = Get<int>(arr[3]);
            var cnt = 0;
            while (true)
            {
                ++cnt;
                var np = NewW(p, r, s);
                var nr = NewW(r, s, p);
                var ns = NewW(p, s, r);
                if (np == -1 || nr == -1 || ns == -1)
                {
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", caseNumber);
                    return;
                }
                p = np;
                r = nr;
                s = ns;
                if (p + r + s == 1)
                    break;                
            }
            var res = '0';
            if (p == 1)
                res = 'P';
            if (r == 1)
                res = 'R';
            if (s == 1)
                res = 'S';
            Console.WriteLine("Case #{0}: {1}", caseNumber, Generate(res, cnt));
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