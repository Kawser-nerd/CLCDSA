using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamQR2012
{
    class Program
    {
        private enum MapContents
        {
            Mirror,
            Empty,
            You
        }

        private class Slope
        {
            public Slope(int xChange, int yChange)
            {
                XChange = xChange;
                YChange = yChange;
            }

            public bool Matches(int otherX, int otherY)
            {
                bool matches;

                if (otherX == 0)
                {
                    if (XChange == 0)
                    {
                        // matches if Y dir is the same
                        matches = (otherY > 0) == (YChange > 0);
                    }
                    else
                    {
                        matches = false;
                    }
                }
                else if (otherY == 0)
                {
                    if (YChange == 0)
                    {
                        // matches if X dir is the same
                        matches = (otherX > 0) == (XChange > 0);
                    }
                    else
                    {
                        matches = false;
                    }
                }
                else if (XChange == 0 || YChange == 0)
                {
                    // should have matched above
                    matches = false;
                }
                else
                {
                    // no zeroes!
                    if ((otherX > 0 == XChange > 0)
                        && (otherY > 0 == YChange > 0)
                        && (otherX * YChange == otherY * XChange))
                    {
                        // same directions and same slopes
                        matches = true;
                    }
                    else
                    {
                        // nope
                        matches = false;
                    }
                }

                return matches;
            }

            public readonly int XChange;
            public readonly int YChange;
        }

        static private void QR_D()
        {
            int numTestCases = Int32.Parse(Console.ReadLine());
            for (int zz = 0; zz < numTestCases; zz++)
            {
                string dimensionsText = Console.ReadLine();
                string[] dimSplits = dimensionsText.Split(' ');

                int h = Int32.Parse(dimSplits[0]);
                int w = Int32.Parse(dimSplits[1]);
                int d = Int32.Parse(dimSplits[2]);

                MapContents[,] map = new MapContents[w, h];

                int youH = -1;
                int youW = -1;

                // read the map
                for (int hLoop = 0; hLoop < h; hLoop++)
                {
                    string rowText = Console.ReadLine();

                    for (int wLoop = 0; wLoop < w; wLoop++)
                    {
                        if (rowText[wLoop] == '#')
                        {
                            map[wLoop, hLoop] = MapContents.Mirror;
                        }
                        else if (rowText[wLoop] == '.')
                        {
                            map[wLoop, hLoop] = MapContents.Empty;
                        }
                        else if (rowText[wLoop] == 'X')
                        {
                            map[wLoop, hLoop] = MapContents.You;
                            youH = hLoop;
                            youW = wLoop;
                        }
                    }
                }

                List<Slope> slopesToCheck = new List<Slope>();

                // find slopes to check in a circle
                for (int x = -d; x <= d; x++)
                {
                    for (int y = -d; y <= d; y++)
                    {
                        if (x != 0 || y != 0)
                        {
                            if ((x * x + y * y) <= (d * d))
                            {
                                // the grid point is within d distance, check for it
                                if (slopesToCheck.Any(s => s.Matches(x, y)))
                                {
                                    // already have something going that way
                                }
                                else
                                {
                                    slopesToCheck.Add(new Slope(x, y));
                                }
                            }
                        }
                    }
                }

                // now i got slopes to check, do crappy raycasting in those directions to a distance of D to see if the ray comes home
                // since the duplicated slopes were removed, every successful ray cast from the list is a visible ME
                int successfulCasts = 0;
                foreach (Slope currentSlope in slopesToCheck)
                {
                    // work on a doubled grid so the center of me is on a grid point just like mirrors
                    double startX = 2 * youW + 1;
                    double startY = 2 * youH + 1;
                    double currentX = startX;
                    double currentY = startY;

                    int currentXChange = currentSlope.XChange;
                    int currentYChange = currentSlope.YChange;

                    double distanceRemaining = 2 * d + 0.0001; // 1/10k should be plenty of error, and not something I'l get near, considering the size of the room

                    while (distanceRemaining > 0)
                    {
                        double nextX;
                        double nextY;

                        if (currentXChange == 0)
                        {
                            nextX = currentX;

                            if (currentYChange > 0)
                            {
                                // move up to the next integer
                                nextY = Math.Floor(currentY + 1);
                            }
                            else
                            {
                                // move down to the next integer
                                nextY = Math.Ceiling(currentY - 1);
                            }
                        }
                        else if (currentYChange == 0)
                        {
                            nextY = currentY;

                            if (currentXChange > 0)
                            {
                                // move up to the next integer
                                nextX = Math.Floor(currentX + 1);
                            }
                            else
                            {
                                // move down to the next integer
                                nextX = Math.Ceiling(currentX - 1);
                            }
                        }
                        else
                        {
                            // currentXChange and currentYChange are non-zero
                            // advance to the next grid line
                            double xChangeToLine;
                            if (currentXChange > 0)
                            {
                                xChangeToLine = Math.Floor(currentX + 1) - currentX;
                            }
                            else
                            {
                                xChangeToLine = Math.Ceiling(currentX - 1) - currentX;
                            }

                            double yChangeToLine;
                            if (currentYChange > 0)
                            {
                                yChangeToLine = Math.Floor(currentY + 1) - currentY;
                            }
                            else
                            {
                                yChangeToLine = Math.Ceiling(currentY - 1) - currentY;
                            }

                            if (xChangeToLine / currentXChange > yChangeToLine / currentYChange)
                            {
                                // x to line needs more time, use y change to line
                                nextY = currentY + yChangeToLine;
                                nextX = currentX + currentXChange * (yChangeToLine / currentYChange);
                            }
                            else
                            {
                                // y to line needs more time, use x change to line
                                nextX = currentX + xChangeToLine;
                                nextY = currentY + currentYChange * (xChangeToLine / currentXChange);
                            }
                        }

                        // fix nextX and nextY for close-enough
                        if (Math.Abs(Math.Round(nextX) - nextX) < 0.0001)
                        {
                            nextX = Math.Round(nextX);
                        }
                        if (Math.Abs(Math.Round(nextY) - nextY) < 0.0001)
                        {
                            nextY = Math.Round(nextY);
                        }

                        // update distanceRemaining
                        double xDiff = nextX - currentX;
                        double yDiff = nextY - currentY;
                        distanceRemaining -= Math.Sqrt(xDiff * xDiff + yDiff * yDiff);

                        if (distanceRemaining < 0)
                        {
                            // outta gas
                            break;
                        }
                        else
                        {
                            if (nextX == startX && nextY == startY)
                            {
                                // back to 'me'
                                successfulCasts++;
                                break;
                            }
                            else
                            {
                                bool xAtEvenGridline = (nextX == Math.Round(nextX) && ((int)nextX) % 2 == 0);
                                bool yAtEvenGridline = (nextY == Math.Round(nextY) && ((int)nextY) % 2 == 0);

                                if (xAtEvenGridline && yAtEvenGridline)
                                {
                                    // hitting both even grid lines at once
                                    // check for mirror surface hit, or either corner hit, or squeezing

                                    int nextGridX = ((int)(nextX + ((currentXChange > 0) ? 0.5 : -0.5))) / 2;
                                    int nextGridY = ((int)(nextY + ((currentYChange > 0) ? 0.5 : -0.5))) / 2;

                                    if (map[nextGridX, nextGridY] == MapContents.Mirror)
                                    {
                                        int oldGridX = ((int)(nextX + ((currentXChange > 0) ? -0.5 : 0.5))) / 2;
                                        int oldGridY = ((int)(nextY + ((currentYChange > 0) ? -0.5 : 0.5))) / 2;

                                        bool otherXisMirror = (map[oldGridX, nextGridY] == MapContents.Mirror);
                                        bool otherYisMirror = (map[nextGridX, oldGridY] == MapContents.Mirror);

                                        if (otherXisMirror && otherYisMirror)
                                        {
                                            // mirror corner, double bounce
                                            currentXChange = -currentXChange;
                                            currentYChange = -currentYChange;
                                        }
                                        else if (otherXisMirror)
                                        {
                                            // both x blocks are mirrors, bounce along y
                                            currentYChange = -currentYChange;
                                        }
                                        else if (otherYisMirror)
                                        {
                                            // both y blocks are mirrors, bounce along x
                                            currentXChange = -currentXChange;
                                        }
                                        else
                                        {
                                            // nailing a mirror corner - die
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        // not crashing into a mirror, so keep going
                                    }
                                }
                                else if (xAtEvenGridline)
                                {
                                    // check for mirror surface hit
                                    int gridX;
                                    if (currentXChange > 0)
                                    {
                                        gridX = ((int)(nextX + 0.5)) / 2;
                                    }
                                    else
                                    {
                                        gridX = ((int)(nextX - 0.5)) / 2;
                                    }

                                    int gridY = ((int)nextY) / 2;
                                    if (map[gridX, gridY] == MapContents.Mirror)
                                    {
                                        // bounce
                                        currentXChange = -currentXChange;
                                    }
                                }
                                else if (yAtEvenGridline)
                                {
                                    // check for mirror surface hit
                                    int gridY;
                                    if (currentYChange > 0)
                                    {
                                        gridY = ((int)(nextY + 0.5)) / 2;
                                    }
                                    else
                                    {
                                        gridY = ((int)(nextY - 0.5)) / 2;
                                    }

                                    int gridX = ((int)nextX) / 2;
                                    if (map[gridX, gridY] == MapContents.Mirror)
                                    {
                                        // bounce
                                        currentYChange = -currentYChange;
                                    }
                                }
                            }
                        }

                        currentX = nextX;
                        currentY = nextY;
                    }
                }

                Console.WriteLine(String.Format("Case #{0}: {1}", zz + 1, successfulCasts));
            }
        }

        static void Main(string[] args)
        {
            QR_D();
        }
    }
}
