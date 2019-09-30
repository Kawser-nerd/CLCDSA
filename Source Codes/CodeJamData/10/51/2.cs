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
        const string IN_FILE = @"A-small-attempt1.in";
        const string OUT_FILE = @"out.txt";

        private void SolveOneTestCase()
        {
            int d = In.NextInt(), k = In.NextInt();
            int[] a = new int[k];
            int[] ten = new int[10];
            ten[0] = 1;
            for (int i = 1; i < 10; ++i) ten[i] = 10 * ten[i - 1];
            for (int i = 0; i < k; i++)
            {
                a[i] = In.NextInt();
            }
            if (k == 1)
            {
                Out.WriteLine("I don't know.");
                return;
            }
            int[] p = new int[ten[d]];
            p[0] = p[1] = 1;
            for (int i = 2; i * i < ten[d]; ++i) if (p[i] == 0) for (int j = i * i; j < ten[d]; j += i) p[j] = 1;
            int nnn = -1;
            bool many = false;
            int mx = -1;
            for (int i = 0; i < k; ++i) mx = Math.Max(mx, a[i]);
            for (int i = mx+1; i < ten[d]; ++i) if (p[i] == 0)
                {
                    if (many) break;
                    for (int A = 0; A < i; ++A)
                    {
                        if (many) break;
                        int B = ((a[1] - (a[0] * A) % i) % i + i) % i;
                        bool ok = true;
                        for (int j = 2; j < k; ++j)
                        {
                            int next = (A * a[j - 1] + B) % i;
                            if (next != a[j]) { ok = false; break; }
                        }
                        if (ok)
                        {
                            int nn = (A * a[k - 1] + B) % i;
                            if (nnn == -1) nnn = nn;
                            else if (nnn != nn) { many = true; break; }
                        }
                    }
                }
            if (!many && nnn != -1)
            {
                Out.WriteLine(nnn);
            }
            else Out.WriteLine("I don't know.");
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
