using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    struct Thing
    {
        public long Count;
        public long Type;
    }

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

        private void Go()
        {
            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                int numBoxes = m_io.ReadInt();
                int numToys = m_io.ReadInt();
                var boxes = Enumerable.Range(0, numBoxes).Select(i => new Thing { Count = m_io.ReadLong(), Type = m_io.ReadLong() }).ToArray();
                var toys = Enumerable.Range(0, numToys).Select(i => new Thing { Count = m_io.ReadLong(), Type = m_io.ReadLong() }).ToArray();



                m_io.WriteCase(Solve(0,0,boxes,toys,0));
            }
        }

        private long Solve(int boxPos, int toyPos, Thing[] boxes, Thing[] toys, long matchedSoFar)
        {
            if (toyPos >= toys.Length || boxPos >= boxes.Length)
                return matchedSoFar;

            if(boxes[boxPos].Count == 0)
                return Solve(boxPos+1,toyPos,boxes,toys,matchedSoFar);

            if(toys[toyPos].Count == 0)
                return Solve(boxPos,toyPos+1,boxes,toys,matchedSoFar);

            long max = 0;
            //Make if we can
            if (boxes[boxPos].Type == toys[toyPos].Type)
            {
                long canMake = Math.Min(boxes[boxPos].Count, toys[toyPos].Count);
                matchedSoFar += canMake;
                boxes[boxPos].Count -= canMake;
                toys[toyPos].Count -= canMake;

                max = Solve(boxPos, toyPos, boxes, toys, matchedSoFar);

                boxes[boxPos].Count += canMake;
                toys[toyPos].Count += canMake;
            }
            else //not sure if this is a good idea
            {
                //Throw out boxes
                max = Math.Max(max, Solve(boxPos + 1, toyPos, boxes, toys, matchedSoFar));
                //Throw out toys
                max = Math.Max(max, Solve(boxPos,toyPos+1,boxes,toys,matchedSoFar));
            }

            return max;
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
