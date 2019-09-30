using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });

            var n = Int32.Parse(Console.ReadLine());
            var a = new List<Int64>();
            var dictIdx = new Dictionary<Int64, int>();
            for (int i = 0; i < n; i++)
            {
                a.Add(Int64.Parse(Console.ReadLine()));
                dictIdx.Add(a[i], i);
            }

            var wk = a.OrderBy(v => v).ToList();
            var indices = new Int64[n];
            for (int i = 0; i < wk.Count; i++)
            {
                indices[dictIdx[wk[i]]] = i;
            }

            Int64 ret = 0;
            for (int i = 0; i < a.Count(); i++)
            {
                if (i % 2 == 0 && indices[i] % 2 == 1) ret++;
            }

            Console.WriteLine(ret);
            Console.Out.Flush();
        }
    }
}