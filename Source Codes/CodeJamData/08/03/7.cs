using System;
using System.Collections.Generic;
using System.Text;

namespace FlySwatter
{
    class Program
    {
        static void Main(string[] args)
        {
            int N; 
            double f, R, t, r, g;
            int k;
            double P;
            string input;
            char[] delemet = { ' ' };
            input = Console.ReadLine();
            N = int.Parse(input);
            for (int n = 0; n < N; n++)
            {
                input = Console.ReadLine();
                string[] tokens = input.Split(delemet);
                f = double.Parse(tokens[0]);
                R = double.Parse(tokens[1]);
                t = double.Parse(tokens[2]);
                r = double.Parse(tokens[3]);
                g = double.Parse(tokens[4]);

                double r_modifid = r+f;
                double g_modified = g-2*f;
                if (g_modified < 0.0f)
                    g_modified = 0.0f;
                double t_modified = t + f;
                
                if (g_modified == 0.0f)
                    P = 1.0f;
                else
                {
                    double empty = 0.0f;
                    for(double x = r_modifid;x<(R-t_modified);x+=(g+2*r))
                    {
                        for (double y = r_modifid; y < (R - t_modified); y += (g + 2 * r))
                        {
                            double x1, x2, x3, x4;
                            double y1, y2, y3, y4;

                            x1 = x;
                            y1 = y;
                            if ((x * x + y * y) > (R - t_modified) * (R - t_modified))
                                break;
                            x2 = x;
                            y2 = y + g_modified;

                            x3 = x + g_modified;
                            y3 = y2;

                            x4 = x3;
                            y4 = y;

                            if ((x2 * x2 + y2 * y2) > (R - t_modified) * (R - t_modified))
                            {
                                if((x4*x4+y4*y4)>(R - t_modified) * (R - t_modified))
                                {
                                    empty += Program.CordArea((R - t_modified), x, y);
                                }
                                else
                                {
                                    empty += Program.CordArea((R - t_modified), x, y);
                                    empty -= Program.CordArea((R - t_modified), x4, y4);
                                }
                            }
                            else if ((x4 * x4 + y4 * y4) > (R - t_modified) * (R - t_modified))
                            {
                                empty += Program.CordArea((R - t_modified), x, y);
                                empty -= Program.CordArea((R - t_modified), x2, y2);
                            }
                            else if((x3 * x3 + y3 * y3) > (R - t_modified) * (R - t_modified))
                            {
                                empty += Program.CordArea((R - t_modified), x, y);
                                empty -= Program.CordArea((R - t_modified), x2, y2);
                                empty -= Program.CordArea((R - t_modified), x4, y4);
                            }
                            else
                            {
                                empty += g_modified * g_modified;
                            }
                        }
                    }
                    P = 1.0f - (empty / (Math.PI * (R * R) / 4.0f));
                }
                
                k = n + 1;
                Console.WriteLine("Case #" + k.ToString() + ": " + P.ToString("0.000000"));
            }
        }

        static double CordArea(double r, double x, double y)
        {
            double ans = x*y;
            ans -= Math.PI * r * r / 4.0f;
            ans += Math.Acos(x / r) * r * r / 2.0f;
            ans += Math.Acos(y / r) * r * r / 2.0f;
            ans -= x * Math.Sqrt((r * r) - (x * x)) / 2.0f;
            ans -= y * Math.Sqrt((r * r) - (y * y)) / 2.0f;
            return ans;
        }
    }
}
