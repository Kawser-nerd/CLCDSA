using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GoogleCodeJamQ2_A
{
    public class Problem
    {
        public Problem()
        {
            var pathname = "Sample.txt";
            using (FileStream fs = new FileStream(pathname, FileMode.Open))
            {
                StreamReader sr = new StreamReader(fs);
                using (FileStream fsout = new FileStream(pathname + ".out", FileMode.Create))
                {
                    StreamWriter sw = new StreamWriter(fsout);
                    int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                    for (int sc = 1; sc <= caseScenario; sc++)
                    {
                        int result = 0;
                        int[] input = sr.ReadLine().Split(' ').Select(s => Int32.Parse(s)).ToArray();
                        int R = input[0];
                        int C = input[1];
                        char[,] tableau = new char[R, C];
                        List<Point> points = new List<Point>();
                        for (int r = 0; r < R; r++)
                        {
                            string line = sr.ReadLine();
                            for (int c = 0; c < C; c++)
                            {
                                tableau[r, c] = line[c];
                                if (tableau[r, c] != '.')
                                {
                                    points.Add(new Point(c, r));
                                }
                            }
                        }
                        result = 0;
                        for (int i = 0; i < points.Count; i++)
                        {
                            Point p = points[i];
                            char dir = tableau[p.Y, p.X];
                            var point = new List<Point>();
                            point.AddRange(points.FindAll(s => (s.X == p.X && s.Y != p.Y) || (s.X != p.X && s.Y == p.Y)));
                            if (point.Count == 0)
                            {
                                result = -1; // si une case ne trouve pas de destination pour boucler, fin
                                break;
                            }
                            if (dir == '^')
                            {
                                var pt = point.FindAll(s => s.Y < p.Y);
                                if (pt.Count == 0)
                                {
                                    result++;
                                }
                            }
                            else if (dir == 'v')
                            {
                                var pt = point.FindAll(s => s.Y > p.Y);
                                if (pt.Count == 0)
                                {
                                    result++;
                                }
                            }
                            else if (dir == '<')
                            {
                                var pt = point.FindAll(s => s.X < p.X);
                                if (pt.Count == 0)
                                {
                                    result++;
                                }
                            }
                            else if (dir == '>')
                            {
                                var pt = point.FindAll(s => s.X > p.X);
                                if (pt.Count == 0)
                                {
                                    result++;
                                }
                            }
                            else
                            {
                                
                            }
                        }
                        //if (points.Count == 0)
                        //{
                        //    result = 0;
                        //}
                        //else if (points.Count == 2)
                        //{
                        //    if (points[0].X == points[1].X)
                        //    {
                        //        result = 0;
                        //        int c0 = points[0].X;
                        //        int r0 = points[0].Y;
                        //        int r1 = points[1].Y;
                        //        int max = r0 > r1 ? r0 : r1;
                        //        int min = r0 + r1 - max;
                        //        if (

                        //    }
                        //    if (points[0].Y == points[1].Y)
                        //    {
                        //    }
                        //}



                            sw.WriteLine("Case #{0}: {1}", sc, result==-1 ? "IMPOSSIBLE" : result.ToString());
                    }
                    sw.Flush();
                }

            }
        }


    }
}
