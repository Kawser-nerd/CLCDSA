using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;

namespace GCJ12QRQ4
{
    class Q4
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                string[] bits = lines[index].Split(' ');
                int H = int.Parse(bits[0]);
                int W = int.Parse(bits[1]);
                int D = int.Parse(bits[2]);
                bool[,] walls = new bool[W,H];
                int x = 0;
                int y = 0;
                for (int j = 0; j < H; j++)
                {
                    index++;
                    for (int k = 0; k < W; k++)
                    {
                        walls[k, j] = lines[index][k] == '#';
                        if (lines[index][k] == 'X')
                        {
                            x = k;
                            y = j;
                        }
                    }
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(H, W, D, walls, x, y)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int H, int W, int D, bool[,] walls, int x, int y)
        {
            int range = D;
            int count = 0;
            bool[,] tried = new bool[range * 2 + 3, range * 2 + 3];
            for (int ty = -range; ty <= range; ty++)
            {
                for (int tx = -range; tx <= range; tx++)
                {
                    if (tx == 0 && ty == 0)
                        continue;
                    int dx = tx;
                    int dy = ty;
                    if (dx != 0 && dy != 0)
                    {
                        int gcd = (int)BigInteger.GreatestCommonDivisor(new BigInteger(Math.Abs(dx)), new BigInteger(Math.Abs(dy)));
                        dx /= gcd;
                        dy /= gcd;
                    }
                    if (dy == 0)
                        dx = dx > 0 ? 1 : -1;
                    if (dx == 0)
                        dy = dy > 0 ? 1 : -1;
                    if (tried[dx + range + 1, dy + range + 1])
                        continue;
                    tried[dx + range + 1, dy + range + 1] = true;
                    if (Trace(H, W, D, walls, x, y, dx, dy))
                        count++;
                }
            }
            return count.ToString();
        }

        private static bool Trace(int H, int W, int D, bool[,] walls, int startX, int startY, int dx, int dy)
        {
            // Handle infinite/0 slope cases, since they are easy and will cause problems otherwise.
            if (dx == 0)
            {
                int cx = startX;
                int cy = startY;
                if (dy == 1)
                {
                    while (cy < H-1)
                    {
                        cy++;
                        if (walls[cx, cy])
                        {
                            return (cy - (startY )) * 2 - 1 <= D;
                        }
                    }
                    return false;
                }
                else
                {
                    while (cy > 0)
                    {
                        cy--;
                        if (walls[cx, cy])
                        {
                            return -(cy - (startY)) * 2 - 1 <= D;
                        }
                    }
                    return false;
                }
            }

            if (dy == 0)
            {
                int cx = startX;
                int cy = startY;
                if (dx == 1)
                {
                    while (cx < W - 1)
                    {
                        cx++;
                        if (walls[cx, cy])
                        {
                            return (cx - (startX)) * 2 - 1 <= D;
                        }
                    }
                    return false;
                }
                else
                {
                    while (cx > 0)
                    {
                        cx--;
                        if (walls[cx, cy])
                        {
                            return -(cx - (startX)) * 2 - 1 <= D;
                        }
                    }
                    return false;
                }
            }
            return TraceSlope(H, W, D, walls, startX, startY, dx, dy);
        }

