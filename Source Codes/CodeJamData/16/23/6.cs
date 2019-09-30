﻿using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

class Program
{
    private static void Flip(int[] m, int l)
    {
        for (int i = 0; i < l; i++) m[i] = 1 - m[i];
        for (int i = 0; i < l / 2; i++)
            Swap(ref m[i], ref m[l - i - 1]);
    }

    private static int IntValue(int[] m)
    {
        int ans = 0;

        for (int i = 0; i < m.Length; i++)
            ans += (m[i] << i);

        return ans;
    }

    private static int[,] dp = new int[11, 1 << 11];
    private static void Solve(int[] m, int l = 0)
    {
        int x = IntValue(m);
        if (dp[m.Length, x] <= l) return;

        dp[m.Length, x] = l;

        for (int i = 1; i <= m.Length; i++)
        {
            Flip(m, i);
            Solve(m, l + 1);
            Flip(m, i);
        }
    }

    private static bool GoodChar(char ch)
    {
        return Char.IsLetterOrDigit(ch) || ch == '?';
    }

    private static char[] ReadStr()
    {
        int ans;

        do
        {
            ans = consoleReader.Read();
        } while (!GoodChar((char)ans));

        List<char> s = new List<char>();
        do
        {
            s.Add((char)ans);
            ans = consoleReader.Read();
        } while (GoodChar((char)ans));

        return s.ToArray();
    }

    private static int[] ToArray(char[] s)
    {
        int[] m = new int[s.Length];
        for (int i = 0; i < s.Length; i++)
            m[i] = s[i] == '+' ? 0 : 1;

        return m;
    }

    private static int GetCount(int ch, int[] m, string s)
    {
        int answer = m[ch - 'A'];
        for (int i = 0; i < s.Length; i++)
            m[s[i] - 'A'] -= answer;

        return answer;
    }

    private static string ToString(int x, char[] s)
    {
        string xx = x.ToString().PadLeft(s.Length, '0');
        return xx;
    }

    private static bool IsMatched(char[] s, int x)
    {
        string xx = ToString(x, s);
        for (int i = 0; i < s.Length; i++)
            if (s[i] != xx[i] && s[i] != '?')
                return false;

        return true;
    }

    class MaxFlow
    {
        public static int n;
        public static int[,] map;
        public static int PushFlow(int s, int e)
        {
            List<int> buf = new List<int>() { s };
            int p = 0;
            int[] income = new int[n];
            for (int i = 0; i < income.Length; i++) income[i] = -1;
            int[] l = new int[n];
            l[s] = int.MaxValue;

            while (p < buf.Count)
            {
                int v = buf[p++];
                for (int i = 0; i < n; i++)
                    if (income[i] == -1 && map[v, i] > 0)
                    {
                        buf.Add(i);
                        income[i] = v;
                        l[i] = Math.Min(l[v], map[v, i]);
                    }
            }

            if (income[e] == -1) return 0;

            int flowSize = l[e];
            while (e != s)
            {
                map[income[e], e] -= flowSize;
                map[e, income[e]] += flowSize;
                e = income[e];
            }

            return flowSize;
        }

        public static int GetMaxFlow()
        {
            int flow = 0;
            while (true)
            {
                int delta = PushFlow(0, 1);
                if (delta == 0) break;
                flow += delta;
            }

            return flow;
        }
    }

