using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Globalization.NumberFormatInfo provider = new System.Globalization.NumberFormatInfo() { NumberDecimalSeparator = "."};
            int t;
            string[] lines = System.IO.File.ReadAllLines("input.txt");
            t = Convert.ToInt32(lines[0]);
            string[] answers = new string[t];
            Parallel.For(0, t, (num) =>
            {
                string[] parts = lines[num + 1].Split(' ');
                double c = Convert.ToDouble(parts[0], provider);
                double f = Convert.ToDouble(parts[1], provider);
                double x = Convert.ToDouble(parts[2], provider);

                double rate = 2;
                double best = double.PositiveInfinity;
                double cur = 0;
                for (int i = 0; i < x; ++i)
                {
                    best = Math.Min(best, cur + x / rate);
                    cur += c / rate;
                    rate += f;
                }
                answers[num] = string.Format("Case #{0}: {1}", num + 1, best.ToString(provider));
            });
            System.IO.File.WriteAllLines("output.txt", answers);
        }
    }
}
