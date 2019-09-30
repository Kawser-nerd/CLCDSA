using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class HallOfMirrors
    {
        private static MirrorsCase[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int lineIndex = 0;
            int cases = int.Parse(lines[lineIndex++]);
            var result = new MirrorsCase[cases];
            for (int caseNo = 1; caseNo <= cases; caseNo++)
            {
                var items = lines[lineIndex++].Split(' ').Select(s => int.Parse(s)).ToArray();
                int H, W, D;
                H = items[0];
                W = items[1];
                D = items[2];

                var squares = new Sq[H][];

                var meX = 0.0;
                var meY = 0.0;

                for (int y = 0; y < H; y++)
                    squares[y] = lines[lineIndex++].Select(
                        (c, x) =>
                            c == '.' ?
                                Sq.Empty :
                                c == 'X' && ((meX = x + 0.5) + (meY = y + 0.5) <= int.MaxValue) ?
                                    Sq.Me :
                                    Sq.Mirror).ToArray();

                result[caseNo - 1] = new MirrorsCase { H = H, W = W, D = D, Squares = squares, MeX = meX, MeY = meY };
            }
            return result;
        }

        private enum Sq
        {
            Empty,
            Me,
            Mirror
        }

        private class MirrorsCase
        {
            public int H;
            public int W;
            public int D;
            public Sq[][] Squares;
            public double MeX;
            public double MeY;
        }

        public static void Main()
        {
            string inputSize = "large";
            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\HallOfMirrors\" + inputSize + " input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\HallOfMirrors\" + inputSize + " output.txt";

            var cases = ReadFile(inputFilepath);

            var outputFile = File.CreateText(outputFilepath);

            int caseNo = 1;

            foreach (var gCase in cases)
            {
                string outputLine = string.Format("Case #{0}: {1}", caseNo++, SolveCase(gCase));
                Console.WriteLine(outputLine);
                outputFile.WriteLine(outputLine);
            }

            outputFile.Close();
        }

        private static double epsilon = 0.00000001;

        private static int SolveCase(MirrorsCase gCase)
        {
            //NB: Store valid paths in coprime form to avoid double-counting overlapping images
            var validPaths = new Dictionary<Tuple<int, int>, double[][]>();

            var attemptedTrajectories = new Dictionary<Tuple<int, int>, bool>();

            double[][] path = null;

            for (int i = -gCase.D; i <= gCase.D; i++)
                for (int j = -gCase.D; j <= gCase.D; j++)
                    if ((i * i + j * j) <= gCase.D * gCase.D && !(i == 0 && j == 0))
                    {
                        var reducedTrajectory = Reduce(i, j);
                        if (attemptedTrajectories.ContainsKey(reducedTrajectory))
                            continue;
                        attemptedTrajectories[reducedTrajectory] = true;

                        if ((path = ValidPath(gCase, i, j)) != null)
                            validPaths[reducedTrajectory] = path;
                    }

            //int pathNo = 0;
            //foreach(var kvp in validPaths)
            //{
            //    Console.WriteLine(string.Format("#:{0}", pathNo++));
            //    foreach(var coords in kvp.Value)
            //        Console.WriteLine(string.Format("{0},{1}", coords[0], coords[1]));
            //}

            return validPaths.Count;
        }

        private static double D(double x1, double y1, double x2, double y2)
        {
            return (Math.Sqrt(Math.Pow(x1 - x2, 2) + Math.Pow(y1 - y2, 2)));
        }

        private static double StepFactor(double x, double y, int dx, int dy)
        {
            if(dx < 0) { dx = -dx; x = -x; }

            if(dy < 0) { dy = -dy; y = -y; }

            if(dx == 0 && dy == 0)
                throw new ArgumentOutOfRangeException();

            double xFactor = (Math.Ceiling(x + epsilon) - x) / dx;
            double yFactor = (Math.Ceiling(y + epsilon) - y) / dy;

            if (dx == 0)
                return (yFactor);

            if (dy == 0)
                return (xFactor);

            return (Math.Min(xFactor, yFactor));
        }

        public static bool IsNearInteger(double x)
        {
            return Math.Abs(Math.Round(x) - x) < epsilon;
        }

        private static void ApplyReflection(MirrorsCase gCase, double x, double y, ref int dx, ref int dy)
        {
            //(nx, ny) are the floor intersection to x + epsilon, y + epsilon
            int nx, ny;
            //(sx, sy) are the cell coordinates of the cell the ray is leaving
            int sx, sy;

            nx = (int)Math.Floor(x + epsilon);
            ny = (int)Math.Floor(y + epsilon);

            if (IsNearInteger(x) && dx > 0)
                sx = nx - 1;
            else
                sx = nx;

            if (IsNearInteger(y) && dy > 0)
                sy = ny - 1;
            else
                sy = ny;

            //Reorient so that the only relevant squares are E, NE and N
            var mirrorNeighbours = new[]{false, false, false};
            int dxSign = dx >= 0 ? 1 : -1;
            int dySign = dy >= 0 ? 1 : -1;

            mirrorNeighbours[0] = (gCase.Squares[sy][sx + dxSign] == Sq.Mirror);
            mirrorNeighbours[1] = (gCase.Squares[sy + dySign][sx + dxSign] == Sq.Mirror);
            mirrorNeighbours[2] = (gCase.Squares[sy + dySign][sx] == Sq.Mirror);

            if(IsNearInteger(x) && !IsNearInteger(y))
            {
                if(mirrorNeighbours[0])
                    dx *= -1;
                return;
            }

            if(!IsNearInteger(x) && IsNearInteger(y))
            {
                if(mirrorNeighbours[2])
                    dy *= -1;
                return;
            }

            if(IsNearInteger(x) && IsNearInteger(y))
            {
                if(mirrorNeighbours[0] && mirrorNeighbours[1])
                    dx *= -1;
                if(mirrorNeighbours[1] && mirrorNeighbours[2])
                    dy *= -1;

                if(mirrorNeighbours[1] && !mirrorNeighbours[0] && !mirrorNeighbours[2])
                    dx = dy = 0;
                return;
            }

            throw new Exception("Not on any square edge");
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="gCase"></param>
        /// <param name="tdX">X component of trajectory in transformed space</param>
        /// <param name="tdY">Y component of trajectory in transformed space</param>
        /// <returns></returns>
        private static double[][] ValidPath(MirrorsCase gCase, int tdX, int tdY)
        {
            if (tdX == 0 && tdY == 0)
                return null;

            // (rX,rY) are coordinates in real space
            double rX = gCase.MeX, rY = gCase.MeY;
            // (tX,tY) are coordinates in transformed space
            double tX = 0.5, tY = 0.5;

            // (rdX, rdY) are components of trajectory in real space
            int rdX = tdX, rdY = tdY;

            var resultList = new List<double[]>();
            resultList.Add(new []{rX, rY});

            while (true)
            {
                //stepFactor * current trajectory takes us to the next cell edge (in both real and transformed space)
                double stepFactor = StepFactor(tX, tY, tdX, tdY);

                //Check whether travelling half way to cell edge exhausts budget
                if (D(tX + 0.5 * stepFactor * tdX, tY + 0.5 * stepFactor * tdY, 0.5, 0.5) > (gCase.D + epsilon))
                    return null;

                //If travelling half way to cell edge hits Me, we are done
                if (D(rX + 0.5 * stepFactor * rdX, rY + 0.5 * stepFactor * rdY, gCase.MeX, gCase.MeY) < epsilon)
                {
                    resultList.Add(new []{gCase.MeX, gCase.MeY});
                    return resultList.ToArray();
                }

                tX += stepFactor * tdX;
                tY += stepFactor * tdY;

                rX += stepFactor * rdX;
                rY += stepFactor * rdY;

                resultList.Add(new[] { rX, rY });

                //Check whether travelling all the way to cell edge exhausted budget
                if (D(tX, tY, 0.5, 0.5) > (gCase.D + epsilon))
                    return null;

                ApplyReflection(gCase, rX, rY, ref rdX, ref rdY);
            }
        }

        public static Tuple<int, int> Reduce(int i, int j)
        {
            if (i == 0)
                return new Tuple<int, int>(0, Math.Sign(j));
            if (j == 0)
                return new Tuple<int, int>(Math.Sign(i), 0);

            int gcd = GCD(Math.Abs(i), Math.Abs(j));

            return new Tuple<int, int>(i / gcd, j / gcd);
        }

        public static int GCD(int i, int j)
        {
            if (j == 0)
                return i;
            return GCD(j, i - j * (i / j));
        }
    }
}