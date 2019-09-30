using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R0C_Bathroom_Stalls
    {
        const bool logEnabled = false;
        static string baseFileName = "C-large";
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

        long N;
        long K;

        private void ReadInput()
        {
            var line = reader.ReadLine().Split(" ".ToCharArray());
            N = long.Parse(line[0]);
            K = long.Parse(line[1]);
        }

        private string Solve()
        {
            var bigLength = N;
            var bigCount = 1L;
            var smallLength = N;
            var smallCount = 0L;
            var totalCount = 1L;
            while (K > totalCount)
            {
                K -= totalCount;
                var bl = bigLength / 2;
                var sl = (smallLength - 1) / 2;
                var bc = bigCount;
                var sc = smallCount;
                if ((bigLength - 1) / 2 == bl)
                {
                    bc += bigCount;
                }
                else
                {
                    sc += bigCount;
                }
                if ((smallLength) / 2 == bl)
                {
                    bc += smallCount;
                }
                else
                {
                    sc += smallCount;
                }
                bigLength = bl;
                bigCount = bc;
                smallLength = sl;
                smallCount = sc;
                totalCount *= 2;
            }
            var x = (K <= bigCount) ? bigLength : smallLength;
            return string.Format("{0} {1}", x / 2, (x - 1) / 2);
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
            new R0C_Bathroom_Stalls().Run();
        }
    }
}
