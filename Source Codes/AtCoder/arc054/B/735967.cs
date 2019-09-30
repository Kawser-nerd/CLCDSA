using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC054
{
    public class B
    {
        private double Calc(double P, double x)
        {
            return x + P / Math.Pow(2, x / 1.5);
        }
        private void Run()
        {
            var P = double.Parse(Console.ReadLine().Trim());

            double left = 0, right = 200;
            for (int i = 0; i < 1000000; i++)
            {
                double x1 = (right - left) / 3 + left;
                double x2 = (right - left) / 3 * 2 + left;

                double y1 = Calc(P, x1);
                double y2 = Calc(P, x2);
                if (y1 < y2) { right = x2; }
                else { left = x1; }
            }
            Console.WriteLine(Calc(P, left).ToString("F9"));
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}