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
        const int MOD = 100003;

        const string IN_FILE = @"C-large.in";
        const string OUT_FILE = @"out.txt";

        int[,] dp;
        bool[,] was;
        long[,] C;

        int go(int len, int max)
        {
            if (was[len, max]) return dp[len, max];
            int res = 0;

            if (len > 1)
            {
                for (int p = 1; p < len; ++p)
                {
                    int need = len - p - 1;
                    if (max - len - 1 >= need)
                    {
                        long tmp = go(p, len);
                        tmp *= C[max - len - 1, need];
                        tmp %= MOD;
                        res += (int)tmp;
                    }
                }
            }
            else res = 1;

            was[len, max] = true;
            return dp[len, max] = res;
        }

        private void SolveOneTestCase()
        {
            int n = In.NextInt();

            C = new long[n + 1, n + 1];
            for (int i = 0; i < n; ++i)
            {
                C[i, 0] = C[i, i] = 1;
                for (int j = 1; j < i; j++)
                {
                    C[i, j] = (C[i - 1, j] + C[i - 1, j - 1]) % MOD;
                }
            }

            dp = new int[n, n + 1];
            was = new bool[n, n + 1];
            int res = 0;
            for (int len = 1; len < n; ++len) res = (res + go(len, n)) % MOD;
            Out.WriteLine(res);
        }

        #region Local wireup

        public const string PROBLEM_ALIAS = "c";

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
