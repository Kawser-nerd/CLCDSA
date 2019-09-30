using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem3
{
    class Program3
    {
        static FixedPoint value = new FixedPoint("5.23606797749978969640917366873127623544061835961152572427089724541052092563780489941441440837878227");

        static void Main(string[] args)
        {
            Calculate(1);
            using (StreamReader sr = new StreamReader(args[0]))
            {
                using (StreamWriter sw = new StreamWriter(args[1]))
                {
                    string cases = sr.ReadLine();
                    int N = int.Parse(cases);
                    for (int i = 0; i < N; i++)
                    {
                        int power = int.Parse(sr.ReadLine());
                        sw.WriteLine("Case #{0}: {1}", i + 1, Calculate(power));
                    }
                }
            }
        }

        private static string Calculate(int power)
        {
            FixedPoint[] p = new FixedPoint[31];
            p[0] = value;
            for (int i = 1; i < p.Length; i++)
                p[i] = p[i - 1] * p[i - 1];

            FixedPoint result = new FixedPoint("1");
            for (int i = 0; i < p.Length; i++)
                if ((power & (1 << i)) != 0)
                    result *= p[i];

            return result.IntPart().ToString("000");
        }

        class FixedPoint
        {
            // rather than doing base conversion, we'll just do math in decimal

            const int mag = 200;
            const int prec = 200;
            int[] values = new int[prec + mag];

            public FixedPoint(string s)
            {
                int dp = s.IndexOf('.');
                if (dp < 0) dp = s.Length;
                for (int i = 0; i < mag; i++)
                    if (dp - mag + i >= 0)
                        values[i] = s[dp - mag + i] - '0';

                for (int i = 0; i < prec; i++)
                    if (dp + 1 + i < s.Length)
                        values[mag + i] = s[dp + 1 + i] - '0';

                Array.Reverse(values);
            }

            FixedPoint() { }

            FixedPoint(int[] values) { this.values = values; }

            public static FixedPoint operator *(FixedPoint a, FixedPoint b)
            {
                int[] result = new int[a.values.Length * 2];
                int[] x = a.values;
                int[] y = b.values;

                int[] temp = new int[a.values.Length * 2];
                for (int i = 0; i < x.Length; i++)
                {
                    int v = x[i];
                    int carry = 0;
                    for (int j = 0; j < y.Length; j++)
                    {
                        temp[i + j] = y[j] * v + carry;
                        carry = temp[i + j] / 10;
                        temp[i + j] -= carry * 10;
                    }
                    temp[i + y.Length] = carry;

                    Add(result, temp);
                }

                int[] result2 = new int[a.values.Length];
                for (int i = 0; i < result2.Length; i++)
                    result2[i] = result[i + prec];

                return new FixedPoint(result2);
            }

            public static FixedPoint operator +(FixedPoint a, FixedPoint b)
            {
                int[] temp = (int[])a.values.Clone();

                Add(temp, b.values);

                return new FixedPoint(temp);
            }

            private static void Add(int[] a, int[] b)
            {
                int carry = 0;
                for (int i = 0; i < a.Length; i++)
                {
                    a[i] += b[i] + carry;
                    carry = 0;
                    if (a[i] >= 10)
                    {
                        carry = 1;
                        a[i] -= 10;
                    }
                }
            }

            public int IntPart()
            {
                return values[values.Length - mag + 2] * 100 + values[values.Length - mag + 1] * 10 + values[values.Length - mag];
            }

            public override string ToString()
            {
                string ret = "";
                for (int i = 0; i < mag; i++)
                    ret += values[values.Length - i - 1];
                ret += ".";
                for (int i = values.Length - mag - 1; i >= 0; i--)
                    ret += values[i];
                return ret;
            }
        }
    }
}
