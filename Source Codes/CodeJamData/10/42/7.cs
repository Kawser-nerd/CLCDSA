using System;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Web;
using System.Text.RegularExpressions;
using System.Numerics;

namespace gcj
{
    class Program
    {
        const string IN_FILE = @"B-large.in";
        const string OUT_FILE = @"out.txt";

        long[] m;

        const long INF = 1000000000000000L;
        int sz, p;
        long[,] dp;
        bool[,] was;

        long go(int u, int skip, int level)
        {
            if (was[u, skip]) return dp[u, skip];
            int l = 2 * u + 1, r = 2 * u + 2;
            was[u, skip] = true;
            if (level == p)
            {
                if (skip > m[u]) return dp[u, skip] = INF;
                else return dp[u, skip] = 0;
            }
            else
            {
                return dp[u, skip] = Math.Min(m[u] + go(l, skip, level + 1) + go(r, skip, level + 1), go(l, skip + 1, level + 1) + go(r, skip + 1, level + 1));
            }
        }

        private void SolveOneTestCase()
        {
            p = In.NextInt();
            dp = new long[1 << (p + 1), p + 1];
            was = new bool[1 << (p + 1), p + 1];
            m = new long[1 << (p + 1)];
            sz = 1 << (p + 1);
            for (int i = p; i >= 0; --i)
            {
                int shift = (1 << i) - 1;
                for (int j = 0; j < (1 << i); ++j)
                {
                    m[j + shift] = In.NextInt();
                }
            }
            Out.WriteLine(go(0, 0, 0));
        }

        #region Local wireup

        public const string PROBLEM_ALIAS = "b";

        private void Solve()
        {
            var path = Path.Combine(Path.Combine(Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location), @"..\..\..\gcj\solutions\" + PROBLEM_ALIAS), OUT_FILE);
            if (File.Exists(path)) File.Delete(path);
            int tests = In.NextInt();
            for (int i = 0; i < tests; ++i)
            {
                using (Out = new StreamWriter(path, true))
                {
                    Out.Write(string.Format("Case #{0}: ", i + 1));
                    var timer = new Stopwatch();
                    timer.Start();
                    SolveOneTestCase();
                    Console.WriteLine(string.Format("Done test {1} in {0} seconds.", timer.ElapsedMilliseconds / 1000.0, i + 1));
                }
            }
        }

        Scanner In = new Scanner();
        TextWriter Out;

        void Start()
        {
            var timer = new Stopwatch();
            timer.Start();
            System.Threading.Thread t = new System.Threading.Thread(Solve, 20000000);
            t.Start();
            t.Join();
            timer.Stop();
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine(string.Format("Done all tests in {0} seconds.\nPress <Enter> to exit.", timer.ElapsedMilliseconds / 1000.0));
            Console.ReadLine();
        }

        static void Main(string[] args)
        {
            new Program().Start();
        }

        class Scanner : IDisposable
        {
            #region Fields

            TextReader _reader;
            int _bufferSize;
            bool _closeReader;
            char[] _buffer;
            int _length, _pos;

            #endregion

            #region .ctors

            public Scanner(TextReader reader, int bufferSize, bool closeReader)
            {
                _reader = reader;
                _bufferSize = bufferSize;
                _closeReader = closeReader;
                _buffer = new char[_bufferSize];
                FillBuffer(false);
            }

            public Scanner(TextReader reader, bool closeReader) : this(reader, 1 << 16, closeReader) { }

            public Scanner(string fileName) : this(new StreamReader(fileName, Encoding.Default), true) { }

            public Scanner()
                : this(
                    Path.Combine(Path.Combine(Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location), @"..\..\..\gcj\solutions\" + PROBLEM_ALIAS), IN_FILE)) { }


            #endregion

            #region IDisposable Members

            public void Dispose()
            {
                if (_closeReader)
                {
                    _reader.Close();
                }
            }

            #endregion

            #region Properties

            public bool Eof
            {
                get
                {
                    if (_pos < _length) return false;
                    FillBuffer(false);
                    return _pos >= _length;
                }
            }

            #endregion

            #region Methods

            public char NextChar()
            {
                if (_pos < _length) return _buffer[_pos++];
                FillBuffer(true);
                return _buffer[_pos++];
            }

            public char PeekNextChar()
            {
                if (_pos < _length) return _buffer[_pos];
                FillBuffer(true);
                return _buffer[_pos];
            }

            private void FillBuffer(bool throwOnEof)
            {
                _length = _reader.Read(_buffer, 0, _bufferSize);
                if (throwOnEof && Eof)
                {
                    throw new IOException("Can't read beyond the end of file");
                }
                _pos = 0;
            }

            public int NextInt()
            {
                bool neg = false;
                int res = 0;
                SkipWhitespaces();
                if (!Eof && PeekNextChar() == '-')
                {
                    neg = true;
                    _pos++;
                }
                while (!Eof && !IsWhitespace(PeekNextChar()))
                {
                    var c = NextChar();
                    if (c < '0' || c > '9') throw new ArgumentException("Illegal character");
                    res = 10 * res + c - '0';
                }
                return neg ? -res : res;
            }

            public long NextLong()
            {
                bool neg = false;
                long res = 0;
                SkipWhitespaces();
                if (!Eof && PeekNextChar() == '-')
                {
                    neg = true;
                    _pos++;
                }
                while (!Eof && !IsWhitespace(PeekNextChar()))
                {
                    var c = NextChar();
                    if (c < '0' || c > '9') throw new ArgumentException("Illegal character");
                    res = (long)10 * res + c - '0';
                }
                return neg ? -res : res;
            }

            public string NextLine()
            {
                SkipUntilNextLine();
                if (Eof) return "";
                var builder = new StringBuilder();
                while (!Eof && !IsEndOfLine(PeekNextChar()))
                {
                    builder.Append(NextChar());
                }
                return builder.ToString();
            }

            public double NextDouble()
            {
                SkipWhitespaces();
                var builder = new StringBuilder();
                while (!Eof && !IsWhitespace(PeekNextChar()))
                {
                    builder.Append(NextChar());
                }
                return double.Parse(builder.ToString(), CultureInfo.InvariantCulture);
            }

            private void SkipWhitespaces()
            {
                while (!Eof && IsWhitespace(PeekNextChar()))
                {
                    ++_pos;
                }
            }

            private void SkipUntilNextLine()
            {
                while (!Eof && IsEndOfLine(PeekNextChar()))
                {
                    ++_pos;
                }
            }

            private bool IsWhitespace(char c)
            {
                return c == ' ' || c == '\t' || c == '\n' || c == '\r';
            }

            private bool IsEndOfLine(char c)
            {
                return c == '\n' || c == '\r';
            }

            #endregion
        }

        #endregion
    }
}