    static void Main(string[] args)
    {
        string path = @"C:\Users\Толик\Downloads\C-Large.in";
        string pathOut = path.Replace(".in", ".out");
        PushTestData(System.IO.File.ReadAllText(path));
        /*
        PushTestData(@"3
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC");*/

        int t = ReadInt();
        var sb = new StringBuilder();

        for (int k = 0; k < t; k++)
        {
            Console.WriteLine("TestId" + k);
            List<int> a = new List<int>();
            List<int> b = new List<int>();
            int n = ReadInt();

            var d1 = new Dictionary<string, int>();
            var d2 = new Dictionary<string, int>();
            int nextId1 = 0;
            int nextId2 = 0;
            for (int i = 0; i < n; i++)
            {
                var a1 = new string(ReadStr());
                var a2 = new string(ReadStr());
                if (!d1.ContainsKey(a1)) d1.Add(a1, nextId1++);
                if (!d2.ContainsKey(a2)) d2.Add(a2, nextId2++);

                a.Add(d1[a1]);
                b.Add(d2[a2]);
            }
            /*
            int nn = n+n+2;
            int[,] map = new int[nn, nn];
            for (int i = 2; i < nn; i++)
                for (int j = 2; j < nn; j++)
                    if (i != j)
                        map[i, j] = 1;

            var d = new Dictionary<string, int>();
            int nextId = 2;
            for (int i = 0; i < n; i++)
            {
                if (!d.ContainsKey(a[i])) d.Add(a[i], nextId++);
                if (!d.ContainsKey(b[i])) d.Add(b[i], nextId++);

                map[d[a[i]], d[b[i]]] = 0;
                map[0, d[a[i]]] = 1;
                map[d[b[i]], 1] = 1;
            }



            MaxFlow.map = map;
            MaxFlow.n = nextId;
            */

            var g = new List<int>[Math.Max(nextId1, nextId2)];
            for (int i = 0; i < g.Length; i++) g[i] = new List<int>();

            int extra = 0;
            for(int i=0;i<a.Count;i++)
                {
                    if (!g[a[i]].Contains(b[i]))
                    {
                        g[a[i]].Add(b[i]);
                    }
                    else extra++;
                }

            var maxArr = MaxMatching.BuildMaxMatching(g);
            int max = maxArr.Count(x => x != -1);

            //bestDeep = int.MaxValue;
            //Go(a.Distinct().ToArray(), b.Distinct().ToArray(), new bool[nextId1], new bool[nextId2]);
            //max = bestDeep;

            int answer = nextId1 + nextId2 - max;

            //sb.AppendFormat("Case #{0}: {1}", k + 1, MaxFlow.GetMaxFlow());
            sb.AppendFormat("Case #{0}: {1}", k + 1, n - answer);
            sb.AppendLine();

            Console.WriteLine((k + 1) + " >>> " + (n - answer));
        }

        var str = sb.ToString();
        Console.WriteLine(str);
        System.IO.File.WriteAllText(pathOut, str);
        Console.WriteLine(pathOut);

        
        Console.WriteLine("ISSUE CHECK");
        var l1 = System.IO.File.ReadAllLines(pathOut);
        var l2 = System.IO.File.ReadAllLines(pathOut.Replace("5", "55"));
        for (int i = 0; i < l1.Length; i++)
        {
            if (l1[i] != l2[i])
            {
                Console.WriteLine("ISSUE");
                Console.WriteLine(l1[i]);
                Console.WriteLine(l2[i]);
            }
        }
    }

    /*
    private static bool HasPair(string s1, string s2, List<int> a, List<int> b)
    {
        for (int i = 0; i < a.Count; i++)
            if (s1 == a[i] && s2 == b[i])
                return true;

        return false;
    }*/

    private static int GetIntVal(bool[] map)
    {
        int ans = 0;
        for (int i = 0; i < map.Length; i++)
            if (map[i])
                ans += (1 << i);

        return ans;
    }

    private static int maxPairs;
    private static bool[,] pair;
    private static int[] cache;
    private static int bestDeep;
    private static void Go(int[] a, int[] b, bool[] aa, bool[] bb, int d = 0, int last = 0)
    {
        if (d >= bestDeep)
            return;

        bool hasTurn = false;
        for (int i = 0; i < a.Length; i++)
            if (!aa[a[i]])
                for (int j = 0; j < b.Length; j++)
                    if (!bb[b[j]])
                    {
                        aa[a[i]] = true;
                        bb[b[j]] = true;

                        hasTurn = true;
                        Go(a, b, aa, bb, d + 1);

                        aa[a[i]] = false;
                        bb[b[j]] = false;
                    }

        if (!hasTurn)
        {
            bestDeep = Math.Min(bestDeep, d);
        }
    }

    class MaxMatching
    {

        private static bool TryKuhn(int v, List<int>[] g, int[] matching, bool[] used)
        {
            if (used[v]) return false;
            used[v] = true;

            for (int i = 0; i < g[v].Count; i++)
            {
                int to = g[v][i];
                if (matching[to] == -1 || TryKuhn(matching[to], g, matching, used))
                {
                    matching[to] = v;
                    return true;
                }
            }
            return false;
        }

        public static int[] BuildMaxMatching(List<int>[] g)
        {
            // http://e-maxx.ru/algo/kuhn_matching

            int[] matching = new int[g.Length];
            for (int i = 0; i < g.Length; i++)
                matching[i] = -1;

            bool[] used1 = new bool[g.Length];
            bool[] used = new bool[g.Length];

            for (int i = 0; i < g.Length; ++i)
                for (int j = 0; j < g[i].Count; j++)
                    if (matching[g[i][j]] == -1)
                    {
                        matching[g[i][j]] = i;
                        used1[i] = true;
                        break;
                    }

            for (int i = 0; i < g.Length; ++i)
            {
                if (used1[i]) continue;
                Array.Clear(used, 0, used.Length);
                TryKuhn(i, g, matching, used);
            }

            return matching;
        }
    }

    private static List<int>[] ReadGraph(int n, int m)
    {
        List<int>[] g = new List<int>[n + 1];
        for (int i = 0; i <= n; i++) g[i] = new List<int>();
        for (int i = 0; i < m; i++)
        {
            int a = ReadInt() - 1;
            int b = ReadInt() - 1;

            g[a].Add(b);
            g[b].Add(a);
        }

        return g;
    }

