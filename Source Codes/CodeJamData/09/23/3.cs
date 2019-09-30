using System;
using System.Globalization;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    class Program
    {
        const string InputFile = @"..\..\Input.txt";
        const string OutputFile = @"..\..\Output.txt";

        static int[] SplitInts(string line)
        {
            var tokens = line.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            var res = new int[tokens.Length];
            for (int i = 0; i < res.Length; i++)
                res[i] = int.Parse(tokens[i], CultureInfo.InvariantCulture);
            return res;
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(InputFile))
            using (StreamWriter writer = new StreamWriter(OutputFile))
            {
                int T = int.Parse(reader.ReadLine());
                for (int i = 0; i < T; i++)
                {
                    writer.WriteLine("Case #{0}:", i + 1);
                    var ints = SplitInts(reader.ReadLine());
                    int W = ints[0];
                    string[] map = new string[W];
                    for (int j = 0; j < W; j++)
                    {
                        map[j] = reader.ReadLine();
                    }
                    ints = SplitInts(reader.ReadLine());
                    var vals = Get(map, ints);
                    foreach (var s in vals)
                    {
                        writer.WriteLine(s);
                    }
                }
            }
        }

        class Triple
        {
            public int A, B, C;

            public Triple(int a, int b, int c)
            {
                A = a;
                B = b;
                C = c;
            }

            public override string ToString()
            {
                return string.Format("A: {0}, B: {1}, C: {2}", A, B, C);
            }
        }

        static string[] Get(string[] map, int[] ints)
        {
            string[] res = new string[ints.Length];
            int count = res.Length;
            int W = map.Length;
            Dictionary<int, string>[,] fff = new Dictionary<int, string>[W,W];
            List<Triple> list = new List<Triple>();
            int s = map[0][0] == '+' || map[0][0] == '-' ? 1 : 0;
            for (int i = 0; i < W; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    fff[i, j] = new Dictionary<int, string>();
                    if ((i + j) % 2 == s)
                    {
                        fff[i, j][map[i][j] - '0'] = map[i][j].ToString();
                        list.Add(new Triple(i, j, map[i][j] - '0'));
                    }
                }
            }
            Check(fff, res, ints, ref count);
            while (count > 0)
            {
                List<Triple> newList = new List<Triple>();
                foreach (var triple in list)
                {
                    var i0 = triple.A;
                    var j0 = triple.B;
                    Go(fff, map, triple, newList, i0 + 1, j0, i0 + 1, j0 + 1);
                    Go(fff, map, triple, newList, i0 + 1, j0, i0 + 1, j0 - 1);
                    Go(fff, map, triple, newList, i0 + 1, j0, i0 + 2, j0);
                    Go(fff, map, triple, newList, i0 + 1, j0, i0, j0);
                    Go(fff, map, triple, newList, i0 - 1, j0, i0 - 1, j0 + 1);
                    Go(fff, map, triple, newList, i0 - 1, j0, i0 - 1, j0 - 1);
                    Go(fff, map, triple, newList, i0 - 1, j0, i0 - 2, j0);
                    Go(fff, map, triple, newList, i0 - 1, j0, i0, j0);
                    Go(fff, map, triple, newList, i0, j0 + 1, i0 + 1, j0 + 1);
                    Go(fff, map, triple, newList, i0, j0 + 1, i0 - 1, j0 + 1);
                    Go(fff, map, triple, newList, i0, j0 + 1, i0, j0 + 2);
                    Go(fff, map, triple, newList, i0, j0 + 1, i0, j0);
                    Go(fff, map, triple, newList, i0, j0 - 1, i0 + 1, j0 - 1);
                    Go(fff, map, triple, newList, i0, j0 - 1, i0 - 1, j0 - 1);
                    Go(fff, map, triple, newList, i0, j0 - 1, i0, j0 - 2);
                    Go(fff, map, triple, newList, i0, j0 - 1, i0, j0);
                }
                list = newList;
                Check(fff, res, ints, ref count);
            }
            return res;
        }

        static void Go(Dictionary<int, string>[,] fff, string[] map, Triple triple, List<Triple> newList, int i1, int j1, int i2, int j2)
        {
            int W = fff.GetLength(0);
            if (i1 < 0 || i1 >= W ||
                j1 < 0 || j1 >= W ||
                i2 < 0 || i2 >= W ||
                j2 < 0 || j2 >= W)
                return;
            int N = triple.C;
            char sign = map[i1][j1];
            int d = map[i2][j2] - '0';
            N += (sign == '+' ? 1 : -1) * d;
            string r = fff[triple.A, triple.B][triple.C];
            r += sign.ToString() + map[i2][j2];
            string old;
            if (!fff[i2, j2].TryGetValue(N, out old) || old.Length > r.Length || old.Length == r.Length && old.CompareTo(r) > 0)
            {
                fff[i2, j2][N] = r;
                newList.Add(new Triple(i2, j2, N));
            }
        }

        static void Check(Dictionary<int, string>[,] fff, string[] res, int[] ints, ref int count)
        {
            int W = fff.GetLength(0);
            for (int i = 0; i < ints.Length; i++)
            {
                if (res[i] != null) continue;
                for (int j = 0; j < W; j++)
                {
                    for (int k = 0; k < W; k++)
                    {
                        string s;
                        if (fff[j, k].TryGetValue(ints[i], out s))
                        {
                            if (res[i] == null)
                            {
                                res[i] = s;
                                count--;
                            } else if (s.Length < res[i].Length || s.Length==res[i].Length && s.CompareTo(res[i]) < 0)
                                res[i] = s;
                        }
                    }
                }
            }
        }
    }
}