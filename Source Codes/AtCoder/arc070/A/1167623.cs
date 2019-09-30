using System;
using System.Globalization;
using System.IO;
using System.Linq;

namespace AtCoder
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var sr = new InputReader(Console.In);
            //var sr = new InputReader(new StreamReader("input.txt"));
            using (var sw = Console.Out)
            //using (var sw = new StreamWriter("output.txt"))
            {
                Solve(sr, sw);
            }
        }


        internal static void Solve(InputReader sr, TextWriter sw)
        {
            var n = sr.NextInt32();

            var i = 0;
            var sum = 0;
            while (true)
            {
                if (sum >= n)
                {
                    sw.WriteLine(i);
                    return;
                }
                sum += ++i;
            }
        }
    }
    internal class InputReader : IDisposable
    {
        private bool isDispose;
        private readonly TextReader sr;

        public InputReader(TextReader stream)
        {
            sr = stream;
        }

        public void Dispose()
        {
            //Dispose(true);
            GC.SuppressFinalize(this);
        }

        public string NextString()
        {
            var result = sr.ReadLine();
            return result;
        }

        public int NextInt32()
        {
            return int.Parse(NextString());
        }

        public long NextInt64()
        {
            return long.Parse(NextString());
        }

        public string[] NextSplitStrings()
        {
            return NextString()
                .Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        public string[] NextSplitInts()
        {
            return NextString()
                .Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        public T[] ReadArray<T>(Func<string, CultureInfo, T> func)
        {
            return NextSplitStrings()
                .Select(s => func(s, CultureInfo.InvariantCulture))
                .ToArray();
        }

        public T[] ReadArrayFromString<T>(Func<string, CultureInfo, T> func, string str)
        {
            return str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(s => func(s, CultureInfo.InvariantCulture))
                .ToArray();
        }

        //protected void Dispose(bool dispose)
        //{
        //    if (isDispose) return;
        //    if (dispose)
        //    {
        //        sr.Close();
        //    }
        //    isDispose = true;
        //}

        //~InputReader()
        //{
        //    Dispose(false);
        //}
    }
}