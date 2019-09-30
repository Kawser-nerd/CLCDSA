using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_1C_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var R = parts[0];
                var C = parts[1];
                var W = parts[2];

                var missedRows = (C / W) * (R - 1);
                var finalRow = (C - 1) / W + W;

                Console.WriteLine("Case #{0}: {1}", testN, missedRows + finalRow);
            }
        }
    }
}
