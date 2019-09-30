using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace C
{
    class Program
    {
        const int MAXX = 102;
        const int MAXY = 102;
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
                fsOutput = File.Create("c.out");
                output = new StreamWriter(fsOutput);

                int[] inp = input.ReadIntsLine(1);
                int casesCount = inp[0];

                for (int q = 0; q < casesCount; ++q)
                {
                    inp = input.ReadIntsLine(1);
                    int r = inp[0];
                    int[,] rects = new int[r, 4];
                    for (int i = 0; i < r; ++i)
                    {
                        inp = input.ReadIntsLine(4);
                        for (int j = 0; j < 4; ++j) 
                        {
                            rects[i, j] = inp[j];
                        }
                    }

                    int[,] a = new int[MAXX, MAXY];
                    int mx = 0, my = 0;
                    for (int i = 0; i < r; ++i) 
                    {
                        if (rects[i, 2] > mx)
                            mx = rects[i, 2];
                        if (rects[i, 3] > my)
                            my = rects[i, 3];
                        for (int j = rects[i, 0]; j <= rects[i, 2]; ++j) 
                        {
                            for (int k = rects[i, 1]; k <= rects[i, 3]; ++k) 
                            {
                                a[j, k] = 1;
                            }
                        }
                    }

                    int s = 0;
                    bool had1 = true;
                    //Write(a, 6, 6);
                    while (had1) 
                    {
                        had1 = false;
                        for (int x = MAXX - 1; x >= 0; --x)
                        {
                            for (int y = MAXY - 1; y >= 0; --y) 
                            {
                                if (a[x, y] == 1)
                                {
                                    had1 = true;
                                    if ((x == 0 || a[x - 1, y] == 0) && (y == 0 || a[x, y - 1] == 0))
                                        a[x, y] = 0;
                                }
                                else
                                {
                                    if (x > 0 && y > 0 && a[x - 1, y] == 1 && a[x, y - 1] == 1)
                                        a[x, y] = 1;
                                }
                            }
                        }
                        if (had1)
                            ++s;
                        //Write(a, 6, 6);
                    }
                    output.WriteLine("Case #{0}: {1}", q + 1,s);
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
        public static void Write(int[,] a, int mx, int my) 
        {
            for (int x = 0; x <= mx; ++x)
            {
                for (int y = 0; y <= my; ++y) 
                {
                    Console.Write(a[x, y]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
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
