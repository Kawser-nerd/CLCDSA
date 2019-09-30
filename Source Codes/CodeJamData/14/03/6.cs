using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (CodeJamIO io = new CodeJamIO("in.txt", "out.txt"))
            {
                Program p = new Program(io); ;
                p.Go();
            }
        }

        private CodeJamIO m_io = null;
        public Program(CodeJamIO io)
        {
            m_io = io;
        }

        private static readonly string Impossible = Environment.NewLine + "Impossible";

        private void Go()
        {
            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                int R = m_io.ReadInt();
                int C = m_io.ReadInt();
                int M = m_io.ReadInt();

                int narrowestSide = Math.Min(R, C);
                int safeSpaces = (R * C - M);

                if (safeSpaces == 1)
                {
                    WriteSimpleSolution(R, C, M, 1);
                }
                else if (narrowestSide == 1)
                {
                    WriteSimpleSolution(R, C, M, C);
                }
                else if (narrowestSide == 2)
                {
                    if (safeSpaces % 2 == 1 || safeSpaces < 4)
                        WriteImpossible(R, C, M);
                    else
                        WriteSimpleSolution(R, C, M, Math.Min(C, safeSpaces / 2));
                }
                else
                {
                    if (safeSpaces < 4 || safeSpaces == 7 || safeSpaces == 5)
                        WriteImpossible(R, C, M);
                    else
                    {
                        var solution = LSolver(R, C, M);
                        WriteLSolution(R, C, M, solution);
                    }
                }
            }
        }

        private int[] LSolver(int R, int C, int M)
        {
            int[] result = new int[R];
            int safeSpaces = (R * C - M);
            var right = 2;
            var down = 2;
            var total = right * 2 + down * 2 - 4;
            bool shouldRight = true;

            while(total + 2 <= safeSpaces && (right < C || down < R))
            {
                if (down == R || (shouldRight && right < C))
                {
                    right++;
                }
                else
                {
                    down++;
                }
                total += 2;
                shouldRight = !shouldRight;
            }

            for (int i = 0; i < 2; i++)
                result[i] = right;
            for (int i = 2; i < down; i++)
                result[i] = 2;

            for (int row = 2; row < R && total < safeSpaces; row++)
            {
                for (int col = 2; col < C && total < safeSpaces; col++)
                {
                    result[row]++;
                    total++;
                }
            }

            return result;
        }

        private int GetNonMineWidth(int R, int C, int M)
        {
            int nonMineSpaces = (R * C - M);
            int nonMineCols = C;
            while(nonMineSpaces / nonMineCols < 2 || nonMineSpaces % nonMineCols == 1)
            {
                --nonMineCols;
                if(nonMineCols == 1 || (nonMineSpaces / nonMineCols + (nonMineSpaces % nonMineCols == 0 ? 0 : 1) > R))
                    return -1;
            }
            return nonMineCols;
        }

        private void WriteImpossible(int R, int C, int M)
        {
            m_io.WriteCase(Impossible);
            //Console.WriteLine("{0}, {1}, {2} ({3})", R, C, M, R*C-M);
            //for (int r = 0; r < R; r++)
            //{
            //    for (int c = 0; c < C; c++)
            //    {
            //        Console.Write('*');
            //    }
            //    Console.WriteLine();
            //}
        }

        private void WriteLSolution(int R, int C, int M, int[] lSolution)
        {

            StringBuilder sb = new StringBuilder(R * (C + 3));
            for (int r = 0; r < R; r++)
            {
                sb.AppendLine();
                for (int c = 0; c < C; c++)
                {
                    if (r == 0 && c == 0)
                    {
                        sb.Append('c');
                    }
                    else if (lSolution[r] > c)
                    {
                        sb.Append('.');
                    }
                    else
                    {
                        sb.Append('*');
                    }
                }
            }
            m_io.WriteCase(sb.ToString());
        }

        private void WriteSimpleSolution(int R, int C, int M, int nonMineCols)
        {
            int nonMineSpaces = (R * C - M);
            StringBuilder sb = new StringBuilder(R*(C+3));
            for (int r = 0; r < R; r++)
            {
                sb.AppendLine();
                for (int c = 0; c < C; c++)
                {
                    if (r == 0 && c == 0)
                    {
                        sb.Append('c');
                        --nonMineSpaces;
                    }
                    else if (nonMineSpaces > 0 && c < nonMineCols)
                    {
                        sb.Append('.');
                        --nonMineSpaces;
                    }
                    else
                    {
                        sb.Append('*');
                    }
                }
            }
            m_io.WriteCase(sb.ToString());
        }
    }

    #region IO Class

    class CodeJamIO : IDisposable
    {
        private int m_case = 0;
        private string m_currentLine;
        private StreamReader m_reader;
        private StreamWriter m_writer;

        public CodeJamIO(string infile, string outfile)
        {
            m_reader = new StreamReader(infile);
            m_writer = new StreamWriter(outfile);
        }

        public void WriteCase(string result)
        {
            ++m_case;
            m_writer.WriteLine("Case #{0}:{1}", m_case, result);
        }
        public void WriteCase(long result)
        {
            WriteCase(result.ToString());
        }
        public void WriteCase(int result)
        {
            WriteCase(result.ToString());
        }

        public long ReadLong()
        {
            return long.Parse(ReadWord());
        }

        public int ReadInt()
        {
            return int.Parse(ReadWord());
        }

        public string ReadLine()
        {
            if (String.IsNullOrWhiteSpace(m_currentLine))
            {
                m_currentLine = m_reader.ReadLine();
                if (m_currentLine == null)
                    throw new Exception("end of file");
            }
            string ret = m_currentLine;
            m_currentLine = null;
            return ret;
        }

        private static char[] whitespace = new char[] { ' ', '\t', '\n', '\r' };

        public string ReadWord()
        {

            string ret;
            int i;
            for (i = 0; string.IsNullOrWhiteSpace(m_currentLine) && i < 1000; i++)
            {
                m_currentLine = m_reader.ReadLine();
            }
            if (i >= 1000)
                throw new Exception("Too many bad reads");
            m_currentLine = m_currentLine.TrimStart(whitespace);
            int positionOfNextSpace = m_currentLine.IndexOfAny(whitespace);
            if (positionOfNextSpace < 0)
            {
                ret = m_currentLine;
                m_currentLine = null;

            }
            else
            {
                ret = m_currentLine.Substring(0, positionOfNextSpace);
                m_currentLine = m_currentLine.Substring(positionOfNextSpace);
            }

            return ret;
        }

        private bool m_disposed = false;
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            // Check to see if Dispose has already been called.
            if (!m_disposed)
            {
                // If disposing equals true, dispose all managed
                // and unmanaged resources.
                if (disposing)
                {
                    // Dispose managed resources.
                    m_writer.Flush();
                    m_writer.Close();
                    m_writer.Dispose();
                }

                m_disposed = true;
            }
        }
    }
    #endregion IO Class
}