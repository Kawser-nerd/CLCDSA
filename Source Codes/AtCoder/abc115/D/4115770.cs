#if DEBUG
using System.Reflection;
using System.Threading.Tasks;
#endif

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Globalization;

#if DEBUG
using System.Diagnostics;
#endif

namespace at115
{
    class Program
    {
        static string _inputFilename = "input.txt";
        static string _outputFilename = "output.txt";
        static bool _useFileInput = false;
        const string _delim = "!";


        static void Main(string[] args)
        {
            StreamWriter file = null;
#if DEBUG
            var testNumber = 0;
            var timer = new Stopwatch();
            foreach (var test in GetTests())
            {

                timer.Start();

                var defaultColor = Console.ForegroundColor;
                Console.ForegroundColor = ConsoleColor.DarkYellow;
                Console.WriteLine($"<!-- TEST #{testNumber} -->");
                Console.ForegroundColor = defaultColor;
                Console.SetIn(test);


#else
            if (_useFileInput)
            {
                Console.SetIn(File.OpenText(_inputFilename));
                file = new StreamWriter(_outputFilename);
                Console.SetOut(file);
            }
#endif

            try
            {
#if DEBUG
                Solution(testNumber);
#else
                Solution(0);
#endif
            }
            finally
            {
#if DEBUG
#else
                if (_useFileInput)
                {
                    file.Close();
                }
#endif
            }

#if DEBUG
                timer.Stop();

                Console.ForegroundColor = ConsoleColor.DarkYellow;
                Console.WriteLine($"<!-- TEST #{testNumber} FINISHED IN {timer.Elapsed.ToString(@"ss\:fff")}-->");
                Console.ForegroundColor = defaultColor;

                timer.Reset();
                testNumber++;
            }
#endif
        }



        static void Solution(int testNumber)
        {
            #region SOLUTION
            var d = ReadLongArray();
            var n = d[0];
            var x = d[1];

            var pc = new long[n + 1];
            pc[0] = 1;

            var sz = new long[n + 1];
            sz[0] = 1;
            for (int i = 1; i < n + 1; i++)
            {
                pc[i] = 2 * pc[i - 1] + 1;
                sz[i] = 2 * sz[i - 1] + 3;
            }

            var count = 0L;
            var size = n;
            var ct = sz[n];
            while (true)
            {
                if (size == 1)
                {

                }
                var mid = ct / 2 + 1;
                if (x == 1)
                {
                    if (ct == 1)
                    {
                        count++;
                    }

                    break;
                }

                if (x == ct)
                {
                    count += (2 * pc[size - 1]) + 1;
                    break;
                }

                if (x == mid)
                {
                    count += (pc[size - 1]) + 1;
                    break;
                }

                if (x < mid)
                {
                    size--;

                    ct = sz[size];
                    //ct = mid - 2;
                    x--;
                }
                else if (x > mid)
                {
                    count += (pc[size - 1]) + 1;
                    x -= mid;

                    size--;
                    ct = sz[size];
                    
                }
            }

            Console.WriteLine(count);
            //var n = readInt();
            //var m = readInt();

            //var a = readIntArray();
            //var b = readIntArray();
            #endregion
        }

        static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }

        static int[] ReadIntArray()
        {
            return Console.ReadLine().Split(' ').Where(i => !string.IsNullOrEmpty(i)).Select(i => int.Parse(i)).ToArray();
        }

        static long[] ReadLongArray()
        {
            return Console.ReadLine().Split(' ').Where(i => !string.IsNullOrEmpty(i)).Select(i => long.Parse(i)).ToArray();
        }

#if DEBUG
        static IEnumerable<TextReader> GetTests()
        {
            var tests = new List<string>();
            var resName = Assembly.GetCallingAssembly().GetManifestResourceNames()[0];
            using (var resource = new StreamReader(Assembly.GetCallingAssembly().GetManifestResourceStream(resName)))
            {
                while (true)
                {
                    var nextText = new StringBuilder();
                    var endOfFile = false;
                    while (true)
                    {
                        var line = resource.ReadLine();

                        endOfFile = line == null;
                        if (endOfFile)
                        {
                            break;
                        }

                        if (line.Equals(_delim, StringComparison.Ordinal))
                        {
                            break;
                        }

                        nextText.AppendLine(line);
                    }

                    yield return new StringReader(nextText.ToString());

                    if (endOfFile)
                    {
                        break;
                    }
                }
            }
        }
#endif
    }
}