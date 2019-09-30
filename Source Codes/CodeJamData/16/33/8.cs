using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "C-small-attempt1";

        private static void Main()
        {
            Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
            Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
            var t = cin.NextInt();
            for (var c = 1; c <= t; c++)
            {
                Debug.WriteLine(c);
                Console.Write("Case #{0}: ", c);
                Solve();
            }
        }

        private static void Solve()
        {
            var j = cin.NextInt();
            var p = cin.NextInt();
            var s = cin.NextInt();
            var k = cin.NextInt();

            var a = new List<int[]>();
            for (var b = 1; b <= j; b++)
            {
                for (var c = 1; c <= p; c++)
                {
                    for (var d = 1; d <= s; d++)
                    {
                        a.Add(new []{ b, c, d});
                    }
                }
            }
            var aa = a.ToArray();

            var bestCount = 0;
            int[][] bestOrder = null;
            for (var i = 0; i < 3000000; i++)
            {
                Shuffle(aa);
                var visited = new Dictionary<int, int>();
                var found = false;
                for (var b = 0; b < aa.Length; b++)
                {
                    var pair = aa[b][0]*100 + aa[b][1]*10;
                    if (!visited.ContainsKey(pair))
                    {
                        visited[pair] = 0;
                    }
                    visited[pair]++;
                    if (visited[pair] > k)
                    {
                        if (b > bestCount)
                        {
                            bestCount = b;
                            bestOrder = aa.ToArray();
                        }
                        found = true;
                        break;
                    }

                    pair = aa[b][0] * 100 + aa[b][2];
                    if (!visited.ContainsKey(pair))
                    {
                        visited[pair] = 0;
                    }
                    visited[pair]++;
                    if (visited[pair] > k)
                    {
                        if (b > bestCount)
                        {
                            bestCount = b;
                            bestOrder = aa.ToArray();
                        }
                        found = true;
                        break;
                    }

                    pair = aa[b][1] * 10 + aa[b][2];
                    if (!visited.ContainsKey(pair))
                    {
                        visited[pair] = 0;
                    }
                    visited[pair]++;
                    if (visited[pair] > k)
                    {
                        if (b > bestCount)
                        {
                            bestCount = b;
                            bestOrder = aa.ToArray();
                        }
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    bestCount = aa.Length;
                    bestOrder = aa;
                    break;
                }
            }
            Console.WriteLine(bestCount);
            for (var i = 0; i < bestCount; i++)
            {
                Console.WriteLine(string.Join(" ", bestOrder[i].Select(x => x.ToString())));
            }
        }

        static Random _random = new Random();

        static void Shuffle<T>(T[] array)
        {
            int n = array.Length;
            for (int i = 0; i < n; i++)
            {
                // NextDouble returns a random number between 0 and 1.
                // ... It is equivalent to Math.random() in Java.
                int r = i + (int)(_random.NextDouble() * (n - i));
                T t = array[r];
                array[r] = array[i];
                array[i] = t;
            }
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