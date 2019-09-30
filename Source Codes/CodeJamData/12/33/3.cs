using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_R1C_C
{
    class Program
    {
        static long result;

        static int n, m;

        static int[] A, B;
        static long[] a, b;

        static List<Cell>[,] table;
        
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"..\..\input.txt");

            StringBuilder output = new StringBuilder();

            int countOfTests = int.Parse(input[0]);
            int k = 1;

            for (int t = 0; t < countOfTests; t++)
            {
                string[] str = input[k].Split(' ');
                
                n = int.Parse(str[0]);
                m = int.Parse(str[1]);

                a = new long[n];
                b = new long[m];
                A = new int[n];
                B = new int[m];

                string[] row = input[k + 1].Split(' ');
                for (int j = 0; j < n; j++)
                {
                    a[j] = long.Parse(row[j * 2]);
                    A[j] = int.Parse(row[j * 2 + 1]);
                }

                row = input[k + 2].Split(' ');
                for (int j = 0; j < m; j++)
                {
                    b[j] = long.Parse(row[j * 2]);
                    B[j] = int.Parse(row[j * 2 + 1]);
                }
                result = long.MinValue;

                //Find(0, 0, a[0], b[0], 0);

                table = new List<Cell>[n, m];
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        table[i, j] = new List<Cell>();
                    }
                }


                for (int j = 0; j < m; j++)
                {
                    if (j == 0)
                    {
                        long r = A[0] == B[j] ? Math.Min(a[0], b[j]) : 0;
                        table[0, j].Add(new Cell { Count = r, AType = A[0], BType = B[j], AValue = a[0] - r, BValue = b[j] - r });
                    }
                    else
                    {
                        long r = A[0] == B[j] ? Math.Min(table[0, j - 1].First().AValue, b[j]) : 0;
                        table[0, j].Add(new Cell { Count = table[0, j - 1].First().Count + r, AType = A[0], BType = B[j], AValue = table[0, j - 1].First().AValue - r, BValue = b[j] - r });
                    }
                }

                for (int i = 0; i < n; i++)
                {
                    if (i == 0)
                    {
                        long r = A[i] == B[0] ? Math.Min(a[i], b[0]) : 0;
                        table[i, 0].Add(new Cell { Count = r, AType = A[i], BType = B[0], AValue = a[i] - r, BValue = b[0] - r });
                    }
                    else
                    {
                        long r = A[i] == B[0] ? Math.Min(table[i - 1, 0].First().BValue, a[i]) : 0;
                        table[i, 0].Add(new Cell { Count = table[i - 1, 0].First().Count + r, AType = A[i], BType = B[0], AValue = a[i] - r, BValue = table[i - 1, 0].First().BValue - r });
                    }
                }

                for (int i = 1; i < n; i++)
                {
                    for (int j = 1; j < m; j++)
                    {
                        foreach (var cell in table[i, j - 1])
                        {
                            long r = A[i] == B[j] ? Math.Min(cell.AValue, b[j]) : 0;
                            var newCell = new Cell { Count = cell.Count + r, AType = cell.AType, BType = B[j], AValue = cell.AValue - r, BValue = b[j] - r };

                            var query = (from c in table[i, j]
                                        where c.AType == newCell.AType && c.BType == newCell.BType && c.AValue == newCell.AValue && c.BValue == newCell.BValue
                                        select c).ToList();
                            if (query.Count > 0)
                            {
                                var max = query.Select(c => c.Count).Max();
                                if (newCell.Count > max)
                                {
                                    foreach (var c in query)
                                        table[i, j].Remove(c);
                                    table[i, j].Add(newCell);
                                }
                            }
                            else
                                table[i, j].Add(newCell);
                        }

                        foreach (var cell in table[i - 1, j])
                        {
                            long r = A[i] == B[j] ? Math.Min(cell.BValue, a[i]) : 0;
                            var newCell = new Cell { Count = cell.Count + r, AType = A[i], BType = cell.BType, AValue = a[i] - r, BValue = cell.BValue - r };

                            var query = (from c in table[i, j]
                                        where c.AType == newCell.AType && c.BType == newCell.BType && c.AValue == newCell.AValue && c.BValue == newCell.BValue
                                        select c).ToList();
                            if (query.Count > 0)
                            {
                                var max = query.Select(c => c.Count).Max();
                                if (newCell.Count > max)
                                {
                                    foreach (var c in query)
                                        table[i, j].Remove(c);
                                    table[i, j].Add(newCell);
                                }
                            }
                            else
                                table[i, j].Add(newCell);
                        }
                    }
                }

                for (int i = 0; i < n; i++)
                {
                    long max = table[i, m - 1].Select(c => c.Count).Max();
                    if (max > result)
                        result = max;
                }

                for (int j = 0; j < m; j++)
                {
                    long max = table[n - 1, j].Select(c => c.Count).Max();
                    if (max > result)
                        result = max;
                }

                output.AppendLine(string.Format("Case #{0}: {1}", t + 1, result));
                k += 3;
            }
            
            File.WriteAllText(@"..\..\output.txt", output.ToString());
        }

        public class Cell
        {
            public long Count { get; set; }

            public long AValue { get; set; }
            public long AType { get; set; }

            public long BValue { get; set; }
            public long BType { get; set; }
        }

        private static void Find(int i, int j, long boxes, long toys, long res)
        {
            if (i == n || j == m)
            {
                if (res > result)
                    result = res;

                return;
            }
            if (A[i] == B[j])
            {
                long r = Math.Min(boxes, toys);
                if (boxes == r)
                    Find(i + 1, j, i + 1 < n ? a[i + 1] : 0, toys - r, res + r);
                else
                    Find(i, j + 1, boxes - r, j + 1 < m ? b[j + 1] : 0, res + r);
            }
            else
            {
                Find(i + 1, j, i + 1 < n ? a[i + 1] : 0, toys, res );
                Find(i, j + 1, boxes, j + 1 < m ? b[j + 1] : 0, res);
            }
        }
    }
}
