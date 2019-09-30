using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R1AB_Haircut
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

        private string Result { get; set; }

        private int B { get; set; }
        private int N { get; set; }
        private List<int> Barbers { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var line = reader.ReadLine().Split(sep);
            B = Int32.Parse(line[0]);
            N = Int32.Parse(line[1]);

            line = reader.ReadLine().Split(sep);
            Barbers = new List<int>();
            foreach (var token in line)
            {
                Barbers.Add(Int32.Parse(token));
            }
        }

        private long Served(long time)
        {
            long result = 0;
            foreach (var barber in Barbers)
            {
                result += ((time + barber - 1) / barber);
            }
            return result;
        }

        private void Solve()
        {
            long lower = 0;
            long upper = 1;
            long lowerNum = Served(lower);
            long upperNum = Served(upper);

            while (upperNum < N)
            {
                upper *= 2;
                upperNum = Served(upper);
            }

            while (upperNum - lowerNum > 2 * B)
            {
                long mid = (lower + upper) / 2;
                long midNum = Served(mid);
                if (midNum < N)
                {
                    lower = mid;
                    lowerNum = midNum;
                }
                else
                {
                    upper = mid;
                    upperNum = midNum;
                }
            }

            long served = 0;
            var timeLeft = new long[Barbers.Count];
            for (int i = 0; i < Barbers.Count; i++)
            {
                served += (lower / Barbers[i]);
                timeLeft[i] = -(lower % Barbers[i]);
            }

            while (served < N)
            {
                int minIndex = 0;
                for (int i = 0; i < timeLeft.Length; i++)
                {
                    if (timeLeft[i] < timeLeft[minIndex])
                    {
                        minIndex = i;
                    }
                }
                timeLeft[minIndex] += Barbers[minIndex];
                if (++served == N)
                {
                    Result = (minIndex + 1).ToString();
                }
            }
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
                    Solve();
                    writer.WriteLine(String.Format("Case #{0}: {1}", t, Result));
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
            new R1AB_Haircut().Run();
        }
    }
}
