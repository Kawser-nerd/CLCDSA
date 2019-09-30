using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Text.RegularExpressions;

namespace Watersheds
{
    class Program
    {
        static StreamReader reader;
        static StreamWriter writer;
        static String alphabet = "abcdefghijklmnopqrstuvwxyz";

        class Point : IComparable<Point>
        {
            public int X;
            public int Y;
            public int H;

            public Point(int x, int y, int h)
            {
                X = x;
                Y = y;
                H = h;
            }

            public int CompareTo(Point p)
            {
                return H - p.H;
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Enter file name: ");
            String fileName = Console.ReadLine();
            reader = new StreamReader(fileName);
            writer = new StreamWriter(fileName.Replace(".in", ".out"));
            int cases = Convert.ToInt32(reader.ReadLine());
            for (int i = 1; i <= cases; i++)
                ProcessCase(i);
            writer.Flush();
            writer.Close();
        }

        static void ProcessCase(int caseNumber)
        {
            String[] numbers = reader.ReadLine().Split(new char[]{' '});
            int height = Convert.ToInt32(numbers[0]);
            int width = Convert.ToInt32(numbers[1]);
            int count = 0;
            int[][] map = new int[height][]; //(Y,X) map
            int[][] labels = new int[height][]; //(Y,X) map
            Point[] cells = new Point[width * height];
            for (int k = 0; k < height; k++)
            {
                map[k] = new int[width];
                labels[k] = new int[width];
                numbers = reader.ReadLine().Split(new char[] { ' ' });
                for (int m = 0; m < width; m++)
                {
                    map[k][m] = Convert.ToInt32(numbers[m]);
                    cells[count] = new Point(m, k, map[k][m]);
                    count++;
                }
            }
            Array.Sort(cells);
            count = 0;
            foreach (Point p in cells)
            {
                Point m = p;
                if (p.Y > 0 && map[p.Y - 1][p.X] < m.H)
                    m = new Point(p.X, p.Y - 1, map[p.Y - 1][p.X]);
                if (p.X > 0 && map[p.Y][p.X - 1] < m.H)
                    m = new Point(p.X - 1, p.Y, map[p.Y][p.X - 1]);
                if (p.X < width - 1 && map[p.Y][p.X + 1] < m.H)
                    m = new Point(p.X + 1, p.Y, map[p.Y][p.X + 1]);
                if (p.Y < height - 1 && map[p.Y + 1][p.X] < m.H)
                    m = new Point(p.X, p.Y + 1, map[p.Y + 1][p.X]);
                if (m == p)
                {
                    labels[p.Y][p.X] = count;
                    count++;
                }
                else
                {
                    labels[p.Y][p.X] = labels[m.Y][m.X];
                }
            }
            count = 0;
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    if (labels[y][x] == count)
                        count++;
                    else if (labels[y][x] > count)
                    {
                        SwapLabels(labels, count, labels[y][x]);
                        count++;
                    }
                }
            }
            writer.WriteLine("Case #{0}:", caseNumber);
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    writer.Write(alphabet[labels[y][x]] + " ");
                }
                writer.WriteLine();
            }
        }

        static void SwapLabels(int[][] labels, int a, int b)
        {
            for (int y = 0; y < labels.Length; y++)
            {
                for (int x = 0; x < labels[y].Length; x++)
                {
                    if (labels[y][x] == a)
                        labels[y][x] = b;
                    else if (labels[y][x] == b)
                        labels[y][x] = a;
                }
            }
        }
    }
}