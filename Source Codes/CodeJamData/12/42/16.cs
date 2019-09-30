using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round2
{
    class Program
    {
        static int ReadInt(System.IO.StreamReader reader)
        {
            return int.Parse(reader.ReadLine());
        }

        static Int64 ReadInt64(System.IO.StreamReader reader)
        {
            return Int64.Parse(reader.ReadLine());
        }

        static List<int> ReadIntList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static List<Int64> ReadInt64List(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToList();
        }

        static int[] ReadIntArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static int[] ReadIntData(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static Int64[] ReadInt64Array(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToArray();
        }

        static List<string> ReadStringList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').ToList();
        }

        class Point
        {
            public double x;
            public double y;
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);
            for (int i = 1; i <= T; i++)
            {
                Int64[] data = ReadInt64Array(reader);
                Int64 N = data[0];
                Int64 W = data[1];
                Int64 L = data[2];

                List<Int64> radius = ReadInt64List(reader);
                Dictionary<int, Int64> radiuses = new Dictionary<int, Int64>();
                for (int j = 0;j < radius.Count;j++)
                    radiuses.Add(j, radius[j]);
                
                radiuses = radiuses.OrderBy(x => x.Value).ToDictionary(x => x.Key, x => x.Value);

                Dictionary<int, Point> points = new Dictionary<int, Point>();
                Point p = new Point();
                p.x = 0;
                p.y = 0;

                Int64 maxRadius = radiuses.Last().Value;
                points.Add(radiuses.Last().Key, p);
                radiuses.Remove(radiuses.Last().Key);
                
                Int64 xCount = 0;
                Int64 yCount = 0;
                
                xCount += maxRadius;
                yCount = 0;

                bool firstTime = true;
                for (int j = 1; j < N; j++)
                {
                    Point pj = new Point();

                    int key = radiuses.Last().Key;
                    if (radiuses[key] > W - xCount)
                    {
                        if (firstTime)
                        {
                            firstTime = false;
                            yCount += maxRadius;
                        }
                        else
                            yCount += 2 * maxRadius;
                        if (yCount > L)
                        {
 
                        }
                        pj.x = 0;
                        pj.y = yCount + radiuses[key];

                        maxRadius = radiuses[key];
                        xCount = radiuses[key];
                    }
                    else
                    {
                        pj.x = xCount + radiuses[key];
                        if (firstTime)
                            pj.y = yCount;
                        else
                            pj.y = yCount + radiuses[key];
                        xCount = xCount + 2 * radiuses[key];
                    }

                    points.Add(radiuses.Last().Key, pj);
                    radiuses.Remove(radiuses.Last().Key);
                }

                Console.WriteLine("Case #" + i + ":");
                writer.Write("Case #" + i + ":");

                for (int j = 0; j < N; j++)
                {
                    writer.Write(points[j].x.ToString(" 0.0"));
                    writer.Write(points[j].y.ToString(" 0.0"));
                }
                writer.WriteLine();
            }

            reader.Dispose();
            writer.Dispose();
        }
    }
}
