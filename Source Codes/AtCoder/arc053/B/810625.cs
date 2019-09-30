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
            var str = Console.ReadLine();
            Console.WriteLine(Solver.Solve(str));
        }
    }

    public class Solver
    {
        public static int Solve(string s)
        {
            var num = new int[26];
            foreach (var c in s) num[c - 'a']++;

            var devideNum = 0;
            foreach (var n in num) if (n % 2 == 1) devideNum++;

            if(devideNum == 0) return s.Length;

            var ret = 1 + (((s.Length - devideNum) / 2) / devideNum) * 2;
            return ret;
        }
    }
}