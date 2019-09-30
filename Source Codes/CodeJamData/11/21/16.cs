/*
 * C# in .NET Framework 3.5
 * Usage:
 * executable -i input_file -o output_file
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RPI
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFile = String.Empty;
            var outFile = String.Empty;

            for (var i = 0; i < args.Length; i++)
            {
                switch (args[i])
                {
                    case "-i":
                        inFile = args[++i];
                        break;
                    case "-o":
                        outFile = args[++i];
                        break;
                }
            }

            if (!String.IsNullOrEmpty(inFile) && !String.IsNullOrEmpty(outFile))
            {
                using (var reader = new StreamReader(inFile))
                using (var writer = new StreamWriter(outFile))
                {
                    var p = new Program();
                    p.Run(reader, writer);
                }
            }
        }

        private void Run(TextReader reader, TextWriter writer)
        {
            var stopwatch = System.Diagnostics.Stopwatch.StartNew();

            var caseCount = int.Parse(reader.ReadLine());
            for (var i = 1; i <= caseCount; i++)
            {
                var answer = RunCase(reader);
                writer.WriteLine("Case #{0}:", i);
                foreach (var d in answer)
                    writer.WriteLine(d);
            }


            stopwatch.Stop();
            Console.WriteLine("{0:#,###}ms", stopwatch.ElapsedMilliseconds);
        }

        private IEnumerable<double> RunCase(TextReader reader)
        {
            var count = int.Parse(reader.ReadLine());
            var wpa = new double[count, count];
            var owpa = new double[count];

            for (var i = 0; i < count; i++)
            {
                var line = reader.ReadLine();
                var win = 0;
                var played = 0;
                foreach (var c in line)
                {
                    if (c == '0')
                        played++;
                    else if (c == '1')
                    {
                        played++;
                        win++;
                    }
                }
                var wp = (double)win / played;
                var owpWin = (double)(win - 1) / (played - 1);
                var owpLos = (double)win / (played - 1);
                for (var j = 0; j < count; j++)
                {
                    if (i == j)
                        wpa[i, j] = wp;
                    else if (line[j] == '1')
                        wpa[i, j] = owpWin;
                    else if (line[j] == '0')
                        wpa[i, j] = owpLos;
                    else
                        wpa[i, j] = -1;
                }
            }
            for (var j = 0; j < count; j++)
            {
                var total = 0d;
                var cnt = 0;

                for (var k = 0; k < count; k++)
                {
                    if (j == k) continue;

                    var owp = wpa[k, j];
                    if (owp != -1)
                    {
                        total += owp;
                        cnt++;
                    }
                }

                owpa[j] = total / cnt;
            }

            for (var i = 0; i < count; i++)
            {
                var owpTotal = 0d;
                var owpCount = 0;
                for (var j = 0; j < count; j++)
                {
                    if (i == j) continue;
                    if (wpa[i, j] == -1d) continue;
                    owpTotal += owpa[j];
                    owpCount++;
                }
                var oowp = owpTotal / owpCount;

                yield return 0.25 * wpa[i, i] + 0.5 * owpa[i] + 0.25 * oowp;
            }
        }
    }
}
