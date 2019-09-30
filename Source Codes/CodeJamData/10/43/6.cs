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
        const string IN_FILE = @"C-small-attempt0.in";
        const string OUT_FILE = @"out.txt";

        private void SolveOneTestCase()
        {
            int R = In.NextInt();
            int[,] a = new int[200, 200];
            for (int z = 0; z < R; ++z)
            {
                int x1 = In.NextInt(), y1 = In.NextInt(), x2 = In.NextInt(), y2 = In.NextInt();
                for (int i = Math.Min(y1, y2); i <= Math.Max(y1, y2); ++i)
                    for (int j = Math.Min(x1, x2); j <= Math.Max(x1, x2); ++j) a[i, j] = 1;
            }
            Queue<int> delete = new Queue<int>(), add = new Queue<int>();
            for (int i = 1; i <= 100; ++i)
                for (int j = 1; j <= 100; ++j) if (a[i, j] == 0)
                    {
                        if (a[i - 1, j] + a[i, j - 1] == 2) { add.Enqueue(i); add.Enqueue(j); }
                    }
                    else
                    {
                        if (a[i - 1, j] + a[i, j - 1] == 0) { delete.Enqueue(i); delete.Enqueue(j); }
                    }
            int res = 0;
            while (add.Count > 0 || delete.Count > 0)
            {
                ++res;
                Queue<int> check = new Queue<int>();
                while (delete.Count > 0)
                {
                    int r = delete.Dequeue();
                    int c = delete.Dequeue();
                    if (a[r, c] == 0) continue;
                    a[r, c] = 0;
                    if (a[r + 1, c] == 1)
                    {
                        check.Enqueue(r + 1);
                        check.Enqueue(c);
                    }
                    if (a[r, c + 1] == 1)
                    {
                        check.Enqueue(r);
                        check.Enqueue(c + 1);
                    }
                }

                while (check.Count > 0)
                {
                    int r = check.Dequeue();
                    int c = check.Dequeue();
                    if (a[r, c] == 1 && a[r - 1, c] + a[r, c - 1] == 0)
                    {
                        delete.Enqueue(r);
                        delete.Enqueue(c);
                    }
                }


                while (add.Count > 0)
                {
                    int r = add.Dequeue();
                    int c = add.Dequeue();
                    if (a[r, c] == 1) continue;
                    a[r, c] = 1;
                    if (a[r + 1, c] == 0)
                    {
                        check.Enqueue(r + 1);
                        check.Enqueue(c);
                    }
                    if (a[r, c + 1] == 0)
                    {
                        check.Enqueue(r);
                        check.Enqueue(c + 1);
                    }
                }

                while (check.Count > 0)
                {
                    int r = check.Dequeue();
                    int c = check.Dequeue();
                    if (a[r, c] == 0 && a[r - 1, c] + a[r, c - 1] == 2)
                    {
                        add.Enqueue(r);
                        add.Enqueue(c);
                    }
                }
            }
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
