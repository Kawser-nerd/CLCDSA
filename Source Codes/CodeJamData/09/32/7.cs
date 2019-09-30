using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1._2
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    {
                        int cases = int.Parse(reader.ReadLine());
                        for (int i = 0; i < cases; i++)
                        {
                            int n = int.Parse(reader.ReadLine());
                            decimal x0 = 0;
                            decimal xa = 0;
                            decimal y0 = 0;
                            decimal ya = 0;
                            decimal z0 = 0;
                            decimal za = 0;
                            for (int j = 0; j < n; j++)
                            {
                                int[] values = reader.ReadLine().Split(null).Select(s => int.Parse(s)).ToArray();
                                x0 += values[0];
                                y0 += values[1];
                                z0 += values[2];
                                xa += values[3];
                                ya += values[4];
                                za += values[5];
                            }

                            x0 /= n;
                            y0 /= n;
                            z0 /= n;
                            xa /= n;
                            ya /= n;
                            za /= n;

                            decimal a = xa * xa + ya * ya + za * za;
                            decimal b = 2.0M * (x0 * xa + y0 * ya + z0 * za);
                            decimal c = x0 * x0 + y0 * y0 + z0 * z0;

                            decimal t = 0;

                            if (a != 0)
                            {
                                t = -b / (2.0M * a);
                            }
                            else if (b != 0)
                            {
                                t = -c / b;
                            }
                            if (t < 0.000000001M)
                                t = 0;

                            decimal minDistanceSquare = a * t * t + b * t + c;

                            decimal minDistance = (minDistanceSquare < 0.000000001M) ? 0 : (decimal)Math.Sqrt((double)minDistanceSquare);
                            
                            writer.WriteLine("Case #" + (i + 1) + ": {0:0.00000000} {1:0.00000000}", minDistance, t);
                        }
                    }
                }
            }
        }
    }
}
