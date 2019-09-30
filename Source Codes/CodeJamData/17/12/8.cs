using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R1AB_Ratatouille
    {
        const bool logEnabled = false;
        static string baseFileName = "B-large";
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

        private class Position
        {
            public int I { get; set; }
            public int J { get; set; }
            public Position (int i, int j)
            {
                I = i;
                J = j;
            }
        }

        int N, P;
        int[] Recipe;
        List<int>[] Quantities;
        List<int[]>[] Servings;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            N = int.Parse(line[0]);
            P = int.Parse(line[1]);
            Quantities = new List<int>[N];
            Servings = new List<int[]>[N];
            Recipe = reader.ReadLine().Split(" ".ToCharArray()).Select(t => int.Parse(t)).ToArray();
            for (int i = 0; i < N; i++)
            {
                Quantities[i] = reader.ReadLine().Split(" ".ToCharArray()).Select(t => int.Parse(t)).ToList();
                Quantities[i].Sort();
                Servings[i] = new List<int[]>();
                for (int j=0;j<Quantities[i].Count;j++)
                {
                    Servings[i].Add(new[] { MinServings(i, Quantities[i][j]), MaxServings(i, Quantities[i][j]) });
                }
            }
        }

        private int MinServings(int ingr, int q)
        {
            return (q * 10 + (Recipe[ingr] * 11 - 1)) / (Recipe[ingr] * 11);
        }

        private int MaxServings(int ingr, int q)
        {
            return (q * 10) / (Recipe[ingr] * 9);
        }

        int[] ix;
        int result;

        private bool Solve(int ingr, int minServ, int maxServ)
        {
            if (minServ > maxServ) return false;
            if (ingr == N)
            {
                result++;
                return true;
            }
            while ((ix[ingr] < P) && (Servings[ingr][ix[ingr]][1] < minServ)) ix[ingr]++;
            if (ix[ingr] >= P) return false;
            if (Solve(ingr + 1, Math.Max(minServ, Servings[ingr][ix[ingr]][0]), Math.Min(maxServ, Servings[ingr][ix[ingr]][1])))
            {
                ix[ingr]++;
                return true;
            }
            else {
                if (ingr == 0)
                {
                    ix[ingr]++;
                }
                return false;
            }
        }

        private string Solve()
        {
            result = 0;
            ix = new int[N];
            while (ix[0] < P) Solve(0, 1, int.MaxValue);
            return result.ToString();
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
            new R1AB_Ratatouille().Run();
        }
    }
}
