using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows;

namespace ProblemA
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012-2\2\B-large.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012-2\2\B-large.out";


        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);

                string res = GetCaseSolutionString(x, n);
                sw.WriteLine(res);
                Console.WriteLine("Solution #" + n +": " + res);

            }
            sr.Close();
            sw.Close();
        }

        private static string GetCaseSolutionString(string result, int n)
        {
            return string.Format("Case #{0}: {1}", n, result);
        }

        private static string SolveNextInput(StreamReader sr)
        {
            string phrase = sr.ReadLine();
            string result = "";

            var s1 = phrase.Split(' ').Select(int.Parse).ToList();
            var N = s1[0];
            var W = s1[1];
            var L = s1[2];
            phrase = sr.ReadLine();
            var h = phrase.Split(' ').Select(int.Parse).ToList();
            var hands = new List<Tuple<int, int>>();

            for (int i = 0; i < h.Count; i++)
            {
                hands.Add(new Tuple<int, int>(h[i], i));
            }
            var shands = hands.OrderByDescending(t => t.Item1).ToList();

            var resCoords = new List<Point>();
            var resRects = new List<Tuple<Rect, int>>();
            var rects = new List<Rect>();

            rects.Add(new Rect(0, 0, W, L));
      
            for (int i = 0; i < shands.Count; i++)
            {
                var hnd = shands[i];
                var r = hnd.Item1;

                var rect = new Rect(0, 0, 2*r, 2*r);
                var horiz = W > L;
                for (int j = 0; j < rects.Count; j++)
                {
                    var availRect = rects[j];

                    if (availRect.Width >= rect.Width && availRect.Height >= rect.Height)
                    { 
                        {
                            // can fit
                            //move to upper left corner
                            rect.X = availRect.X;
                            rect.Y = availRect.Y;

                            resRects.Add(new Tuple<Rect, int>(rect, hnd.Item2));

                            // remove old
                            rects.RemoveAt(j);
                            // horiz
                            if (horiz)
                            {
                                var nr1 = new Rect(availRect.X + rect.Width, availRect.Y, availRect.Width - rect.Width,
                                                   availRect.Height);
                                var nr2 = new Rect(availRect.X, availRect.Y + rect.Height, rect.Width,
                                                   availRect.Height - rect.Height);
                                rects.Add(nr1);
                                rects.Add(nr2);
                            }
                            else
                            {
                                var nr1 = new Rect(availRect.X + rect.Width, availRect.Y, availRect.Width - rect.Width,
                   rect.Height);
                                var nr2 = new Rect(availRect.X, availRect.Y + rect.Height, availRect.Width,
                                                   availRect.Height - rect.Height);
                                rects.Add(nr1);
                                rects.Add(nr2);
                            }
                            break;
                        }
                    }
                    else if (availRect.Width >= rect.Width && availRect.Height < rect.Height)
                    {
                        if (HeightInfinity(availRect, rect, W, L))
                        {
                            //move to upper left corner
                            rect.X = availRect.X;
                            rect.Y = -r;

                            resRects.Add(new Tuple<Rect, int>(rect, hnd.Item2));

                            // remove old
                            rects.RemoveAt(j);
                            // horiz
                            var nr1 = new Rect(availRect.X + rect.Width, availRect.Y, availRect.Width - rect.Width,
                                               availRect.Height);
                            rects.Add(nr1);
                            break;
                        }
                    }
                    else if (availRect.Width < rect.Width && availRect.Height >= rect.Height)
                    {
                        if (WidthInfinity(availRect, rect, W, L))
                        {
                            //move to upper left corner
                            rect.X = -r;
                            rect.Y = availRect.Y;
                            resRects.Add(new Tuple<Rect, int>(rect, hnd.Item2));

                            // remove old
                            rects.RemoveAt(j);
                            // horiz
                            var nr1 = new Rect(availRect.X, availRect.Y + rect.Height, availRect.Width,
                                               availRect.Height - rect.Height);
                            rects.Add(nr1);
                            break;
                        }
                    }
                    
                }
                
            }


            StringBuilder sb = new StringBuilder();
            var xyz = resRects.OrderBy(x => x.Item2).ToList();
            foreach (var rr in xyz)
            {
                var resRect = rr.Item1;
                sb.Append("" + (resRect.X + resRect.Width/2.0) + " ").
                    Append("" + (resRect.Y + resRect.Height/2.0) + " ");
            }
            result = sb.ToString().Trim();

            return result;
        }

        private static bool WidthInfinity(Rect availRect, Rect rect, int W, int L)
        {
            if (availRect.X == 0 && availRect.Width == W)
            {
                return true;
            }
            return false;
        }

        private static bool HeightInfinity(Rect availRect, Rect rect, int W, int L)
        {
            if (availRect.Y == 0 && availRect.Height == L)
            {
                return true;
            }
            return false;
        }

        private static bool CanFit(int W, int L, Rect rect, Rect availRect)
        {
            if (availRect.Width >= rect.Width)
            {
                if (availRect.Height >= rect.Height)
                {
                    return true;
                }
            }

            return false;
        }

    }

}
