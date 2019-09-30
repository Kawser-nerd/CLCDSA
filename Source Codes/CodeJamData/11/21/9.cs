using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace GCJ.TaskA
{
    class Solution
    {
        private readonly int _num;
        private readonly int _n;
        private readonly string[] _a;
        private double[] _res;

        private double WP(int t, int skip)
        {
            int g = 0;
            int w = 0;
            for (int i=0;i<_n;i++)
            {
                if (_a[t][i] == '.' || i == skip)
                    continue;

                g++;
                if (_a[t][i] == '1')
                    w++;
            }

            if (g == 0)
                return 0;

            return ((double)w) / g;
        }

        private double OWP(int t)
        {
            double sum = 0;
            int count = 0;
            for (int i=0;i<_n;i++)
            {
                if (i == t || _a[t][i] == '.') continue;

                var rp = WP(i, t);
                sum += rp;
                count++;
            }

            if (count == 0)
                return 0;

            return sum/count;
        }

        private double OOWP(int t)
        {
            double sum = 0;
            int count = 0;
            for (int i=0;i<_n;i++)
            {
                if (i == t || _a[t][i] == '.') continue;

                count++;
                sum += OWP(i);
            }
            if (count == 0)
                return 0;

            return sum/count;
        }

        internal Solution(TextReader reader, int num)
        {
            _num = num;

            _n = reader.ReadLineAsInt();
            _a = new string[_n];
            
            for (int i=0;i<_n;i++)
            {
                _a[i] = reader.ReadLine();
            }
        }

        public void Solve()
        {
            Console.WriteLine("Start: {0}.", _num);
            _res = new double[_n];
            for (int i = 0; i < _n;i++)
            {
                var wp = WP(i, -1);
                var owp = OWP(i);
                var oowp = OOWP(i);

                _res[i] = 0.25*wp + 0.5*owp + 0.25*oowp;
            }

            Console.WriteLine("Done: {0}.", _num);
        }

        public void WriteResult(TextWriter writer)
        {
            writer.WriteLine();
            writer.WritePerLine(_res);
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
                writer.WriteLine(items[i].ToString().Replace(',', '.'));

            writer.Write(items[items.Count - 1].ToString().Replace(',', '.'));

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
