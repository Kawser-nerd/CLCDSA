using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

class Program
{
    public class MaxMatching
    {
        private List<int>[] g;
        private int n;
        private int m;
        private int[] matching;
        private bool[] used;

        private MaxMatching(List<int>[] g, int n, int m)
        {
            this.g = g;
            this.n = n;
            this.m = m;

            this.matching = new int[m];
            for (int i = 0; i < m; i++)
                this.matching[i] = -1;

            bool[] used1 = new bool[n];
            this.used = new bool[n];

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < g[i].Count; j++)
                    if (this.matching[g[i][j]] == -1)
                    {
                        this.matching[g[i][j]] = i;
                        used1[i] = true;
                        break;
                    }

            for (int i = 0; i < n; ++i)
            {
                if (used1[i]) continue;
                Array.Clear(this.used, 0, used.Length);
                TryKuhn(i);
            }
        }

        private bool TryKuhn(int v)
        {
            if (this.used[v]) return false;
            this.used[v] = true;

            for (int i = 0; i < g[v].Count; i++)
            {
                int to = g[v][i];
                if (this.matching[to] == -1 || TryKuhn(this.matching[to]))
                {
                    this.matching[to] = v;
                    return true;
                }
            }
            return false;
        }

        public static int[] BuildMaxMatching(List<int>[] g, int n, int m)
        {
            // http://e-maxx.ru/algo/kuhn_matching
            return new MaxMatching(g, n, m).matching;
        }
    }

    private static void SolveB()
    {
        int n = RI();
        int c = RI();
        var m = RI();

        var c1 = new List<int>();
        var c2 = new List<int>();

        for (int i = 0; i < m; i++)
        {
            var p = RI();
            var b = RI();

            if (b == 1) c1.Add(p);
            if (b == 2) c2.Add(p);
        }

        c1.Sort();
        c2.Sort();

        var t1 = new int[n + 1];
        var t2 = new int[n + 1];
        foreach (var cc in c1) t1[cc]++;
        foreach (var cc in c2) t2[cc]++;

        var answer1 = Math.Max(c1.Count, c2.Count);
        answer1 = Math.Max(answer1, c1.Count(cc => cc == 1) + c2.Count(cc => cc == 1));
        var answer2 = 0;

        if (answer1 < c1.Count && answer1 < c2.Count)
        {
            SetAnswer(answer1.ToString() + " " + answer2.ToString());
            return;
        }

        for (int i = 0; i <= n; i++)
            if (t1[i] + t2[i] > answer1)
            {
                answer2 = Math.Max(answer2, t1[i] + t2[i] - answer1);
            }

        SetAnswer(answer1.ToString() + " " + answer2.ToString());
    }

    private static bool IsBlaster(char ch)
    {
        return (ch == '-' || ch == '|' || ch == '+');
    }

    private static bool Has(int i, int j, int di, int dj, int x, int y, char[][] map)
    {
        i += di;
        j += dj;

        while (i < x && j < y && i >= 0 && j >= 0)
        {
            if (IsBlaster(map[j][i]))
                return true;

            if (map[j][i] == '#')
                return false;

            i += di;
            j += dj;
        }

        return false;
    }

    private static char Get(int i, int j, int di, int dj, int x, int y, char[][] map)
    {
        i += di;
        j += dj;
        while (i < x && j < y && i >= 0 && j >= 0)
        {
            if (IsBlaster(map[j][i]))
                return map[j][i];

            if (map[j][i] == '#')
                return '#';
            i += di;
            j += dj;
        }

        return '#';
    }

    private static void Update(int i, int j, int di, int dj, int x, int y, char[][] map, char set)
    {
        i += di;
        j += dj;
        while (i < x && j < y && i >= 0 && j >= 0)
        {
            if (IsBlaster(map[j][i]))
            {
                map[j][i] = set;
                return;
            }

            if (map[j][i] == '#')
                return;
            i += di;
            j += dj;
        }
    }

    private static bool Optimize(char[][] map, int x, int y)
    {
        bool updated = true;
        while (updated)
        {
            updated = false;

            for (int i = 0; i < x; i++)
                for (int j = 0; j < y; j++)
                    if (map[j][i] == '.')
                    {
                        var hasUp = Get(i, j, 0, -1, x, y, map);
                        var hasDown = Get(i, j, 0, 1, x, y, map);
                        var hasLeft = Get(i, j, -1, 0, x, y, map);
                        var hasRight = Get(i, j, 1, 0, x, y, map);

                        var coveredUp = (hasUp == '|');
                        var coveredDown = (hasDown == '|');
                        var coveredLeft = (hasLeft == '-');
                        var coveredRight = (hasRight == '-');

                        if (!coveredUp && !coveredDown && !coveredLeft && !coveredRight)
                        {
                            int cnt = 0;
                            if (hasUp == '+') cnt++;
                            if (hasDown == '+') cnt++;
                            if (hasLeft == '+') cnt++;
                            if (hasRight == '+') cnt++;

                            if (cnt == 0)
                            {
                                //SetAnswer("IMPOSSIBLE");
                                return false;
                            }

                            if (cnt == 1)
                            {
                                if (hasUp == '+') Update(i, j, 0, -1, x, y, map, '|');
                                if (hasDown == '+') Update(i, j, 0, 1, x, y, map, '|');
                                if (hasLeft == '+') Update(i, j, -1, 0, x, y, map, '-');
                                if (hasRight == '+') Update(i, j, 1, 0, x, y, map, '-');
                                updated = true;
                            }
                        }
                    }


            for (int i = 0; i < x; i++)
                for (int j = 0; j < y; j++)
                    if (map[j][i] == '+')
                    {
                        int h = 0;
                        if (i > 0 && map[j][i - 1] == '.') h++;
                        if (i+1 < x && map[j][i + 1] == '.') h++;

                        int v = 0;
                        if (j > 0 && map[j - 1][i] == '.') v++;
                        if (j+1 < y && map[j + 1][i] == '.') v++;

                        if (v == 0)
                        {
                            map[j][i] = '-';
                            updated = true;
                        }

                        if (h == 0)
                        {
                            map[j][i] = '|';
                            updated = true;
                        }
                    }
        }

        return true;
    }

    private static bool IsLast(char[][] map, int x, int y)
    {
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (map[j][i] == '+')
                    return false;

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
            {
                if (map[j][i] == '.')
                {
                    var correct = false;
                    correct |= (Get(i, j, 0, -1, x, y, map) == '|');
                    correct |= (Get(i, j, 0, 1, x, y, map) == '|');
                    correct |= (Get(i, j, 1, 0, x, y, map) == '-');
                    correct |= (Get(i, j, -1, 0, x, y, map) == '-');

                    if (!correct) return false;
                }
            }

        return true;
    }


    private static char[][] Clone(char[][] map, int x, int y)
    {
        var copy = new char[y][];
        for (int j = 0; j < y; j++)
        {
            copy[j] = new char[x];
            for (int i = 0; i < x; i++)
                copy[j][i] = map[j][i];
        }

        return copy;
    }

    private static char[][] Search(char[][] map, int x, int y)
    {
        var copy = Clone(map, x, y);

        if (IsLast(copy, x, y)) return copy;

        if (!Optimize(copy, x, y))
            return null;

        var optimizedCopy = Clone(copy, x, y);
        /*Console.WriteLine(ToString(optimizedCopy, x, y));
        Console.WriteLine();
        */
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (optimizedCopy[j][i] == '+')
                {
                    var copy2 = Clone(optimizedCopy, x, y);
                    copy2[j][i] = '|';

                    var ans = Search(copy2, x, y);
                    if (ans != null) return ans;

                    copy2[j][i] = '-';
                    ans = Search(copy2, x, y);
                    return ans;
                }

        return optimizedCopy;
    }

    private static void SolveC()
    {

        int y = RI();
        int x = RI();
        var map = new char[y][];
        for (int i = 0; i < y; i++) map[i] = ReadStringLine();
        /*Console.WriteLine(testId);
        Console.WriteLine(ToString(map, x, y));
        */

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (IsBlaster(map[j][i]))
                {
                    var hasUp = Has(i, j, 0, -1, x, y, map);
                    var hasDown = Has(i, j, 0, 1, x, y, map);
                    var hasLeft = Has(i, j, -1, 0, x, y, map);
                    var hasRight = Has(i, j, 1, 0, x, y, map);

                    var hasV = (hasUp | hasDown);
                    var hasH = (hasLeft | hasRight);

                    if (hasV && hasH)
                    {
                        SetAnswer("IMPOSSIBLE");
                        return;
                    }

                    if (!hasV && !hasH) map[j][i] = '+';
                    if (hasV && !hasH) map[j][i] = '-';
                    if (!hasV && hasH) map[j][i] = '|';
                }

        if (!Optimize(map, x, y))
        {
            SetAnswer("IMPOSSIBLE");
            return;
        }

        var ans = Search(map, x, y);
        if (ans == null)
        {
            SetAnswer("IMPOSSIBLE");
            return;
        }

        var sb = new StringBuilder();
        sb.AppendLine("POSSIBLE");
        sb.Append(ToString(ans, x, y));

        SetAnswer(sb.ToString());
    }

    private static string ToString(char[][] map, int x, int y)
    {
        var sb = new StringBuilder();
        for (int j = 0; j < y; j++)
        {
            sb.Append(new string(map[j]));
            if (j + 1 < y)
                sb.AppendLine();
        }

        return sb.ToString();
    }

    private static void Go()
    {
        SolveC();
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
        var path = @"C:\Users\v-sers\Downloads\C-small-attempt1.in";
        var outputFile = path.Replace(".in", ".out");
        var data = File.ReadAllText(path);
        /*
        data = @"

3
1 3
-.-
3 4
#.##
#--#
####
2 2
-.
#|
";

        */
        PushTestData(data);


        var t = RI();
        for (testId = 1; testId <= t; testId++)
            Go();

        File.WriteAllText(outputFile, answer.ToString());

        File.Copy(@"..\..\..\Program.cs", @"C:\Users\v-sers\Downloads\!Program.cs", true);

        Console.WriteLine(answer.ToString());
    }

    private const int Mod = 1000000000 + 7;

    #region Data Read

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