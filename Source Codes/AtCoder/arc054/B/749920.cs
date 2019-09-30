using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static double f(double x)
        {
            return x + P * Math.Pow(A, x);
        }

        static double fp(double x)
        {
            return 1.0 + P * lnA * Math.Pow(A, x);
        }

        static double P;
        static double A;
        static double lnA;
        static void Main(string[] args)
        {
            P = double.Parse(Console.ReadLine());
            A = Math.Pow(2.0, -2.0 / 3);
            lnA = Math.Log(A);

            if (fp(0) >= 0)
            {
                Console.WriteLine(f(0));
                return;
            }

            double bottom = 0.0;
            double top = 1.0;
            while (fp(top) <= 0)
            {
                bottom = top;
                top *= 2;
            }

            for (int i = 0; i < 1000; i++)
            {
                var next = (bottom + top) / 2;
                if (fp(next) <= 0)
                {
                    bottom = next;
                }
                else
                {
                    top = next;
                }
            }

            Console.WriteLine(f(bottom));
        }
    }
}