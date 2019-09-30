using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        private static bool[, ,] a;
        private static TextReader GetFileTextReader()
        {
            return File.OpenText(@"..\..\b.in");
        }

        private static TextWriter GetFileTextWriter()
        {
            return File.CreateText(@"..\..\b.out");
        }

        static void Main(string[] args)
        {
            using (TextReader reader = GetFileTextReader())
            {
                using (TextWriter writer = GetFileTextWriter())
                {
                    int t = int.Parse(reader.ReadLine());

                    int xshift = 400;
                    int yshift = 400;

                    int xmax = 1001;
                    int ymax = 1001;
                    int kmax = 501;

                    a = new bool[xmax, ymax, kmax];

                    a[xshift, yshift, 0] = true;

                    for (int k = 1; k < kmax; k++)
                    {
                        for (int x = 0; x < xmax; x++)
                        {
                            for (int y = 0; y < ymax; y++)
                            {
                                if (x + k >= xmax || y + k >= ymax || x - k < 0 || y - k < 0) continue;

                                if (a[x - k, y, k - 1] || a[x + k, y, k - 1] || a[x, y + k, k - 1] || a[x, y - k, k - 1])
                                {
                                    a[x, y, k] = true;
                                }
                            }
                        }
                    }

                    for (int j = 0; j < t; j++)
                    {
                        string[] s = reader.ReadLine().Split(" ".ToArray(), StringSplitOptions.RemoveEmptyEntries);

                        int x = int.Parse(s[0]);
                        int y = int.Parse(s[1]);

                        string result = Find(x + xshift, y + yshift);

                        writer.WriteLine("Case #{0}: {1}", j + 1, result);
                    }
                }
            }
        }

        private static string Find(int xd, int yd)
        {
            string result = string.Empty;
            
            for (int k = 0; k < 501; k++)
            {
                if (a[xd, yd, k])
                {
                    int x = xd, y = yd;
                    while (k != 0)
                    {
                        if (a[x + k, y, k - 1])
                        {
                            x += k;
                            result = 'W' + result;
                        }
                        else if (a[x - k, y, k - 1])
                        {
                            x -= k;
                            result = 'E' + result;                            
                        }
                        else if (a[x, y + k, k - 1])
                        {
                            y += k;
                            result = 'S' + result;                          
                        }
                        else if (a[x, y - k, k - 1])
                        {
                            y -= k;
                            result = 'N' + result;                            
                        }
                        else { throw new Exception(); }

                        k--;
                    }

                    break;
                }
            }

            return result;
        }
    }
}
