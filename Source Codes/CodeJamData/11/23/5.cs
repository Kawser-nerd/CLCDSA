using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam_2011_round1B
{
    public class Room
    {
        public int[] Points
        {
            get;
            set;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Checks
            if (args.Length != 1)
            {
                Console.WriteLine("Specify input file");
                Console.ReadLine();
                return;
            }

            StreamReader reader = new StreamReader(args[0]);
            int t = int.Parse(reader.ReadLine());
            for (int current = 1; current <= t; ++current)
            {
                string[] firstLineTokens = reader.ReadLine().Split(' ');
                int n = int.Parse(firstLineTokens[0]);
                int m = int.Parse(firstLineTokens[1]);
                int[] startPoints = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                int[] endPoints = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

                int[] allPoints = new int[n];
                for (int a = 1; a <= n; ++a)
                {
                    allPoints[a - 1] = a;
                }
                List<Room> rooms = new List<Room>() { new Room { Points = allPoints.ToArray() } };

                for (int a = 0; a < m; ++a)
                {
                    int start = startPoints[a];
                    int end = endPoints[a];
                    Room containingRoom = null;
                    foreach (Room testRoom in rooms)
                    {
                        if (testRoom.Points.Contains(start) && testRoom.Points.Contains(end))
                        {
                            containingRoom = testRoom;
                            break;
                        }
                    }
                    System.Diagnostics.Debug.Assert(containingRoom != null);
                    if (start > end)
                    {
                        int buffer = start;
                        start = end;
                        end = buffer;
                    }
                    List<int> roomAPoints = new List<int>();
                    List<int> roomBPoints = new List<int>();
                    foreach (int point in containingRoom.Points)
                    {
                        if (point == start || point == end)
                        {
                            roomAPoints.Add(point);
                            roomBPoints.Add(point);
                        }
                        else
                        {
                            if (point > start && point < end)
                            {
                                roomAPoints.Add(point);
                            }
                            else
                            {
                                roomBPoints.Add(point);
                            }
                        }
                    }

                    rooms.Remove(containingRoom);
                    rooms.Add(new Room() { Points = roomAPoints.ToArray() });
                    rooms.Add(new Room() { Points = roomBPoints.ToArray() });
                }

                int c = rooms.Select(x => x.Points.Length).Min();

                int[] colors = new int[c];
                for (int a = 1; a <= c; ++a) 
                {
                    colors[a - 1] = a;
                }

                int[] pillarsColor = new int[n];
                while (rooms.Count > 0)
                {
                    // Select room to give the least colors for
                    Room leastColorRoom = rooms
                                                .OrderBy(x => PointsNeeded(x, pillarsColor))
                                                .ThenBy(x => c - ColorsNeed(x, c, pillarsColor)).First();
                    int colorsNeeded = ColorsNeed(leastColorRoom, c, pillarsColor);
                    if (colorsNeeded == 0)
                    {
                        rooms.Remove(leastColorRoom);
                    }
                    else
                    {
                        int colorlessPoint = 0;
                        List<int> colorsHave = new List<int>();
                        foreach (int lcrPoint in leastColorRoom.Points)
                        {
                            int lcrPointColor = pillarsColor[lcrPoint - 1];
                            if (lcrPointColor != 0)
                            {
                                colorsHave.Add(lcrPointColor);
                            }
                            else if (colorlessPoint == 0)
                            {
                                colorlessPoint = lcrPoint;
                            }
                        }
                        int[] availableColors = colors.Where(x => !colorsHave.Contains(x)).ToArray();
                        pillarsColor[colorlessPoint - 1] = availableColors[0];
                    }
                }
                for (int a = 0; a < n; ++a)
                {
                    if (pillarsColor[a] == 0)
                    {
                        pillarsColor[a] = 1;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", current, c);
                string outputColors = string.Join(" ", pillarsColor.Select(x => x.ToString()).ToArray());
                Console.WriteLine(outputColors);
            }
        }

        private static int ColorsNeed(Room room, int c, int[] pillarsColor)
        {
            int colorsCount = 0;
            List<int> colorsHave = new List<int>();
            foreach (int point in room.Points)
            {
                int pointColor = pillarsColor[point - 1];
                if (pointColor != 0 && !colorsHave.Contains(pointColor))
                {
                    colorsHave.Add(pointColor);
                    colorsCount += 1;
                }
            }
            return c - colorsCount;
        }

        private static int PointsNeeded(Room room, int[] pillarsColor)
        {
            int needCount = 0;
            foreach (int point in room.Points)
            {
                if (pillarsColor[point-1] == 0)
                {
                    needCount += 1;
                }
            }
            return needCount;
        }
    }
}
