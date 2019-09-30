using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace B
{
    class Program
    {
        static int[] power = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
        static List<int[]> price;
        static void Main(string[] args)
        {
            FileStream fsInput;
            StreamReader input = null;

            FileStream fsOutput;
            StreamWriter output = null;

            try
            {
                fsInput = File.OpenRead(args[0]);
                input = new StreamReader(fsInput);
                fsOutput = File.Create("b.out");
                output = new StreamWriter(fsOutput);

                int[] x = input.ReadIntsLine(1);
                int casesCount = x[0];

                for (int q = 0; q < casesCount; ++q)
                {
                    x = input.ReadIntsLine(1);
                    int p = x[0];

                    int[] m = input.ReadIntsLine(power[p]);
                    price = new List<int[]>(p);
                    for (int i = 0; i < p; ++i)
                    {
                        price.Add(input.ReadIntsLine(power[p - i - 1]));
                    }



                    output.WriteLine("Case #{0}: {1}", q + 1, ComputePrice(m, p, 0));
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            finally
            {
                if (null != input)
                    input.Dispose();
                if (null != output)
                    output.Dispose();
            }
        }
        static int ComputePrice(int[] m, int p, int offset)
        {
            if (0 == p) 
                return 0;
            int price1 = price[p - 1][offset / power[p]];
            int[] m1 = new int[power[p - 1]];
            for (int i = 0; i < power[p - 1]; ++i)
            {
                m1[i] = m[i];
            }
            price1 += ComputePrice(m1, p - 1, offset);
            for (int i = 0; i < power[p - 1]; ++i)
            {
                m1[i] = m[i + power[p - 1]];
            }
            price1 += ComputePrice(m1, p - 1, offset + power[p - 1]);

            for (int i = 0; i < power[p - 1]; ++i)
            {
                m1[i] = m[i] - 1;
                if (0 > m1[i])
                    return price1;
            }
            int price2 = 0;
            price2 += ComputePrice(m1, p - 1, offset);
            for (int i = 0; i < power[p - 1]; ++i)
            {
                m1[i] = m[i + power[p - 1]] - 1;
                if (0 > m1[i])
                    return price1;
            }
            price2 += ComputePrice(m1, p - 1, offset + power[p - 1]);

            return Math.Min(price1, price2);
        }
    }
    public static class StreamReaderExtensions
    {
        public static int[] ReadIntsLine(this StreamReader r, int count)
        {
            string s = r.ReadLine();
            string[] split = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            if (split.Length != count)
                throw new ArgumentException("Invalid count", "count");
            int[] result = new int[count];
            for (int i = 0; i < count; ++i)
            {
                result[i] = Int32.Parse(split[i]);
            }
            return result;
        }
    }
}
