using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Mirrors
{
    class Program
    {
        private static Tuple<int, int> gcdVector(int y, int x)
        {
            int gcd = (int)BigInteger.GreatestCommonDivisor(y, x);
            return Tuple.Create(y / gcd, x / gcd);
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("c:\\codejam\\2012\\qual\\D-large.in");
            StreamWriter sw = new StreamWriter("c:\\codejam\\2012\\qual\\D-large.out");

            Stopwatch watch = new Stopwatch();
            watch.Start();

            int T = Int32.Parse(sr.ReadLine());
            foreach (int caseN in Enumerable.Range(1, T))
            {
                int[] tmp = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                int H = tmp[0];
                int W = tmp[1];
                int D = tmp[2];

                int Xy = 0, Xx = 0;

                bool[,] grid = new bool[H, W];
                for (int h = 0; h < H; h++)
                {
                    var line = sr.ReadLine();
                    for (int w = 0; w < W; w++)
                    {
                        grid[h, w] = line[w] == '#';
                        if (line[w] == 'X')
                        {
                            Xy = h; Xx = w;
                        }
                    }
                }

                int reflections = 0;

                HashSet<Tuple<int, int>> vectors = new HashSet<Tuple<int, int>>();
                int max = 150;
                for (int sry = -max; sry <= max; sry++)
                {
                    for (int srx = -max; srx <= max; srx++)
                    {
                        if (sry == 0 && srx == 0)
                            continue;

                        if (vectors.Contains(gcdVector(sry, srx)))
                            continue;

                        vectors.Add(gcdVector(sry, srx));

                        int ry = sry;
                        int rx = srx;

                        //project the ray in direction (ry,rx)
                        int gcd = (int) BigInteger.GreatestCommonDivisor(ry, rx);

                        //if rx or ry is 0 then we just scale everything by 2
                        int lcm = (ry == 0 || rx == 0) ? 0 : 2 * Math.Abs(ry * rx) / gcd;

                        //grid scalings
                        int my = (ry == 0 || rx == 0) ? 2 : lcm / Math.Abs(ry);
                        int mx = (ry == 0 || rx == 0) ? 2 : lcm / Math.Abs(rx);

                        //ry and rx are direction vectors
                        //in new scaling we always move (1,1),(-1,0) etc...
                        ry = Math.Sign(ry);
                        rx = Math.Sign(rx);

                        //our current position
                        int ay = Xy * my + my / 2;
                        int ax = Xx * mx + mx / 2;

                        int cly = 0;
                        int clx = 0;

                        int lastGy = ay;
                        int lastGx = ax;
                        while ((clx / mx ) * (clx / mx) + (cly / my) * (cly / my) <= D * D)
                        {

                            if (ax % (mx / 2) == 0 && ay % (my / 2) == 0 && (clx + cly) != 0)
                            {
                                if (ax == (Xx * mx + mx / 2) && ay == (Xy * my + my / 2))
                                {
                                    //hit the middle!

                                    reflections++;
                                    break;
                                }
                            }


                            //in direction we are moving we want to find the next point that intersects a real grid line
                            int newy = 0;
                            if (ay % (my / 2) == 0 || ry > 0)
                            {
                                newy = (ay / (my / 2) + 1 * ry) * (my / 2);
                            }
                            else
                            {
                                newy = (ay / (my / 2)) * (my / 2);
                            }
                            int newx = 0;
                            if (ax % (mx / 2) == 0 || rx > 0)
                            {
                                newx = (ax / (mx / 2) + 1 * rx) * (mx / 2);
                            }
                            else
                            {
                                newx = (ax / (mx / 2)) * (mx / 2);
                            }

                            if (rx == 0 || Math.Abs(newy - ay)  < Math.Abs(newx - ax) && ry != 0)
                            {
                                //we move to next y grid line
                                ax = ax + Math.Abs(newy - ay) * rx;
                                ay = newy;
                            }
                            else
                            {
                                ay = ay + Math.Abs(newx - ax) * ry;
                                ax = newx;
                            }

                            //we have our new scaled grid position in ay and ax
                            //this is a real grid line if it is % the scaling

                            if (ay % (my / 2) == 0 && ry != 0)
                            {
                                //we have hit a vert grid line
                                cly += Math.Abs(lastGy - ay);
                                lastGy = ay;
                            }
                            if (ax % (mx / 2) == 0 && rx != 0)
                            {
                                //we have hit a horiz grid line
                                clx += Math.Abs(lastGx - ax);
                                lastGx = ax;
                            }

                            //we have projected the ray to the next possible grid intersection
                            if (ay % my == 0 && ax % mx == 0 )
                            {
                                //not this can never happen when rx or ry is 0

                                //at a corner
                                //get 3 mirrors we need to check
                                int realy = ay / my;
                                int realx = ax / mx;

                                int cornery = realy - (ry < 0 ? 1 : 0);
                                int cornerx = realx - (rx < 0 ? 1 : 0);
                                int horizy = cornery + (ry > 0 ? -1 : 1);
                                int vertx = cornerx + (rx > 0 ? -1 : 1);

                                //(cornery,cornerx), (horizy,cornerx), (cornery,vertx)
                                if (grid[cornery, cornerx] && grid[horizy, cornerx] && grid[cornery, vertx])
                                {
                                    ry *= -1; rx *= -1;
                                }
                                else if (grid[cornery, cornerx] && grid[horizy, cornerx])
                                {
                                    rx *= -1;
                                }
                                else if (grid[cornery, cornerx] && grid[cornery, vertx])
                                {
                                    ry *= -1;
                                }
                                else if (grid[cornery, cornerx])
                                {
                                    //destroyed
                                    break;
                                }
                            }
                            else if (ay % my == 0)
                            {
                                //poss vert reflection
                                int realy = ay / my + (ry < 0 ? -1 : 0);
                                int realx = ax / mx;
                                if (grid[realy, realx])
                                {
                                    ry *= -1;
                                }
                            }
                            else if (ax % mx == 0)
                            {
                                //poss horiz reflection
                                int realy = ay / my;
                                int realx = ax / mx + (rx < 0 ? - 1 : 0);
                                if (grid[realy, realx])
                                {
                                    rx *= -1;
                                }
                            }
                        }
                        
                    }
                }



                sw.WriteLine(String.Format("Case #{0}: {1}", caseN, reflections));

                Console.WriteLine(String.Format("Case #{0}: {1}ms", caseN, watch.ElapsedMilliseconds));

                sw.Flush();
            }

            sr.Close();
            sw.Close();

        }
    }
}
