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
           
            var solver = new Solver();
            Console.WriteLine(solver.Solve(double.Parse(str)));
        }
    }

    public class Solver
    {
        public double Solve(double p)
        {
            double l = 0;
            double r = p;

            //ternary search
            while(r - l > 1E-10)
            {
                var m1 = l + (r - l) / 3.0;
                var m2 = l + (r - l) * 2.0 / 3.0;

                var t1 = m1 + p / Math.Pow(2.0, m1 / 1.5);
                var t2 = m2 + p / Math.Pow(2.0, m2 / 1.5);

                if (t1 < t2)
                {
                    r = m2;
                }
                else
                {
                    l = m1;
                }
            }

            return (l + r) / 2.0 + p / Math.Pow(2.0, ((l + r) / 2.0) / 1.5);    //don't forget to calc!
        }
    }
}