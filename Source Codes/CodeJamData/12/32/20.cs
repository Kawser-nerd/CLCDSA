using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2
{
    public class CodeJamProblem : IDisposable
    {
        private StreamReader _reader;
        private StreamWriter _writer;

        private bool disposed = false;

        public CodeJamProblem(string path)
        {
            _reader = new StreamReader(path);
            _writer = new StreamWriter(Path.ChangeExtension(path, ".out"));

            CaseNumber = 1;
            StartTime = Environment.TickCount;
        }

        public int StartTime { get; private set; }
        public int ElapsedTime { get; private set; }
        public int CaseNumber { get; private set; }

        public bool InputAvailable
        {
            get { return _reader.Peek() != -1; }
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose(bool disposing)
        {
            if (disposed) return;
            if (disposing)
            {
                this.ElapsedTime = Environment.TickCount - this.StartTime;

                _reader.Dispose();
                _writer.Dispose();

                Console.WriteLine("Elapsed time: {0:#,#0}ms", this.ElapsedTime);
                Console.Beep();
                Console.ReadKey(true);
            }

            disposed = true;
        }

        public void OutputCase(params object[] values)
        {
            var parts = new string[values.Length];
            for (int i = 0; i < parts.Length; i++)
                parts[i] = values[i].ToString();
            OutputCase(string.Join(" ", parts));
        }

        public void OutputCase()
        {
            OutputCase((string)null);
        }

        public void OutputCase(string value)
        {
            WriteLine("Case #{0:#0}: {1}", CaseNumber, value);
            ++CaseNumber;
        }

        public void WriteArrays<T>(T[][] entries)
        {
            for (int i = 0; i < entries.Length; i++)
                WriteArray(entries[i]);
        }

        public void WriteArray<T>(T[] values)
        {
            var parts = new string[values.Length];
            for (int i = 0; i < parts.Length; i++)
                parts[i] = values[i].ToString();
            WriteLine(string.Join(" ", parts));
        }

        public void WriteLines(string[] lines)
        {
            for (int i = 0; i < lines.Length; i++)
                WriteLine(lines[i]);
        }

        public void WriteLine(string format, params object[] arg)
        {
            Console.WriteLine(format, arg);
            this._writer.WriteLine(format, arg);
        }

        public void WriteLine(string line)
        {
            Console.WriteLine(line);
            this._writer.WriteLine(line);
        }

        public T[][] ReadArrays<T>(int count, Func<string, T> converter)
        {
            var entries = new T[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadArray(converter);
            return entries;
        }

        public T[] ReadArray<T>(Func<string, T> converter)
        {
            var parts = ReadParts();
            var values = new T[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = converter(parts[i]);
            return values;
        }

        public short[][] ReadInt16Arrays(int count)
        {
            var entries = new short[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt16Array();
            return entries;
        }

        public short[] ReadInt16Array()
        {
            var parts = ReadParts();
            var values = new short[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = short.Parse(parts[i]);
            return values;
        }

        public int[][] ReadInt32Arrays(int count)
        {
            var entries = new int[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt32Array();
            return entries;
        }

        public int[] ReadInt32Array()
        {
            var parts = ReadParts();
            var values = new int[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = int.Parse(parts[i]);
            return values;
        }

        public long[][] ReadInt64Arrays(int count)
        {
            var entries = new long[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt64Array();
            return entries;
        }

        public long[] ReadInt64Array()
        {
            var parts = ReadParts();
            var values = new long[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = long.Parse(parts[i]);
            return values;
        }

        public double[][] ReadDoubleArrays(int count)
        {
            var entries = new double[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadDoubleArray();
            return entries;
        }

        public double[] ReadDoubleArray()
        {
            var parts = ReadParts();
            var values = new double[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = double.Parse(parts[i]);
            return values;
        }

        public string[] ReadParts()
        {
            return ReadLine().Split(' ');
        }

        public string[] ReadLines(int count)
        {
            var lines = new string[count];
            for (int i = 0; i < lines.Length; i++)
                lines[i] = ReadLine();
            return lines;
        }

        public short ReadLineInt16()
        {
            return short.Parse(ReadLine());
        }

        public int ReadLineInt32()
        {
            return int.Parse(ReadLine());
        }

        public long ReadLineInt64()
        {
            return long.Parse(ReadLine());
        }

        public double ReadLineDouble()
        {
            return double.Parse(ReadLine());
        }

        public string ReadLine()
        {
            return _reader.ReadLine();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (var prob = new CodeJamProblem(args[0]))
            {
                int probCount = prob.ReadLineInt32();
                for (int i = 0; i < probCount; ++i)
                {
                    prob.OutputCase();
                    var counts = prob.ReadDoubleArray();
                    double d = counts[0];
                    var car2 = prob.ReadDoubleArrays((int)counts[1]);
                    foreach (double a in prob.ReadDoubleArray())
                    {
                        prob.WriteLine("{0:0.0000000}", GetTime(d, a, car2));
                    }
                }
            }
        }

        public static double GetTime(double d, double a, double[][] car2)
        {
            double vi = 0, si = 0;
            for (int i = 1; i < car2.Length; ++i)
            {
                double t0 = car2[i - 1][0], t1 = car2[i][0], s0 = car2[i - 1][1], s1 = car2[i][1];
                double dt = t1 - t0;
                double car2v = (s1 - s0) / (t1 - t0);

                double tCatch = t0 + Solve(0.5 * a, vi - car2v, -s0);
                double sCatch = car2v * (tCatch - t0) + s0;

                if (sCatch >= d)
                    return t0 + Solve(0.5 * a, vi, si - d);

                if (tCatch <= t1)
                {
                    if (s1 >= d)
                        return (d - s0) * dt / (s1 - s0) + t0;
                    
                    // If there a fast leg coming up, should we brake early and build up a head of speed before reaching car2?
                    vi = car2v;
                    si = s1;
                }
                else
                {
                    si += vi * dt + 0.5 * a * dt;
                    vi += a * dt;
                }
            }
            return Solve(0.5 * a, vi, si - d);
        }

        public static double Solve(double a, double b, double c)
        {
            double part = Math.Sqrt(b * b - 4 * a * c);
            //double solution2 = (-b - part) / (2 * a);
            return (-b + part) / (2 * a);
        }
    }
}
