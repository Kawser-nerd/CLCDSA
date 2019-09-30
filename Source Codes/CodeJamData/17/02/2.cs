using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2017
{
    class R0B_Tidy_Numbers
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

        string N;

        private void ReadInput()
        {
            N = reader.ReadLine();
        }

        private string Solve()
        {
            var sb = new StringBuilder();
            var pivot = 0;
            for (int i=1;i<N.Length;i++)
            {
                if (N[i] > N[i-1])
                {
                    sb.Append(N.Substring(pivot, i - pivot));
                    pivot = i;
                }
                else if (N[i] < N[i-1])
                {
                    sb.Append((char)(N[pivot] - 1));
                    for (int j=pivot+1;j<N.Length;j++)
                    {
                        sb.Append('9');
                    }
                    return sb.ToString().TrimStart("0".ToCharArray());
                }
            }
            sb.Append(N.Substring(pivot, N.Length - pivot));
            return sb.ToString();
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
            new R0B_Tidy_Numbers().Run();
        }
    }
}
