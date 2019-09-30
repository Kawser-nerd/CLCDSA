using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
using E = System.Linq.Enumerable;

namespace ProbC {
    class Program {
        protected IOHelper io;

        BigInteger in_base(int []x,int b){
            BigInteger ans = 0;
            for (int i = 0; i < x.Length; i++) ans = ans * b + x[i];
            return ans;
        }

        readonly int[] checklist = { 2, 3, 5, 7, 11, 13, 17, 19 };

        int[] check(int []x) {
            int[] ans = new int[9];
            for (int i = 2; i <= 10; i++) {
                BigInteger val = in_base(x, i);
                bool flag = false;
                for (int j = 0; j < checklist.Length && !flag; ++j) {
                    if (val % checklist[j] == 0) {
                        ans[i - 2] = checklist[j];
                        flag = true;
                    }
                }
                if (!flag) return null;
            }
            return ans;
        }

        public Program(string inputFile, string outputFile) {
            io = new IOHelper(inputFile, outputFile, Encoding.Default);
            int T = io.NextInt();
            int n = io.NextInt(), m = io.NextInt();
            io.WriteLine("Case #1:");
            int[] inbin = new int[n];
            inbin[0] = inbin[n - 1] = 1;

            int cnt = 0;
            for (long i = (long)in_base(inbin, 2);cnt<m ; i += 2) {
                long x = i;
                for (int j = n - 1; j >= 0; j--) {
                    inbin[j] = (int)(x & 1);
                    x >>= 1;
                }
                int[] res = check(inbin);
                if (res != null) {
                    ++cnt;
                    for (int j = 0; j < n; j++) io.Write(inbin[j]);
                    for (int j = 0; j < 9; j++) io.Write(" " + res[j]);
                    io.WriteLine("");
                }
            }

            io.Dispose();
        }

        static void Main(string[] args) {
            Program myProgram = new Program(@"F:\noipacm\商业比赛\2016gcj\qualification\C-large.in",
                                            @"F:\noipacm\商业比赛\2016gcj\qualification\clarge.txt");
        }
    }

    class IOHelper : IDisposable {
        public StreamReader reader;
        public StreamWriter writer;

        public IOHelper(string inputFile, string outputFile, Encoding encoding) {
            if (inputFile == null)
                reader = new StreamReader(Console.OpenStandardInput(), encoding);
            else
                reader = new StreamReader(inputFile, encoding);

            if (outputFile == null)
                writer = new StreamWriter(Console.OpenStandardOutput(), encoding);
            else
                writer = new StreamWriter(outputFile, false, encoding);

            curLine = new string[] { };
            curTokenIdx = 0;
        }

        string[] curLine;
        int curTokenIdx;

        char[] whiteSpaces = new char[] { ' ', '\t', '\r', '\n' };

        public bool hasNext() {
            if (curTokenIdx >= curLine.Length) {
                //Read next line
                string line = reader.ReadLine();
                if (line != null)
                    curLine = line.Split(whiteSpaces, StringSplitOptions.RemoveEmptyEntries);
                else
                    curLine = new string[] { };
                curTokenIdx = 0;
            }

            return curTokenIdx < curLine.Length;
        }

        public string NextToken() {
            return hasNext() ? curLine[curTokenIdx++] : null;
        }

        public int NextInt() {
            return int.Parse(NextToken());
        }

        public double NextDouble() {
            string tkn = NextToken();
            return double.Parse(tkn, System.Globalization.CultureInfo.InvariantCulture);
        }

        public void Write(double val, int precision) {
            writer.Write(val.ToString("F" + precision, System.Globalization.CultureInfo.InvariantCulture));
        }

        public void Write(object stringToWrite) {
            writer.Write(stringToWrite);
        }

        public void WriteLine(double val, int precision) {
            writer.WriteLine(val.ToString("F" + precision, System.Globalization.CultureInfo.InvariantCulture));
        }

        public void WriteLine(object stringToWrite) {
            writer.WriteLine(stringToWrite);
        }

        public void Dispose() {
            try {
                if (reader != null) {
                    reader.Dispose();
                }
                if (writer != null) {
                    writer.Flush();
                    writer.Dispose();
                }
            } catch { };
        }


        public void Flush() {
            if (writer != null) {
                writer.Flush();
            }
        }
    }
}