        private static bool TraceSlope(int H, int W, int D, bool[,] walls, int startX, int startY, int dx, int dy)
        {
            Fraction currentX = new Fraction(startX, 1) + new Fraction(1, 2);
            Fraction currentY = new Fraction(startY, 1) + new Fraction(1, 2);
            Fraction targetX = currentX;
            Fraction targetY = currentY;

            Fraction nextX = currentX + new Fraction(dx > 0 ? 1 : -1,2);
            Fraction nextY = currentY + new Fraction(dy > 0 ? 1: -1, 2);
            Fraction cumulativeX = new Fraction(0,1);
            Fraction cumulativeY = new Fraction(0,1);
            while (true)
            {
                Fraction projectX = (nextY - currentY) * new Fraction(dx, 1) / new Fraction(dy, 1) + currentX;
                Fraction projectY = (nextX - currentX) * new Fraction(dy, 1) / new Fraction(dx, 1) + currentY;
                if ((projectX - nextX) * (dx > 0 ? new Fraction(1, 1) : new Fraction(-1, 1)) > new Fraction(0, 1))
                {
                    cumulativeX = cumulativeX + Abs(nextX - currentX);
                    cumulativeY = cumulativeY + Abs(projectY - currentY);
                    currentX = nextX;
                    currentY = projectY;
                }
                else
                {
                    cumulativeX = cumulativeX + Abs(projectX - currentX);
                    cumulativeY = cumulativeY + Abs(nextY - currentY);
                    currentX = projectX;
                    currentY = nextY;
                }

                // Don't walk too far.
                if (!DistCheck(cumulativeX, cumulativeY, D))
                    return false;

                // have we made it?
                if (currentX == targetX && currentY == targetY)
                    return true;

                if (currentX.Denominator == 1)
                {
                    if (currentY.Denominator == 1)
                    {
                        // Corner check
                        // 3 options
                        // 1 do nothing
                        // 2 reflect
                        // 3 fail
                        int xToCheck = (int)currentX.Numerator;
                        int yToCheck = (int)currentY.Numerator;
                        if (dx < 0)
                            xToCheck--;
                        if (dy < 0)
                            yToCheck--;
                        if (walls[xToCheck, yToCheck])
                        {
                            // either reflect or fail...
                            if (dx > 0 && dy > 0)
                            {
                                int failCount = 0;
                                if (walls[xToCheck - 1, yToCheck])
                                {
                                    dy = -dy;
                                }
                                else failCount++;
                                if (walls[xToCheck, yToCheck - 1])
                                {
                                    dx = -dx;
                                }
                                else failCount++;

                                if (failCount == 2)
                                    return false;
                            }
                            else if (dx > 0)
                            {
                                int failCount = 0;
                                if (walls[xToCheck - 1, yToCheck])
                                {
                                    dy = -dy;
                                }
                                else failCount++;
                                if (walls[xToCheck, yToCheck + 1])
                                {
                                    dx = -dx;
                                }
                                else failCount++;

                                if (failCount == 2)
                                    return false;
                            }
                            else if (dy > 0)
                            {
                                int failCount = 0;
                                if (walls[xToCheck + 1, yToCheck])
                                {
                                    dy = -dy;
                                }
                                else failCount++;
                                if (walls[xToCheck, yToCheck - 1])
                                {
                                    dx = -dx;
                                }
                                else failCount++;

                                if (failCount == 2)
                                    return false;
                            }
                            else
                            {
                                int failCount = 0;
                                if (walls[xToCheck + 1, yToCheck])
                                {
                                    dy = -dy;
                                }
                                else failCount++;
                                if (walls[xToCheck, yToCheck + 1])
                                {
                                    dx = -dx;
                                }
                                else failCount++;

                                if (failCount == 2)
                                    return false;
                            }
                        }
                    }
                    else
                    {
                        // vert edge check.
                        int xToCheck = (int)currentX.Numerator;
                        int yToCheck = Floor(currentY);
                        if (dx < 0)
                            xToCheck--;
                        if (walls[xToCheck, yToCheck])
                            dx = -dx;
                    }
                }
                else
                {
                    if (currentY.Denominator == 1)
                    {
                        // horiz edge check.
                        int xToCheck = Floor(currentX);
                        int yToCheck = (int)currentY.Numerator;
                        if (dy < 0)
                            yToCheck--;
                        if (walls[xToCheck, yToCheck])
                            dy = -dy;
                    }
                }

                if (currentX.Denominator == 1 || currentX.Denominator == 2)
                {
                    nextX = currentX + new Fraction(dx > 0 ? 1 : -1, 2);
                }
                else
                {
                    // round to next half in direction of dx.
                    if (dx > 0)
                    {
                        nextX = new Fraction(Floor(currentX * new Fraction(2, 1)) + 1, 2);
                    }
                    else
                    {
                        nextX = new Fraction(Floor(currentX * new Fraction(2, 1)), 2);
                    }
                }
                if (currentY.Denominator == 1 || currentY.Denominator == 2)
                {
                    nextY = currentY + new Fraction(dy > 0 ? 1 : -1, 2);
                }
                else
                {
                    if (dy > 0)
                    {
                        nextY = new Fraction(Floor(currentY * new Fraction(2, 1)) + 1, 2);
                    }
                    else
                    {
                        nextY = new Fraction(Floor(currentY * new Fraction(2, 1)), 2);
                    }
                }
            }


            return false;
        }

        private static int Floor(Fraction currentX)
        {
            return (int)(currentX.Numerator / currentX.Denominator);
        }

        private static bool DistCheck(Fraction cumulativeX, Fraction cumulativeY, int D)
        {
            return !((cumulativeX*cumulativeX + cumulativeY*cumulativeY) > new Fraction(D*D,1));
        }

        static Fraction Abs(Fraction input)
        {
            if (input.Denominator > 0 && input.Numerator >= 0)
                return input;
            if (input.Denominator < 0 && input.Numerator <= 0)
                return input;
            return new Fraction(-input.Numerator, input.Denominator);
        }

    }
}
