using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "B-large";

        private static void Main()
        {
            Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
            Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
            var t = cin.NextInt();
            for (var c = 1; c <= t; c++)
            {
                if (c == 27)
                {
                    var g = 5;
                }
                Console.Write("Case #{0}: ", c);
                Solve();
            }
        }

        private static void Solve()
        {
            var n = cin.NextInt();

            var counts = new int[3000];

            var sold = new List<List<int>>();
            for (var i = 0; i < 2*n - 1; i++)
            {
                var list = new List<int>();
                for (var j = 0; j < n; j++)
                {
                    var num = cin.NextInt();
                    counts[num]++;
                    //list.Add(cin.NextInt());
                }
                //sold.Add(list);
            }

            var output = new List<int>();
            for (var i = 0; i < counts.Length; i++)
            {
                if (counts[i]%2 == 1)
                {
                    output.Add(i);
                }
            }

            for (var i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    Console.Write(output[i]);
                }
                else
                {
                    Console.Write(" " + output[i]);
                }
            }
            Console.WriteLine();
            return;


            sold.Sort(new Comparer());

            var grid = new int[n, n];

            var idx = 0;
            var ans = 0;
            var isRow = false;
            for (var i = 0; i < n; i++)
            {
                var first = sold[idx++];
                List<int> second = null;
                if (idx < sold.Count)
                {
                    second = sold[idx++];
                }
                if (i == 0)
                {
                    if (first[i] == second[i])
                    {
                        for (var j = 0; j < first.Count; j++)
                        {
                            grid[i, j] = first[j];
                        }
                        for (var j = 0; j < second.Count; j++)
                        {
                            grid[j, i] = second[j];
                        }
                    }
                    else
                    {
                        for (var j = 0; j < first.Count; j++)
                        {
                            grid[i, j] = first[j];
                        }
                        ans = i;
                        idx--;
                        isRow = false;
                    }
                }
                else
                {
                    var canRow = true;
                    for (var j = 0; j < i; j++)
                    {
                        if (grid[i, j] != first[j] && grid[i,j] > 0)
                        {
                            canRow = false;
                            break;
                        }
                    }

                    var canCol = true;
                    for (var j = 0; j < i; j++)
                    {
                        if (grid[j, i] != first[j] && grid[j, i] > 0)
                        {
                            canCol = false;
                            break;
                        }
                    }

                    var canRow2 = second != null;
                    for (var j = 0; j < i && canRow2; j++)
                    {
                        if (grid[i, j] != second[j] && grid[i, j] > 0)
                        {
                            canRow2 = false;
                            break;
                        }
                    }

                    var canCol2 = second != null;
                    for (var j = 0; j < i && canCol2; j++)
                    {
                        if (grid[j, i] != second[j] && grid[j, i] > 0)
                        {
                            canCol2 = false;
                            break;
                        }
                    }

                    if (canRow && canCol2)
                    {
                        for (var j = 0; j < first.Count; j++)
                        {
                            grid[i, j] = first[j];
                        }
                        for (var j = 0; j < second.Count; j++)
                        {
                            grid[j, i] = second[j];
                        }
                    }
                    else if (canCol && canRow2)
                    {
                        for (var j = 0; j < first.Count; j++)
                        {
                            grid[j, i] = first[j];
                        }
                        for (var j = 0; j < second.Count; j++)
                        {
                            grid[i, j] = second[j];
                        }
                    }
                    else if (canRow)
                    {
                        for (var j = 0; j < first.Count; j++)
                        {
                            grid[i, j] = first[j];
                        }
                        ans = i;
                        isRow = false;
                        idx--;
                    }
                    else if (canRow2)
                    {
                        for (var j = 0; j < second.Count; j++)
                        {
                            grid[i, j] = second[j];
                        }
                        ans = i;
                        isRow = false;
                        idx--;
                        sold[idx] = sold[idx - 1];
                    }
                    else if (canCol)
                    {
                        for (var j = 0; j < first.Count; j++)
                        {
                            grid[j, i] = first[j];
                        }
                        ans = i;
                        isRow = true;
                        idx--;
                    }
                    else
                    {
                        for (var j = 0; j < second.Count; j++)
                        {
                            grid[j, i] = second[j];
                        }
                        ans = i;
                        isRow = true;
                        idx--;
                        sold[idx] = sold[idx - 1];
                    }
                }
            }

            if (isRow)
            {
                for (var i = 0; i < n; i++)
                {
                    if (i == 0)
                    {
                        Console.Write(grid[ans, i]);
                    }
                    else
                    {
                        Console.Write(" " + grid[ans, i]);
                    }
                }
            }
            else
            {
                for (var i = 0; i < n; i++)
                {
                    if (i == 0)
                    {
                        Console.Write(grid[i, ans]);
                    }
                    else
                    {
                        Console.Write(" " + grid[i, ans]);
                    }
                }
            }
            Console.WriteLine();
        }
    }

    public class Comparer : IComparer<List<int>>
    {
        public int Compare(List<int> x, List<int> y)
        {
            for (var i = 0; i < x.Count; i++)
            {
                var res = x[i].CompareTo(y[i]);
                if (res != 0)
                {
                    return res;
                }
            }
            return 0;
        }
    }

    internal class Scanner
    {
        private string[] s = new string[0];
        private int i;
        private readonly char[] cs = { ' ' };

        public string NextString()
        {
            if (i < s.Length) return s[i++];
            var line = Console.ReadLine() ?? string.Empty;
            if (line == string.Empty)
            {
                return NextString();
            }
            s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 1;
            return s.First();
        }

        public double NextDouble()
        {
            return double.Parse(NextString());
        }

        public int NextInt()
        {
            return int.Parse(NextString());
        }

        public long NextLong()
        {
            return long.Parse(NextString());
        }
    }
}