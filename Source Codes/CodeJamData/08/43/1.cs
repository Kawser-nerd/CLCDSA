using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2008
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("C-small-attempt0.in");
            string output = "";
            int lineAt = 0;
            int testCases = int.Parse(input[lineAt++]);
            for (int i = 0; i < testCases; i++)
            {
                int n = int.Parse(input[lineAt++]);
                int[] x = new int[n];
                int[] y = new int[n];
                int[] z = new int[n];
                int[] p = new int[n];
                double res = 999999999;
                for(int j=0;j<n;j++)
                {
                    string[] line = input[lineAt++].Split(' ');
                    x[j] = int.Parse(line[0]);
                    y[j] = int.Parse(line[1]);
                    z[j] = int.Parse(line[2]);
                    p[j] = int.Parse(line[3]);
                }

                bool allSame = true;
                for (int j = 1; j < n; j++)
                {
                    if (x[j] != x[j - 1] || y[j] != y[j - 1] || z[j] != z[j - 1])
                    {
                        allSame = false;
                    }
                }
                if (allSame)
                {
                    res = 0;
                }
                else
                {
                    double lowPower = 1e-8;
                    double highPower = 1e8;

                    for (int j = 0; j < 1000; j++)
                    {
                        double guess = (lowPower + highPower) / 2.0;
                        bool strongEnough = true;
                        for (int k = 0; k < n; k++)
                        {
                            for (int m = k + 1; m < n; m++)
                            {
                                double p1 = p[k];
                                double p2 = p[m];
                                double lerp = p2 / (p1 + p2);
                                double oneMinusLerp = 1 - lerp;

                                double xs = x[k] * lerp + x[m] * oneMinusLerp;
                                double ys = y[k] * lerp + y[m] * oneMinusLerp;
                                double zs = z[k] * lerp + z[m] * oneMinusLerp;

                                if (power(xs, ys, zs, x[k], y[k], z[k], p[k]) > guess ||
                                    power(xs, ys, zs, x[m], y[m], z[m], p[m]) > guess)
                                {
                                    strongEnough = false;
                                    break;
                                }
                            }
                            if (!strongEnough)
                            {
                                break;
                            }
                        }
                        if (strongEnough)
                        {
                            highPower = guess;
                        }
                        else
                        {
                            lowPower = guess;
                        }
                    }
                    res = lowPower;
                }
                output += "Case #" + (i + 1) + ": " + res + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
        static double power(double xs, double ys, double zs, int x, int y, int z, int p)
        {
            return (Math.Abs(xs - x) + Math.Abs(ys - y) + Math.Abs(zs - z)) / p;
        }
    }
}
