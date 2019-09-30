using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace GCJ.TaskB
{
    class Solution
    {
        private readonly int _num;
        private int _n;
        private int _d;
        private double _result;

        private List<double> _a;

        private double _minP;

        internal Solution(TextReader reader, int num)
        {
            _num = num;
            int[] tmp = reader.ReadLineAsIntArray();
            _n = tmp[0];
            _d = tmp[1];
            _a = new List<double>(_n);
            for (int i=0;i<_n;i++)
            {
                tmp = reader.ReadLineAsIntArray();
                for (int j=0;j<tmp[1];j++)
                    _a.Add(tmp[0]);
                if (tmp[0] < _minP)
                    _minP = tmp[0];
            }
        }

        public void Solve()
        {
            Console.WriteLine("Start: {0}.", _num);

            double _f;
            double min = 0;
            double max = 1000000000000;

            _a.Sort();
            int n = _a.Count;

            
            while(true)
            {
                bool res = true;
                double _t = (min + max) / 2;
                if (_t == max)
                {
                    _result = max;
                    break;
                }
                _f = _minP - _t;
                double _cur = _f;

                for (int i=0;i<n;i++)
                {
                    double v1 = _a[i] - _t;
                    double v2 = _a[i] + _t;

                    if (v2 < _cur)
                    {
                        res = false;
                        break;
                    }

                    if (v1 <= _cur && v2 >= _cur)
                    {
                        _cur += _d;
                    } else if (v1 > _cur)
                    {
                        _cur = v1 + _d;
                    }
                }

                if (res)
                    max = _t;
                else
                    min = _t + 1e-6;

                if (max - min <= 1e-6)
                {
                    _result = max;
                    break;
                }
            }

            Console.WriteLine("Done: {0}.", _num);
        }

        public void WriteResult(TextWriter writer)
        {
            writer.Write(_result.ToString().Replace(',', '.'));
        }
    }

    class Program
    {
        private static int _numberOfTests;
        private static Solution[] _solutions;

        private static void ReadData()
        {
            using (var reader = new StreamReader(@"..\..\input.txt"))
            {
                _numberOfTests = reader.ReadLineAsInt();
                _solutions = new Solution[_numberOfTests];
                for (int i = 0; i < _numberOfTests; ++i)
                {
                    _solutions[i] = new Solution(reader, i);
                }
            }
        }

        private static void Run(bool singleThread = false)
        {
            var tasks = new Task[_numberOfTests];
            for (int i = 0; i < _numberOfTests; i++)
            {
                tasks[i] = Task.Factory.StartNew(_solutions[i].Solve);
                if (singleThread)
                    tasks[i].Wait();
            }

            Task.WaitAll(tasks);
        }

        private static void WriteResult()
        {
            using (var writer = new StreamWriter(@"..\..\output.txt"))
            {
                for (int i = 0; i < _numberOfTests; ++i)
                {
                    if (i > 0)
                        writer.WriteLine();

                    writer.Write("Case #{0}: ", i + 1);
                    _solutions[i].WriteResult(writer);
                }
            }
        }

        static void Main(string[] args)
        {
            ReadData();
            Run();
            WriteResult();
        }
    }

    #region Helper

    internal static class Helper
    {
        internal static int ReadLineAsInt(this TextReader reader)
        {
            return Int32.Parse(reader.ReadLine());
        }

        internal static int[] ReadLineAsIntArray(this TextReader reader, char separator = ' ')
        {
            return Array.ConvertAll(reader.ReadLine().Split(' '), Int32.Parse);
        }

        internal static string[] ReadLineAsStringArray(this TextReader reader, char separator = ' ')
        {
            return reader.ReadLine().Split(separator);
        }

        internal static Tuple<int, int[]> ReadLineAsIntAndIntArray(this TextReader reader, char separator = ' ')
        {
            var temp = Array.ConvertAll(reader.ReadLine().Split(separator), Int32.Parse);
            var result = new Tuple<int, int[]>(temp[0], new int[temp[0]]);
            Array.Copy(temp, 1, result.Item2, 0, temp[0]);

            return result;
        }

        internal static Tuple<int, string[]> ReadLineAsIntAndStringArray(this TextReader reader, char separator = ' ')
        {
            var temp = reader.ReadLine().Split(separator);
            int n = Int32.Parse(temp[0]);
            var result = new Tuple<int, string[]>(n, new string[n]);
            Array.Copy(temp, 1, result.Item2, 0, n);

            return result;
        }

        internal static void WritePerLine(this TextWriter writer, IList items, bool addNewLine = false)
        {
            if (items.Count == 0)
                return;

            for (int i = 0; i < items.Count - 1; i++)
                writer.WriteLine(items[i]);

            writer.Write(items[items.Count - 1]);

            if (addNewLine)
                writer.WriteLine();
        }

        internal static void WriteAsSingleLine(this TextWriter writer, IList items, bool addNewLine = false)
        {
            if (items.Count == 0)
                return;

            for (int i = 0; i < items.Count - 1; i++)
            {
                writer.Write(items[i]);
                writer.Write(" ");
            }

            writer.Write(items[items.Count - 1]);

            if (addNewLine)
                writer.WriteLine();
        }
    }

    #endregion

}
