using System;
using System.Collections.Generic;
using System.Text;

namespace Google_Code_Jam_2013_R1B
{
    class B
    {
        static string solve(Queue<string> input)
        {
            string[] inputs = input.Dequeue().Split(' ');

            int n = Int32.Parse(inputs[0]);
            int x = Int32.Parse(inputs[1]);
            int y = Int32.Parse(inputs[2]);

            Dictionary<int, Dictionary<int, bool>> points = new Dictionary<int, Dictionary<int, bool>>();

            return String.Format("{0:N6}", solve(points, n, x, y, 0));
        }

        static double solve(Dictionary<int, Dictionary<int, bool>> points, int n, int x, int y, int yMax)
        {
            while (n > 0)
            {
                --n;
                int theX = 0;
                int theY = yMax + 2;

                if (!Fall(points, ref theX, ref theY, yMax))
                {
                    double leftResult = 0.0;
                    double rightResult = 0.0;

                    Dictionary<int, Dictionary<int, bool>> pointsCopy = Copy(points);
                    int xLeft = theX - 1, yLeft = theY - 1;
                    Fall(pointsCopy, ref xLeft, ref yLeft, yMax);

                    // Set points occupied
                    MarkOccupied(pointsCopy, xLeft, yLeft);
                    //Console.WriteLine("{0}, {1}", xLeft, yLeft);

                    // Check to see if the center is on x,y or if x,y is covered
                    if (xLeft == x && yLeft == y)
                        leftResult = 1.0;
                    else if (IsOccupied(pointsCopy, x, y))
                        leftResult = 0.0;
                    else
                    {
                        //Console.WriteLine("Going left");
                        leftResult = solve(pointsCopy, n, x, y, (yMax < yLeft + 3 ? yLeft + 3 : yMax));
                        //Console.WriteLine("Finished going left");
                    }

                    pointsCopy = Copy(points);
                    int xRight = theX + 1, yRight = theY - 1;
                    Fall(pointsCopy, ref xRight, ref yRight, yMax);

                    // Set points occupied
                    MarkOccupied(pointsCopy, xRight, yRight);
                    //Console.WriteLine("{0}, {1}", xRight, yRight);

                    // Check to see if the center is on x,y or if x,y is covered
                    if (xRight == x && yRight == y)
                        rightResult = 1.0;
                    else if (IsOccupied(pointsCopy, x, y))
                        rightResult = 0.0;
                    else
                    {
                        //Console.WriteLine("Going right");
                        rightResult = solve(pointsCopy, n, x, y, (yMax < yRight + 3 ? yRight + 3 : yMax));
                        //Console.WriteLine("Finished going right");
                    }

                    return (.5 * leftResult) + (.5 * rightResult);
                }
                //Console.WriteLine("{0}, {1}", theX, theY);
                // Set points occupied
                MarkOccupied(points, theX, theY);
                if (yMax < theY + 3)
                    yMax = theY + 3;

                // Check to see if the center is on x,y or if x,y is covered
                if (theX == x && theY == y)
                    return 1.0;
                else if (IsOccupied(points, x, y))
                    return 0.0;
            }

            return 0.0;
        }

        private static bool Fall(Dictionary<int, Dictionary<int, bool>> points, ref int x, ref int y, int yMax)
        {
            while (true)
            {
                if (y == 0)
                    break;

                if (IsOccupied(points, x, y - 1)) // down
                {
                    if (IsOccupied(points, x - 1, y - 1)) // left
                    {
                        if (IsOccupied(points, x + 1, y - 1)) // right
                        {
                            // Stopped on each side
                            break;
                        }
                        else
                        {
                            // Fall right
                            --y;
                            ++x;
                        }
                    }
                    else if (IsOccupied(points, x + 1, y - 1)) // right
                    {
                        // Fall left
                        --y;
                        --x;
                    }
                    else
                    {
                        // Could fall either way, return false to figure it out
                        return false;
                    }
                }
                else
                {
                    // Fall down
                    --y;
                }
            }

            return true;
        }

        private static bool IsOccupied(Dictionary<int, Dictionary<int, bool>> points, int x, int y)
        {
            if (points.ContainsKey(x) && points[x].ContainsKey(y))
                return true;
            return false;
        }

        private static void MarkOccupied(Dictionary<int, Dictionary<int, bool>> points, int x, int y)
        {
            if (!points.ContainsKey(x))
                points.Add(x, new Dictionary<int, bool>());
            if (!points.ContainsKey(x - 1))
                points.Add(x - 1, new Dictionary<int, bool>());
            if (!points.ContainsKey(x + 1))
                points.Add(x + 1, new Dictionary<int, bool>());

            points[x][y] = true;
            points[x][y - 1] = true;
            points[x][y + 1] = true;
            points[x - 1][y] = true;
            points[x + 1][y] = true;
        }

        private static Dictionary<int, Dictionary<int, bool>> Copy(Dictionary<int, Dictionary<int, bool>> points)
        {
            Dictionary<int, Dictionary<int, bool>> copy = new Dictionary<int, Dictionary<int, bool>>(points.Count);

            foreach (int key in points.Keys)
            {
                copy.Add(key, new Dictionary<int, bool>(points[key]));
            }

            return copy;
        }

        static void Main(string[] args)
        {
            string filename = "..\\..\\io\\" + "B-small-attempt1.in";
            Queue<string> input = new Queue<string>(System.IO.File.ReadAllLines(filename));

            int numCases = Int32.Parse(input.Dequeue());

            System.IO.StreamWriter sw = new System.IO.StreamWriter(filename.Replace("in", "out"), false);

            for (int i = 1; i <= numCases; i++)
            {
                sw.WriteLine("Case #{0}: {1}", i, solve(input));
            }

            sw.Close();
        }
    }
}
