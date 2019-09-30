using System;
using System.Linq;
using static System.Math;
using static System.Console;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            Stdin io = new Stdin();
            Solve(io);
        }
        static void Solve(Stdin io)
        {
            long x = io.Input();
            WriteLine((x<1200)?"ABC":"ARC");
        }
    }
    class Stdin
    {
        public long Input()
        {
            return long.Parse(ReadLine());
        }
        public long[] Inputs()
        {
            string[] buf = ReadLine().Split(' ');
            return buf.Select(x => long.Parse(x)).ToArray();
        }
        public string Raw_Input()
        {
            return ReadLine();
        }
    }
}