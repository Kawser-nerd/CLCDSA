using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Diagnostics;

namespace QuestionD
{
    class Plant
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int R { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string casename = "D-small-attempt2";
            using (StreamReader reader = new StreamReader(casename + ".in"))
            {
                IOStream input = new IOStream(reader);
                using (StreamWriter writer = new StreamWriter(casename + ".out"))
                {
                    int NumCases = input.ReadInt();
                    for (int testcase = 0; testcase != NumCases; ++testcase)
                    {
                        // parse testcase
                        int N = input.ReadInt();
                        List<Plant> plants = new List<Plant>();
                        for (int i = 0; i != N; ++i)
                        {
                            int X = input.ReadInt();
                            int Y = input.ReadInt();
                            int R = input.ReadInt();
                            plants.Add(new Plant { X = X, Y = Y, R = R });
                        }

                        // solve testcase
                        double solution = Solve(plants);

                        // write answer
                        Console.WriteLine("Case #{0}: {1}", testcase + 1, solution);
                        writer.WriteLine("Case #{0}: {1}", testcase + 1, solution);
                    }
                }
            }
        }

        private static double Solve(List<Plant> plants)
        {
            int xrange = plants.Max(p => p.X + p.R) - plants.Min(p => p.X - p.R);
            int yrange = plants.Max(p => p.Y + p.R) - plants.Min(p => p.Y - p.R);
            double rmax = Math.Max(xrange / 2.0, yrange / 2.0);
            double rmin = 0;

            while (rmax - rmin > 1.0e-6)
            {
                double rmiddle = (rmin + rmax) / 2;
                if (CanCover(plants, rmiddle))
                {
                    rmax = rmiddle;
                }
                else
                {
                    rmin = rmiddle;
                }
            }

            return (rmax + rmin) / 2.0;
        }

        private static bool CanCover(List<Plant> plants, double R)
        {
            if (plants.Count == 1)
            {
                return plants[0].R <= R;
            }
            else if (plants.Count == 2)
            {
                return plants[0].R <= R && plants[1].R <= R;
            }
            else
            {
                Debug.Assert(plants.Count <= 3);
                for (int i = 0; i != plants.Count; ++i)
                {
                    for (int j = i + 1; j != plants.Count; ++j)
                    {
                        double rneeded = (Distance(plants[i], plants[j]) + plants[i].R + plants[j].R) / 2;
                        if (R >= rneeded)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        private static double Distance(Plant p, Plant q)
        {
            double X = p.X - q.X;
            double Y = p.Y - q.Y;
            return Math.Sqrt(X * X + Y * Y);
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
}
