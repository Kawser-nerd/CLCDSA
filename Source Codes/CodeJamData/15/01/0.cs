using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R0A_StandingOvation
    {
        const bool logEnabled = false;
        static string baseFileName = "A-large";
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
        private int S { get; set; }
        private char[] Audience { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var row = reader.ReadLine().Split(sep);

            S = Int32.Parse(row[0]);
            Audience = row[1].ToCharArray();
        }

        private void Solve()
        {
            var invites = 0;
            var standing = 0;
            for (int i = 0; i <= S; i++)
            {
                if (standing < i)
                {
                    invites += (i - standing);
                    standing = i;
                }
                standing += (Audience[i] - '0');
            }
            Result = invites.ToString();
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
            new R0A_StandingOvation().Run();
        }
    }
}
