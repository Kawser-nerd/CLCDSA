using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

class Program
{
    public class Item
    {
        public int X, Y;
        public char Tp;

        public override string ToString()
        {
            return this.Tp + " " + (this.X + 1) + " " + (this.Y + 1);
        }
    }

    public class MaxFlow
    {
        public int n;
        public int[,] map;

        public MaxFlow(int[,] map, int n)
        {
            this.n = n;
            this.map = map;
        }

        private int PushFlow(int s, int e)
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

        public int GetMaxFlow(int from, int to)
        {
            int flow = 0;
            while (true)
            {
                int delta = PushFlow(from, to);
                if (delta == 0) break;
                flow += delta;
            }

            return flow;
        }
    }


    private static void Go()
    {
        var n = RI();
        var m = RI();

        var x = new List<Item>();
        var p = new List<Item>();

        var extraX = new List<Item>();
        var extraP = new List<Item>();

        for (int i = 0; i < m; i++)
        {
            var newItem = new Item();
            newItem.Tp = ReadAnyOf(new char[] { 'x', '+', 'o' });
            newItem.X = RI() - 1;
            newItem.Y = RI() - 1;

            if (newItem.Tp == 'x' || newItem.Tp == 'o') x.Add(newItem);
            if (newItem.Tp == '+' || newItem.Tp == 'o') p.Add(newItem);
        }

        var xx = Enumerable.Range(0, n).Except(x.Select(xxx => xxx.X)).ToList();
        var yy = Enumerable.Range(0, n).Except(x.Select(xxx => xxx.Y)).ToList();
        for (int i = 0; i < xx.Count; i++)
            extraX.Add(new Item() { X = xx[i], Y = yy[i], Tp = 'x' });

        // 0 - root
        // 1 - N+N-1 > D1
        // N+N - N+N+N+N-1 > D
        // 4N > exist.

        var d1 = new bool[n + n - 1];// x+y
        var d2 = new bool[n + n - 1]; // x-y+n-1
        foreach (var t in p)
        {
            d1[t.X + t.Y] = true;
            d2[t.X - t.Y + n - 1] = true;
        }

        var nn = 4 * n + 1;

        var map = new int[nn, nn];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!d1[i + j] && !d2[i - j + n - 1])
                {
                    var d1Id = i + j;
                    var d2Id = i - j + n - 1;

                    var v1 = 1 + d1Id;
                    var v2 = n + n + d2Id;

                    map[0, v1] = 1;
                    map[v1, v2] = 1;
                    map[v2, nn - 1] = 1;
                }

        var flow = new MaxFlow(map, nn);
        var maxFlow = flow.GetMaxFlow(0, nn - 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!d1[i + j] && !d2[i - j + n - 1])
                {
                    var d1Id = i + j;
                    var d2Id = i - j + n - 1;

                    var v1 = 1 + d1Id;
                    var v2 = n + n + d2Id;

                    if (map[v1, v2] == 0)
                    {
                        extraP.Add(new Item() { X = i, Y = j, Tp = '+' });
                    }
                }

        var q1 = new char[n, n];
        foreach (var t in x) q1[t.X, t.Y] = t.Tp;
        foreach (var t in p) q1[t.X, t.Y] = t.Tp;

        var q2 = (char[,])(q1.Clone());
        foreach (var t in extraX)
        {
            if (q2[t.X, t.Y] == '+') t.Tp = 'o';
            q2[t.X, t.Y] = t.Tp;
        }

        foreach (var t in extraP)
        {
            if (q2[t.X, t.Y] == 'x') t.Tp = 'o';
            q2[t.X, t.Y] = t.Tp;
        }

        var result = new List<Item>();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (q1[i, j] != q2[i, j])
                    result.Add(new Item() { X = i, Y = j, Tp = q2[i, j] });

                var sb = new StringBuilder();

        var max = x.Count + p.Count + extraX.Count + extraP.Count;
        sb.Append(max + " " + result.Count);
        foreach (var t in result)
        {
            sb.AppendLine();
            sb.Append(t.ToString());
        }

        SetAnswer(sb.ToString());
    }

    private static void SetAnswer(string s)
    {
        answer.AppendFormat("Case #{0}: {1}", testId, s);
        answer.AppendLine();
    }

    private static StringBuilder answer = new StringBuilder();
    private static int testId;
    private static void Main(string[] args)
    {
        var path = @"C:\Users\v-sers\Downloads\D-large.in";
        var outputFile = path.Replace(".in", ".out");
        var data = File.ReadAllText(path);
        PushTestData(data);

        var t = RI();
        for (testId = 1; testId <= t; testId++)
            Go();

        File.WriteAllText(outputFile, answer.ToString());

        File.Copy(@"..\..\..\Program.cs", @"C:\Users\v-sers\Downloads\Program.cs", true);

        Console.WriteLine(answer.ToString());

    }

    private const int Mod = 1000000000 + 7;

    #region Data Read
    private static char ReadSign()
    {
        while (true)
        {
            int ans = consoleReader.Read();
            if (ans == '+' || ans == '-' || ans == '?')
                return (char)ans;
        }
    }

    private static long GCD(long a, long b)
    {
        if (a % b == 0) return b;
        return GCD(b, a % b);
    }

    private static List<int>[] ReadGraph(int n, int m)
    {
        List<int>[] g = new List<int>[n];
        for (int i = 0; i < g.Length; i++) g[i] = new List<int>();
        for (int i = 0; i < m; i++)
        {
            int a = RI() - 1;
            int b = RI() - 1;

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
            int a = RI();
            int b = RI();
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

    private const int BufferSize = 1 << 16;
    private static StreamReader consoleReader;
    private static MemoryStream testData;

    private static int RI()
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

    private static ulong RUL()
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

    private static long RL()
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

    private static int[] RIA(int n)
    {
        int[] ans = new int[n];
        for (int i = 0; i < n; i++)
            ans[i] = RI();
        return ans;
    }

    private static long[] RLA(int n)
    {
        long[] ans = new long[n];
        for (int i = 0; i < n; i++)
            ans[i] = RL();
        return ans;
    }

    private static char[] ReadWord()
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

    private static char[] ReadStringLine()
    {
        int ans;

        do
        {
            ans = consoleReader.Read();
        } while (ans == 10 || ans == 13);

        List<char> s = new List<char>();

        do
        {
            s.Add((char)ans);
            ans = consoleReader.Read();
        } while (ans != 10 && ans != 13 && ans != -1);

        return s.ToArray();
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
    private static char ReadNonLetter()
    {
        while (true)
        {
            int ans = consoleReader.Read();
            if (!((ans >= 'a' && ans <= 'z') || (ans >= 'A' && ans <= 'Z')))
                return (char)ans;
        }
    }

    private static char ReadAnyOf(IEnumerable<char> allowed)
    {
        while (true)
        {
            char ans = (char)consoleReader.Read();
            if (allowed.Contains(ans))
                return ans;
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
        return x.ToString(CultureInfo.InvariantCulture);
    }

    private static double DoubleFromString(string x)
    {
        return double.Parse(x, CultureInfo.InvariantCulture);
    }

    static Program()
    {
        //Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        consoleReader = new StreamReader(Console.OpenStandardInput(BufferSize), Encoding.ASCII, false, BufferSize);
    }

    private static void PushTestData(StringBuilder sb)
    {
        PushTestData(sb.ToString());
    }
    private static void PushTestData(string data)
    {
#if TOLYAN_TEST
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
    #endregion
}