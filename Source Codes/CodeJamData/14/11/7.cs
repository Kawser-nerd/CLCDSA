using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
    public class Program
    {
        public static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: A.exe <input file> <output file>");
                return;
            }
            using (var textReader = File.OpenText(args[0]))
            {
                using (var textWriter = File.CreateText(args[1]))
                {
                    var testsCount = int.Parse(textReader.ReadLine().Trim());
                    for (int i = 0; i < testsCount; i++)
                        ProcessTestCase(i + 1, textReader, textWriter);
                }
            }
        }

        private static void ProcessTestCase(int testCaseNumber, TextReader reader, TextWriter writer)
        {
            var line = reader.ReadLine().Trim().Split(' ');
            var n = int.Parse(line[0]);
            var l = int.Parse(line[1]);
            var initial = reader.ReadLine().Trim().Split(' ').ToArray();
            var desired = reader.ReadLine().Trim().Split(' ').OrderBy(s => s).ToArray();

            int best = (int)1e9;
            bool ok = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    var mask = new bool[l];
                    var count = 0;
                    for (int k = 0; k < l; k++)
                    {
                        if (initial[i][k] != desired[j][k])
                        {
                            mask[k] = true;
                            count++;
                        }
                        else
                            mask[k] = false;
                    }
                    var transform = new string[n];
                    for (int r = 0; r < n; r++)
                    {
                        var stringBuilder = new StringBuilder();
                        for (int k = 0; k < l; k++)
                        {
                            if (initial[r][k] == '0')
                            {
                                if (mask[k])
                                    stringBuilder.Append('1');
                                else
                                    stringBuilder.Append('0');
                            }
                            else
                            {
                                if (mask[k])
                                    stringBuilder.Append('0');
                                else
                                    stringBuilder.Append('1');
                            }
                        }
                        transform[r] = stringBuilder.ToString();
                    }
                    transform = transform.OrderBy(s => s).ToArray();
                    bool eq = true;
                    for (int r = 0; r < n; r++)
                    {
                        if (desired[r] != transform[r])
                        {
                            eq = false;
                            break;
                        }
                    }
                    if (eq)
                    {
                        ok = true;
                        best = Math.Min(best, count);
                    }
                }
            }

            if (ok)
                writer.WriteLine("Case #{0}: {1}", testCaseNumber, best);
            else
                writer.WriteLine("Case #{0}: NOT POSSIBLE", testCaseNumber);
        }
    }
}
