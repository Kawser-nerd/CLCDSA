using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int[] x = new int[3], y = new int[3];
            x[0] = int.Parse(s[0]);
            y[0] = int.Parse(s[1]);
            int r;
            r = int.Parse(s[2]);
            
            s = Console.ReadLine().Split(' ');
            x[1] = int.Parse(s[0]);
            y[1] = int.Parse(s[1]);
            x[2] = int.Parse(s[2]);
            y[2] = int.Parse(s[3]);
            int xmax, xmin, ymax, ymin;
            xmax = Math.Max(x.Max(), x[0] + r);
            xmin = Math.Min(x.Min(), x[0] - r);
            ymax = Math.Max(y.Max(), y[0] + r);
            ymin = Math.Min(y.Min(), y[0] - r);


            int xlen = xmax - xmin +1;
            int ylen = ymax - ymin +1;
            int[,] xy = new int[xlen, ylen];
            double dr;
            for (int dx = xmin; dx <= xmax; dx++)
            {
                for (int dy = ymin; dy <= ymax ; dy++)
                {
                    int ix = dx - xmin, iy = dy - ymin;
                    dr = Math.Pow( dx - x[0],2) + Math.Pow(dy - y[0],2);
                    if (dr <= r*r)
                    {
                        xy[ix, iy] +=  1;
                    }
                    if (x[1] <= dx && dx <= x[2])
                    {
                        if (y[1] <= dy && dy <= y[2])
                        {
                            xy[ix, iy] += 2;
                        }
                    }
                }
            }

            string red = "NO", blue = "NO";
            for (int dy = ymin; dy <= ymax; dy++)
            {
                //string ss = "";
                for (int dx = xmin; dx <= xmax; dx++)
                {
                    int ix = dx - xmin, iy = dy - ymin;

                    if (xy[ix, iy] == 1)
                    {
                        red = "YES";
                    }
                    if (xy[ix, iy] == 2)
                    {
                        blue = "YES";
                    }
                    //ss += xy[ix, iy].ToString();

                }
                //Console.WriteLine(ss);
            }

            Console.WriteLine(red);
            Console.WriteLine(blue);
            Console.ReadLine();

        }
    }
}