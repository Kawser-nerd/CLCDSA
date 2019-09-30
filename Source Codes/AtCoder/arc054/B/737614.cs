using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b
{
    class Program
    {
        static double p;
        static void Main(string[] args)
        {
            p = double.Parse(Console.ReadLine());
            double lb = 0;
            double ub = 100;
            double lmid = (ub + lb * 2) / 3;
            double umid = (ub * 2 + lb) / 3;

            while (ub-lb>1e-5)
            {
                lmid = (ub + lb * 2) / 3;
                umid = (ub * 2 + lb) / 3;
                if (t(lmid) > t(umid)) lb = lmid;
                else ub = umid;
            }

            Console.WriteLine(Math.Min(p, t(lmid)));
        }

        static double t(double x)
        {
            return x + p / Math.Pow(2, x / 1.5);
        }
    }
}