    private static int[,] ReadGraphAsMatrix(int n, int m)
    {
        int[,] matrix = new int[n + 1, n + 1];
        for (int i = 0; i < m; i++)
        {
            int a = ReadInt();
            int b = ReadInt();
            matrix[a, b] = matrix[b, a] = 1;
        }

        return matrix;
    }

    private static void Sort(ref int a, ref int b)
    {
        if (a > b) Swap(ref a, ref b);
    }

    private static void Swap(ref int a, ref int b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    private const int BufferSize = 1 << 12;
    private static StreamReader consoleReader;
    private static MemoryStream testData;

    private static int ReadInt()
    {
        int ans = 0;
        int mul = 1;
        do
        {
            ans = consoleReader.Read();
            if (ans == -1)
                return 0;
            if (ans == '-') mul = -1;
        } while (ans < '0' || ans > '9');

        ans -= '0';
        while (true)
        {
            int chr = consoleReader.Read();
            if (chr < '0' || chr > '9')
                return ans * mul;
            ans = ans * 10 + chr - '0';
        }
    }

    private static ulong ReadULong()
    {
        ulong ans = 0;
        int chr;
        do
        {
            chr = consoleReader.Read();
            if (chr == -1)
                return 0;
        } while (chr < '0' || chr > '9');

        ans = (uint)(chr - '0');
        while (true)
        {
            chr = consoleReader.Read();
            if (chr < '0' || chr > '9')
                return ans;
            ans = ans * 10 + (uint)(chr - '0');
        }
    }

    private static long ReadLong()
    {
        long ans = 0;
        int mul = 1;
        do
        {
            ans = consoleReader.Read();
            if (ans == -1)
                return 0;
            if (ans == '-') mul = -1;
        } while (ans < '0' || ans > '9');

        ans -= '0';
        while (true)
        {
            int chr = consoleReader.Read();
            if (chr < '0' || chr > '9')
                return ans * mul;
            ans = ans * 10 + chr - '0';
        }
    }

    private static int[] ReadIntArray(int n)
    {
        int[] ans = new int[n];
        for (int i = 0; i < n; i++)
            ans[i] = ReadInt();
        return ans;
    }

    private static long[] ReadLongArray(int n)
    {
        long[] ans = new long[n];
        for (int i = 0; i < n; i++)
            ans[i] = ReadLong();
        return ans;
    }

    private static char[] ReadString()
    {
        int ans;

        do
        {
            ans = consoleReader.Read();
        } while (!((ans >= 'a' && ans <= 'z') || (ans >= 'A' && ans <= 'Z')));

        List<char> s = new List<char>();
        do
        {
            s.Add((char)ans);
            ans = consoleReader.Read();
        } while ((ans >= 'a' && ans <= 'z') || (ans >= 'A' && ans <= 'Z'));

        return s.ToArray();
    }

    private static char[] ReadString(int n)
    {
        int ans;

        do
        {
            ans = consoleReader.Read();
        } while (!((ans >= 'a' && ans <= 'z') || (ans >= 'A' && ans <= 'Z')));

        char[] s = new char[n];
        int pos = 0;
        do
        {
            s[pos++] = (char)ans;
            if (pos == n) break;
            ans = consoleReader.Read();
        } while ((ans >= 'a' && ans <= 'z') || (ans >= 'A' && ans <= 'Z'));

        return s;
    }

    private static char ReadLetter()
    {
        while (true)
        {
            int ans = consoleReader.Read();
            if ((ans >= 'a' && ans <= 'z') || (ans >= 'A' && ans <= 'Z'))
                return (char)ans;
        }
    }

    private static char ReadDigit()
    {
        while (true)
        {
            int ans = consoleReader.Read();
            if (ans >= '0' && ans <= '9')
                return (char)ans;
        }
    }

    private static int ReadDigitInt()
    {
        return ReadDigit() - (int)'0';
    }

    private static char ReadAnyChar()
    {
        return (char)consoleReader.Read();
    }

    private static string DoubleToString(double x)
    {
        return x.ToString(System.Globalization.CultureInfo.InvariantCulture);
    }

    static Program()
    {
        //Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        consoleReader = new StreamReader(Console.OpenStandardInput(BufferSize), Encoding.ASCII, false, BufferSize);
    }

    private static void PushTestData(string data)
    {
#if !ONLINE_JUDGE
        if (testData == null)
        {
            testData = new MemoryStream();
            consoleReader = new StreamReader(testData);
        }

        var pos = testData.Position;
        var bytes = Encoding.UTF8.GetBytes(data);
        testData.Write(bytes, 0, bytes.Length);
        testData.Flush();
        testData.Position = pos;
#endif
    }
}