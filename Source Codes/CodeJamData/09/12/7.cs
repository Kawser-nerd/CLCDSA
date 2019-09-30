using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GJ
{
    public class Crossing
    {
        int rows;
        int columns;
        TrafficLight[] lights;
        int result;
        int width;
        int height;
        bool[] close;


        public void Run(string iPath, string oPath)
        {
            StreamReader inFileName = new StreamReader(iPath);
            StreamWriter outFileName = new StreamWriter(oPath);

            int cases = int.Parse(inFileName.ReadLine());
            char[] split = { ' ' };
            for (int i = 0; i < cases; i++)
            {
                string[] line = inFileName.ReadLine().Split(split);
                rows = int.Parse(line[0]);
                columns = int.Parse(line[1]);
                lights = new TrafficLight[rows * columns];
                for (int row = 0; row < rows; row++)
                {
                    line = inFileName.ReadLine().Split(split);
                    for (int column = 0; column < columns; column++)
                    {
                        TrafficLight l = new TrafficLight();
                        l.s = int.Parse(line[column * 3]);
                        l.w = int.Parse(line[column * 3 + 1]);
                        l.t = int.Parse(line[column * 3 + 2]);
                        lights[row * columns + column] = l;
                    }
                }
                CodeJam.WriteCase(outFileName, i + 1, Solve().ToString());
            }

            inFileName.Close();
            outFileName.Close();
        }

        private int Solve()
        {
            result = int.MaxValue;
            width = columns * 2;
            height = rows * 2;
            close = new bool[width * height];
            for (int i = 0; i < close.Length; i++)
                close[i] = false;
            FindPath(0, height - 1, 0);
            return result;
        }

        private void FindPath(int x, int y, int cost)
        {
            // check for cost
            if (cost > result)
                return;
            // check for end
            if (y == 0 && x == width - 1)
            {
                result = cost;
                return;
            }
            // close
            close[x + y * width] = true;
            // temp vars
            int nextX;
            int nextY;
            int step;
            // east
            nextX = x + 1;
            nextY = y;
            if ((step = GetCost(x, y, nextX, nextY, cost)) > 0)
                FindPath(nextX, nextY, cost + step);
            // north
            nextX = x;
            nextY = y - 1;
            if ((step = GetCost(x, y, nextX, nextY, cost)) > 0)
                FindPath(nextX, nextY, cost + step);
            // south
            nextX = x;
            nextY = y + 1;
            if ((step = GetCost(x, y, nextX, nextY, cost)) > 0)
                FindPath(nextX, nextY, cost + step);
            // west
            nextX = x - 1;
            nextY = y;
            if ((step = GetCost(x, y, nextX, nextY, cost)) > 0)
                FindPath(nextX, nextY, cost + step);
        }

        int GetCost(int x, int y, int nextX, int nextY, int cost)
        {
            // check valid
            if (nextX < 0 || nextY < 0 || nextX >= width || nextY >= height)
                return -1;
            //if (close[nextX + nextY * width])
            //    return -1;
            // if not crossing the road
            if (!IsCrossing(x, y, nextX, nextY))
                return 2;
            // return the wait time + 1
            return GetWaitTime(x, y, nextX, nextY, cost) + 1;
        }

        private bool IsCrossing(int x, int y, int nextX, int nextY)
        {
            return ((x / 2 == nextX / 2) && (y / 2 == nextY / 2));
        }

        private int GetWaitTime(int x, int y, int nextX, int nextY, int cost)
        {
            // get direction
            bool south = (y != nextY);
            return GetWaitTimeAtLight(y / 2, x / 2, cost, south);
        }

        int GetWaitTimeAtLight(int row, int column, int cost, bool south)
        {
            TrafficLight l = lights[row * columns + column];
            cost -= l.t;
            while (cost < 0)
                cost += l.s + l.w;
            int time = cost % (l.s + l.w);
            if (south)
            {
                if (time < l.s)
                    return 0;
                else
                    return (l.s + l.w) - time;
            }
            else
            {
                if (time >= l.s)
                    return 0;
                else
                    return (l.s - time);
            }
        }


        struct TrafficLight
        {
            public int s;
            public int w;
            public int t;
        }
    }
}
