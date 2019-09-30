using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

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

        private static readonly char[] c_baseElements = "QWERASDF".Select(c => c).ToArray();

        private void Go()
        {
            Dictionary<char, int> emptyTally = c_baseElements.ToDictionary(e => e, e => 0);

            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                int C = m_io.ReadInt();
                Dictionary<string, char> combiners = new Dictionary<string, char>(C * 2);
                for (int c = 0; c < C; c++)
                {
                    string com = m_io.ReadWord();
                    combiners.Add(com.Substring(0, 2), com[2]);
                    if (com[1] != com[0])
                        combiners.Add(com[1].ToString() + com[0].ToString(), com[2]);
                }

                int D = m_io.ReadInt();
                HashSet<string> oposers = new HashSet<string>();
                for (int d = 0; d < D; d++)
                {
                    string opp = m_io.ReadWord();
                    oposers.Add(opp[0].ToString() + opp[1]);
                    oposers.Add(opp[1].ToString() + opp[0]);
                }

                int N = m_io.ReadInt();
                string seq = m_io.ReadWord();
                Dictionary<char, int> tally = new Dictionary<char,int>(emptyTally);
                List<char> state = new List<char>(seq.Length);
                char last = '?';
                foreach (char next in seq)
                {
                    char toAdd = next;
                    char combined;
                    if (combiners.TryGetValue(last.ToString() + next, out combined))
                    {
                        toAdd = combined;
                    }

                    bool flush = false;
                    string toAddStr = toAdd.ToString();
                    foreach (string curact in tally.Where(kvp => kvp.Value > 0).Select(kvp => kvp.Key + toAddStr))
                    {
                        if (oposers.Contains(curact))
                        {
                            flush = true;
                            break;
                        }
                    }

                    if (flush)
                    {
                        tally = new Dictionary<char, int>(emptyTally);
                        state.Clear();
                        last = '?';
                    }
                    else
                    {
                        if (toAdd == next)
                        {
                            tally[toAdd]++;
                            state.Add(toAdd);
                        }
                        else
                        {
                            tally[last]--;
                            state[state.Count - 1] = toAdd;
                        }
                        last = toAdd;
                    }
                }


                m_io.WriteCase("[" + String.Join(", ", state) + "]");
            }
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
            m_writer.WriteLine("Case #{0}: {1}", m_case, result);
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
