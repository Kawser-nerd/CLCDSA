using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class A
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("b.in.txt");
            StreamWriter output = new StreamWriter("b.out.txt");

            int tc = Int32.Parse(input.ReadLine());

            for (int i = 0; i < tc; i++)
                output.WriteLine("Case #{0}: {1}", i + 1, solveCase(input));

            input.Close();
            output.Close();
        }

        static bool[][] map;
        static int?[, ,] cache = new int?[80, 80, 80];


        static void go(int row)
        {
            for(int i=0;i<width;i++)
                for (int j = 0; j <= width; j++)
                {
                    int? c = cache[row, i, j];
                    if (c != null)
                        go(row, i, j, c.Value);
                }
        }

        static void  go(int row, int from, int to, int cost)
        {
            bool rightEmpty = map[row + 1][to - 1] == false;
            bool leftEmpty = map[row + 1][from] == false;

            int rwb = rightEmpty ? to - 1 : to;
            int lwb = leftEmpty ? from + 1 : from;

            for (int digFrom = from; digFrom < rwb - 1; digFrom++)
                for (int digTo = digFrom+1; digTo < rwb; digTo++)
                    tryDig(row + 1, digFrom, digTo, digTo - 1, cost + (digTo - digFrom) - (leftEmpty && digFrom == from ? 1 : 0), row);
            
            for (int digFrom = lwb+1; digFrom < to; digFrom++)
                for (int digTo = digFrom+1; digTo <= to; digTo++)
                    tryDig(row + 1, digFrom, digTo, digFrom, cost + (digTo - digFrom) - (rightEmpty && digTo == to ? 1 : 0), row);
        }

        static int worstFall;
        static int width;
        static int height;

        private static void tryDig(int row, int digFrom, int digTo, int fall, int cost, int fallFrom)
        {
            if(row-fallFrom > worstFall)
                return;
            if (row == height - 1)
                registerSuccess(cost);
            if (map[row + 1][fall] == false)
                    tryDig(row + 1, fall, fall + 1, fall, cost, fallFrom);
            else
            {
                int realFrom = fall;
                while (true)
                {
                    if (realFrom == 0)
                        break;
                    int newRF = realFrom - 1;
                    if (newRF < digFrom && map[row][newRF])
                        break;
                    realFrom = newRF;
                    if (map[row + 1][realFrom] == false)
                        break;
                }
                int realTo = fall;
                while (true)
                {
                    if (realTo == width - 1)
                        break;
                    int newRT = realTo + 1;
                    if (newRT >= digTo && map[row][newRT])
                        break;
                    realTo = newRT;
                    if (map[row + 1][realTo] == false)
                        break;
                }
                realTo++;

                updateCost(row, realFrom, realTo, cost);
            }
        }

        static int? bestSuccess;

        private static void registerSuccess(int cost)
        {
            if (bestSuccess == null || bestSuccess.Value > cost)
                bestSuccess = cost;
        }

        private static void updateCost(int row,int realFrom,int realTo,int cost)
        {
            var old = cache[row, realFrom, realTo];
            if (old == null || old.Value > cost)
                cache[row, realFrom, realTo] = cost;
        }

        private static string solveCase(StreamReader input)
        {
            bestSuccess = null;
            map = new bool[80][];

            var rcf = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
            height = rcf[0];
            width = rcf[1];
            worstFall = rcf[2];
            cache = new int?[height+1, width, width+1];

            for (int ln = 0; ln < height; ln++)
                map[ln] = input.ReadLine().Select(ch => ch == '#').ToArray();
            map[height] = map[0].Select(b => true).ToArray();

            tryDig(0, 0, 1, 0, 0, 0);

            for (int i = 0; i < height - 1; i++)
                go(i);

            return bestSuccess == null ? "No" : "Yes " + bestSuccess.Value;
        }
    }
}
