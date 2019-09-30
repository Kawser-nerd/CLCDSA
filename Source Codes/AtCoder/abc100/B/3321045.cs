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
            int d, n;
            int[] l = io.Inputs();
            d = l[0]; n = l[1];
            if(n%100==0){
                n++;
            }
            WriteLine(n * (int)Math.Pow(10, 2 * d));
        }
    }
    class Stdin
    {
        public int Input()
        {
            return int.Parse(ReadLine());
        }
        public int[] Inputs()
        {
            string[] buf = ReadLine().Split(' ');
            return buf.Select(x => int.Parse(x)).ToArray();
        }
        public string Raw_Input()
        {
            return ReadLine();
        }
    }
}