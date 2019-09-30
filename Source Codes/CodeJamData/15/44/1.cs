using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R2D_Drum
    {
        const bool logEnabled = false;
        static string baseFileName = "D-small-attempt2";
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

        private int R { get; set; }
        private int C { get; set; }

        private long[][] table;

        private void ReadInput()
        {
            char[] sep = { ' ' };
            var line = reader.ReadLine().Split(sep);
            R = Int32.Parse(line[0]);
            C = Int32.Parse(line[1]);
        }

        private void Solve()
        {
            /*
             * 0 = '1' + '2'squares; /3
             * 1 = '2' snake around vertical '1'; /4
             * 2 = '2' snake around horizontal '1'; /6
             * 3 = '2' strip; uniform
             * 4 = '3' strip; uniform
             * 5 = '2' strip; /3
             * 6 = '3' strip; /3
             * 7 = '2' strip; /4
             * 8 = '3' strip; /4
             * 9 = '2' strip; /6
             * 10 = '3' strip; /6
             * 11 = '2' strip; /12
             * 12 = '3' strip; /12
             * 13 = '1' + '2'squares; /12
             * 14 = '2' snake around vertical '1'; /12
             * 15 = '2' snake around horizontal '1'; /12
             * 16 = nothing
             * 17 = '1' + '2'squares; /6
             */
            var cmod3 = (C % 3 == 0) ? 3 : 0;
            var cmod4 = (C % 4 == 0) ? 4 : 0;
            var cmod6 = (C % 6 == 0) ? 6 : 0;
            var divisor = new[] { 3, 4, 6, 1, 1, 3, 3, 4, 4, 6, 6, 12, 12, 12, 12, 12, 1, 6 };
            table = new long[20][];
            for (int i = 0; i < table.Length; i++)
            {
                table[i] = new long[4];
                for (int j = 0; j < 4; j++)
                {
                    table[i][j] = 0;
                }
            }
            table[16][0] = 1;

            for (int i = 1; i <= R; i++)
            {
                var d = i % 4;
                var a = (i + 1) % 4;
                var b = (i + 2) % 4;
                var c = (i + 3) % 4;

                table[16][d] = 0;

                table[0][d] = (cmod3 * (table[4][b] + table[6][b] + table[16][b])) % 12000000084;
                table[1][d] = (cmod4 * (table[4][a] + table[8][a] + table[16][a])) % 12000000084;
                table[2][d] = (cmod6 * (table[4][b] + table[6][b] + table[10][b] + table[16][b])) % 12000000084;

                table[17][d] = (cmod3 * (table[10][b])) % 12000000084;

                table[13][d] = (cmod3 * (table[7][b] + table[9][b])) % 12000000084;
                table[14][d] = (cmod4 * (table[5][a] + table[9][a])) % 12000000084;
                table[15][d] = (cmod6 * (table[3][a] + table[7][a] + table[12][a])) % 12000000084;

                table[3][d] = (table[4][c] + table[16][c]) % 12000000084;
                table[4][d] = (table[3][b] + table[16][b]) % 12000000084;
                table[5][d] = table[6][c];
                table[6][d] = (table[5][b] + table[0][b]) % 12000000084;
                table[7][d] = table[8][c];
                table[8][d] = (table[7][b] + table[1][b]) % 12000000084;
                table[9][d] = table[10][c];
                table[10][d] = (table[9][b] + table[2][b] + table[17][b]) % 12000000084;
                table[11][d] = table[12][c];
                table[12][d] = (table[11][b] + table[13][b] + table[14][b] + table[15][b]) % 12000000084;
                if (i == R)
                {
                    long result = 0;
                    for (int j = 0; j < divisor.Length; j++)
                    {
                        result += (table[j][d] / divisor[j]);
                    }
                    result = result % 1000000007;
                    Result = result.ToString();
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
            new R2D_Drum().Run();
        }
    }
}
