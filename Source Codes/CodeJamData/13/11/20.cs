using System;
using System.IO;

namespace Bullseye
{
    class Program
    {
        private static long Search(long r, long paintLeft)
        {
            long circles = 0;
            while (true)
            {
                long required = 2*r + 1;
                if (paintLeft >= required)
                {
                    paintLeft -= required;
                    circles++;
                }
                else
                {
                    break;
                }

                r += 2;
            }

            return circles;
        }

        private static long BinarySearch(long r, long paintLeft)
        {
            long from = 0;
            long to = (long) Math.Sqrt(paintLeft) + 10;

            while (to - from > 1)
            {
                long middle = (to + from)/2;

                // overflow
                decimal required;
                checked
                {
                    required =(0.0m + 2 * r + 1 + 2 * r + 1 + 4 * (middle - 1)) / 2 * middle;
                }

                if (required <= paintLeft)
                {
                    from = middle;
                }
                else
                {
                    to = middle;
                }
            }

            return from;
        }

        static void Main(string[] args)
        {
            try
            {
                int started = Environment.TickCount;
                string path = @"..\..\..\..\";
                string filenameIn = "A-large.in";
                string filenameOut = "A-large.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                for (int t = 0; t < testCount; t++)
                {
                    string[] splitted = sr.ReadLine().Split(' ');

                    long r = Convert.ToInt64(splitted[0]);
                    long paintLeft = Convert.ToInt64(splitted[1]);

                    //long v1 = Search(r, paintLeft);
                    long v2 = BinarySearch(r, paintLeft);

                    string message = v2.ToString();
                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);
                }

                sr.Close();
                sw.Close();

                int elapsed = Environment.TickCount - started;
                Console.WriteLine("Time elapsed: " + elapsed);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
