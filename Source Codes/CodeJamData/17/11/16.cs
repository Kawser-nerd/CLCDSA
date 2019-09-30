using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;

namespace CodeJam
{
    class Program
    {
        private const string FileName = "A-large";

        static string[] Solve(string[] rows)
        {
            bool[] emptyRows = new bool[rows.Length];

            for (int i = 0; i < rows.Length; i++)
            {
                StringBuilder r = new StringBuilder(rows[i]);

                bool isEmpty = true;
                for (int j = 0; j < r.Length; j++)
                {
                    if (r[j] != '?')
                    {
                        isEmpty = false;

                        int z;
                        for (z = j-1; z >= 0 && r[z] == '?'; z--)
                            r[z] = r[j];

                        for (z = j+1; z < r.Length && r[z] == '?'; z++)
                            r[z] = r[j];

                        j = z-1;
                    }
                }

                emptyRows[i] = isEmpty;

                rows[i] = r.ToString();
            }

            for (int row_idx = 0; row_idx < rows.Length; row_idx++)
            {
                if (!emptyRows[row_idx])
                {
                    for (int rr = row_idx - 1; rr >= 0 && emptyRows[rr]; rr--)
                    {
                        rows[rr] = rows[row_idx];
                        emptyRows[rr] = false;
                    }

                    for (int rr = row_idx + 1; rr < rows.Length && emptyRows[rr]; rr++)
                    {
                        rows[rr] = rows[row_idx];
                        emptyRows[rr] = false;
                    }
                }
            }

            return rows;
        }

        static void Main(string[] args)
        {
            var data = File.ReadAllLines($"D:\\!CodeJam\\1\\{FileName}.in").ToArray();

            List<string> result = new List<string>();

            int testCaseNumber = 1;
            for (int i = 1; i < data.Length; i++)
            {
                string[] tokens = data[i].Split(' ');
                int[] intTokens = tokens.Select(t => Int32.Parse(t)).ToArray();
                int R = intTokens[0];
                int C = intTokens[1];

                string[] rows= new string[R];
                for (int j = 0; j < R; j++)
                {
                    i++;
                    rows[j] = data[i];
                }

                result.Add($"Case #{testCaseNumber}:");
                foreach (var r in Solve(rows))
                {
                    result.Add(r);
                }

                testCaseNumber++;
            }

            File.WriteAllLines($"D:\\!CodeJam\\1\\{FileName}.out", result);
        }
    }
}
