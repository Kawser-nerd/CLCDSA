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
        const string IN_FILE = @"A-small-attempt0.in";
        const string OUT_FILE = @"out.txt";

        private void SolveOneTestCase()
        {
            int k = In.NextInt();
            int[,] a = new int[k, k];
            for (int i = 0; i < 2 * k - 1; ++i)
            {
                int cnt = i < k ? i + 1 : 2 * k - i - 1;
                for (int j = 0; j < cnt; ++j)
                {
                    if (i < k)
                        a[i - j, j] = In.NextInt();
                    else
                        a[k - j - 1, j + i - k + 1] = In.NextInt();
                }
            }
            for (int sz = k; sz <= 3 * k; ++sz)
            {
                bool ex = false;
                for (int i = 0; i + k - 1 < sz; ++i)
                    for (int j = 0; j + k - 1 < sz; ++j)
                    {
                        int[,] b = new int[sz, sz];
                        for (int ii = 0; ii < sz; ++ii)
                            for (int jj = 0; jj < sz; ++jj)
                                b[ii, jj] = -1;
                        for (int ii = 0; ii < k; ++ii)
                            for (int jj = 0; jj < k; ++jj)
                                b[i + ii, j + jj] = a[ii, jj];
                        bool ok = true;
                        for (int ii = 0; ii < sz; ++ii)
                        {
                            for (int jj = 0; jj < sz; ++jj)
                            {
                                if (b[ii, jj] == -1) continue;

                                if (b[jj, ii] == -1) b[jj, ii] = b[ii, jj];
                                else if (b[ii, jj] != b[jj, ii]) { ok = false; break; }

                                if (b[sz - jj - 1, sz - ii - 1] == -1) b[sz - jj - 1, sz - ii - 1] = b[ii, jj];
                                else if (b[ii, jj] != b[sz - jj - 1, sz - ii - 1]) { ok = false; break; }
                            }
                            if (!ok) break;
                        }
                        if (ok)
                        {
                            ex = true;
                            break;
                        }
                    }
                if (ex)
                {
                    Out.WriteLine(sz * sz - k * k);
                    break;
                }
            }
        }

        #region Local wireup

        public const string PROBLEM_ALIAS = "a";

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
