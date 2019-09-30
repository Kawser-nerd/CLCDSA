using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2016
{
    class R3C_Rebel_small
    {
        const bool logEnabled = false;
        static string baseFileName = "C-small-attempt0";
        string inputFile = baseFileName + ".in";
        string outputFile = baseFileName + ".out";
        string logFile = baseFileName + ".log";
        StreamReader reader;
        StreamWriter writer;
        StreamWriter logWriter;
        private void Log(string message)
        {
            if (!logEnabled) return;
            logWriter.WriteLine(message);
        }

        class Position
        {
            public int X { get; set; }
            public int Y { get; set; }
            public int Z { get; set; }

            public int Best { get; set; }
            public bool Checked { get; set; }

            public int DistanceSquared (Position other)
            {
                return Square(Math.Abs(X - other.X))
                    + Square(Math.Abs(Y - other.Y))
                    + Square(Math.Abs(Z - other.Z));
            }

            private static int Square(int x)
            {
                return x * x;
            }
        }

        int N, S;
        Position[] P;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            N = int.Parse(line[0]);
            S = int.Parse(line[1]);
            P = new Position[N];
            for (int i=0;i< N;i++)
            {
                line = reader.ReadLine().Split(" ".ToCharArray());
                P[i] = new Position
                {
                    X = int.Parse(line[0]),
                    Y = int.Parse(line[1]),
                    Z = int.Parse(line[2]),
                    Best = int.MaxValue,
                    Checked = false
                };
            }
        }

        private string Solve()
        {
            P[0].Best = 0;
            
            while (P.Any(p => !p.Checked))
            {
                var min = P.Where(p => !p.Checked).Min(p => p.Best);
                var x = P.Where(p => !p.Checked && p.Best == min).First();
                for (int j=0;j< N;j++)
                {
                    var dist = x.DistanceSquared(P[j]);
                    var maxDist = Math.Max(dist, x.Best);
                    if (P[j].Best > maxDist)
                        P[j].Best = maxDist;
                }
                x.Checked = true;
            }

            return Math.Sqrt(P[1].Best).ToString();
        }

        public void Run()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
            if (logEnabled)
                logWriter = new StreamWriter(logFile);
            try
            {
                string s = reader.ReadLine();
                int T = Int32.Parse(s);
                for (int t = 1; t <= T; t++)
                {
                    Log("Start Case #" + t);
                    ReadInput();
                    writer.WriteLine(String.Format("Case #{0}: {1}", t, Solve()));
                    Log("End Case #" + t);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
                if (logEnabled)
                    logWriter.Close();
            }
        }
        static void Main(string[] args)
        {
            new R3C_Rebel_small().Run();
        }
    }
}
