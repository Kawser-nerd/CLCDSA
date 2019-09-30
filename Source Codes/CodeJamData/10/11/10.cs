using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Collections;

namespace QuestionA
{
    enum Contents
    {
        Red,
        Blue,
        Empty,
        Both
    }
    class Program
    {
        static void Main(string[] args)
        {
            string casename = "A-large";
            using (StreamReader reader = new StreamReader(casename + ".in"))
            {
                IOStream input = new IOStream(reader);
                using (var writer = new StreamWriter(casename + ".out"))
                {
                    int T = input.ReadInt();
                    for (int t = 0; t != T; ++t)
                    {
                        // parse test case
                        int N = input.ReadInt();
                        int K = input.ReadInt();
                        var grid = new Grid<Contents>(N, N, Contents.Empty);
                        for (int n = 0; n != N; ++n)
                        {
                            string line = input.ReadString();
                            for (int i = 0; i != N; ++i)
                            {
                                if (line[i] == 'R')
                                {
                                    grid[n, i] = Contents.Red;
                                }
                                else if (line[i] == 'B')
                                {
                                    grid[n, i] = Contents.Blue;
                                }
                            }
                        
                        }

                        // solve
                        var solution = Solve(grid, K);

                        switch (solution)
                        {
                            case Contents.Red: writer.WriteLine("Case #{0}: Red", t + 1); break;
                            case Contents.Blue: writer.WriteLine("Case #{0}: Blue", t + 1); break;
                            case Contents.Empty: writer.WriteLine("Case #{0}: Neither", t + 1); break;
                            case Contents.Both: writer.WriteLine("Case #{0}: Both", t + 1); break;
                        }
                    }
                }
            }
        }

        private static void Compact(Grid<Contents> grid, int row)
        {
            int empty = grid.Width;
            for (int x = grid.Width - 1; x >= 0; --x)
            {
                if (grid[row, x] == Contents.Empty)
                {
                    empty = x;
                    break;
                }
            }
            if (empty != grid.Width)
            {
                for (int x = empty - 1; x >= 0; --x)
                {
                    if (grid[row, x] != Contents.Empty)
                    {
                        grid[row, empty] = grid[row, x];
                        grid[row, x] = Contents.Empty;
                        --empty;
                    }
                }
            }
        }

        private static Contents Solve(Grid<Contents> grid, int K)
        {
            for (int n = 0; n != grid.Height; ++n)
            {
                Compact(grid, n);
            }

            bool redRun = false;
            bool blueRun = false;
            // horizontal runs
            for (int i = 0; i != grid.Height; ++i)
            {
                int redRunLength = 0;
                int blueRunLength = 0;
                for (int j = 0; j != grid.Width; ++j)
                {
                    if (grid[i, j] == Contents.Red)
                        ++redRunLength;
                    else
                        redRunLength = 0;
                    if (grid[i, j] == Contents.Blue)
                        ++blueRunLength;
                    else
                        blueRunLength = 0;

                    if (redRunLength >= K)
                        redRun = true;
                    if (blueRunLength >= K)
                        blueRun = true;
                }
            }
            
            // vertical
            for (int i = 0; i != grid.Height; ++i)
            {
                int redRunLength = 0;
                int blueRunLength = 0;
                for (int j = 0; j != grid.Width; ++j)
                {
                    if (grid[j, i] == Contents.Red)
                        ++redRunLength;
                    else
                        redRunLength = 0;
                    if (grid[j, i] == Contents.Blue)
                        ++blueRunLength;
                    else
                        blueRunLength = 0;

                    if (redRunLength >= K)
                        redRun = true;
                    if (blueRunLength >= K)
                        blueRun = true;
                }
            }
            
            // diagonal one way
            for (int i = -grid.Height; i != grid.Height; ++i)
            {
                int redRunLength = 0;
                int blueRunLength = 0;
                for (int j = 0; j != grid.Width; ++j)
                {
                    int a = j;
                    int b = i + j;
                    if (b < 0 || b >= grid.Width) continue;
                    if (grid[a, b] == Contents.Red)
                        ++redRunLength;
                    else
                        redRunLength = 0;
                    if (grid[a, b] == Contents.Blue)
                        ++blueRunLength;
                    else
                        blueRunLength = 0;

                    if (redRunLength >= K)
                        redRun = true;
                    if (blueRunLength >= K)
                        blueRun = true;
                }
            }

            // diagonal other way
            for (int i = 0; i != grid.Height * 2; ++i)
            {
                int redRunLength = 0;
                int blueRunLength = 0;
                for (int j = 0; j != grid.Width; ++j)
                {
                    int a = j;
                    int b = i - j;
                    if (b < 0 || b >= grid.Width) continue;
                    if (grid[a, b] == Contents.Red)
                        ++redRunLength;
                    else
                        redRunLength = 0;
                    if (grid[a, b] == Contents.Blue)
                        ++blueRunLength;
                    else
                        blueRunLength = 0;

                    if (redRunLength >= K)
                        redRun = true;
                    if (blueRunLength >= K)
                        blueRun = true;
                }
            }

            if (blueRun && redRun) return Contents.Both;
            else if (blueRun) return Contents.Blue;
            else if (redRun) return Contents.Red;
            else return Contents.Empty;
        }
    }

    class IOStream
    {
        public IOStream(StreamReader reader)
        {
            this.reader = reader;
        }

        public int ReadInt()
        {
            return int.Parse(ReadString());
        }

        public long ReadLong()
        {
            return long.Parse(ReadString());
        }

        public string ReadString()
        {
            if (parts == null || partNum >= parts.Length)
            {
                ReadMore();
            }
            string rtn = parts[partNum];
            ++partNum;
            return rtn;
        }

        private void ReadMore()
        {
            parts = reader.ReadLine().Split(' ');
            partNum = 0;
        }

        StreamReader reader;
        string[] parts;
        int partNum;
    }
    class Square
    {
        public Square(int x, int y)
        {
            X = x;
            Y = y;
        }

        public int X { get; set; }
        public int Y { get; set; }

        public IEnumerable<Square> Adjacent(int w, int h)
        {
            // north, west, east, south
            if (Y > 0) yield return new Square(X, Y - 1);
            if (X > 0) yield return new Square(X - 1, Y);
            if (X + 1 < w) yield return new Square(X + 1, Y);
            if (Y + 1 < h) yield return new Square(X, Y + 1);
        }
    }

    class Grid<T>
    {
        public Grid(int w, int h, T initial)
        {
            width = w;
            height = h;
            data = new List<T>();
            for (int i = 0; i != w * h; ++i)
            {
                data.Add(initial);
            }
        }

        public T this[Square s]
        {
            get { return data[s.X + s.Y * width]; }
            set { data[s.X + s.Y * width] = value; }
        }

        public T this[int x, int y]
        {
            get { return data[x + y * width]; }
            set { data[x + y * width] = value; }
        }

        public int Width { get { return width; } }
        public int Height { get { return height; } }
        int width;
        int height;
        List<T> data;
    }
}
