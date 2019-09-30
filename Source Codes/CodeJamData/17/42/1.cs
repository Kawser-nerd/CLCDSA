using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R2B_Roller_Coaster_Scheduling
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

        int N, C, M;
        int[] Customers;
        int[] Seats;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            N = int.Parse(line[0]);
            C = int.Parse(line[1]);
            M = int.Parse(line[2]);
            Customers = new int[C+1];
            Seats = new int[N+1];
            for (int i=0;i< M;i++)
            {
                line = reader.ReadLine().Split(" ".ToCharArray());
                Seats[int.Parse(line[0])]++;
                Customers[int.Parse(line[1])]++;
            }
        }

        private string Solve()
        {
            var max = Customers.Max();
            var sum = 0;
            for (int i = 1; i <= N; i++)
            {
                sum += Seats[i];
                max = Math.Max(max, (sum + i - 1) / i);
            }
            var promotions = 0;
            for (int i = 1; i <= N; i++)
            {
                if (Seats[i] > max)
                {
                    promotions += Seats[i] - max;
                }
            }
            return string.Format("{0} {1}", max, promotions);
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
            new R2B_Roller_Coaster_Scheduling().Run();
        }
    }
}
