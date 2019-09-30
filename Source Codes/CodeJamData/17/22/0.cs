using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

class Program
{

    public class Queue : IComparable<Queue>
    {
        public char Name;
        public List<string> Items;

        public int Count
        {
            get { return this.Items.Count; }
        }


        public string DropOne()
        {
            var ans = this.Items.Last();
            this.Items.RemoveAt(this.Items.Count - 1);

            return ans;
        }

        public int CompareTo(Queue other)
        {
            return this.Items.Count.CompareTo(other.Items.Count);
        }
    }


    private static string GetChain(int n, char a, char mid)
    {
        var sb = new StringBuilder();

        if (n > 0)
        {
            sb.Append(a);
            for (int i = 0; i < n; i++)
            {
                sb.Append(mid);
                sb.Append(a);
            }
        }

        return sb.ToString();
    }

    private static void Go()
    {
        /*
            A mane with red and yellow hairs appears orange.
            A mane with yellow and blue hairs appears green.
            A mane with red and blue hairs appears violet.
         */
        //R, O, Y, G, B, V
        int n = RI();

        var m = RIA(6);

        var r = m[0];
        var o = m[1];
        var y = m[2];
        var g = m[3];
        var b = m[4];
        var v = m[5];

        var sb = new StringBuilder();
        if (o > 0 && o == b)
        {
            if (n > o + b)
            {
                sb.Append("IMPOSSIBLE");
            }
            else
            {
                for (int i = 0; i < o; i++)
                    sb.Append("OB");
            }

            SetAnswer(sb.ToString());
            return;
        }

        if (g > 0 && g == r)
        {
            if (n > g + r)
            {
                sb.Append("IMPOSSIBLE");
            }
            else
            {
                for (int i = 0; i < g; i++)
                    sb.Append("GR");
            }

            SetAnswer(sb.ToString());
            return;
        }

        if (v > 0 && v == y)
        {
            if (n > v + y)
            {
                sb.Append("IMPOSSIBLE");
            }
            else
            {
                for (int i = 0; i < v; i++)
                    sb.Append("VY");
            }

            SetAnswer(sb.ToString());
            return;
        }

        if ((o > 0 && o > b) || (g > 0 && g > r) || (v > 0 && v > y))
        {
            SetAnswer("IMPOSSIBLE");
            return;
        }

        var c1 = GetChain(o, 'B', 'O');
        var c2 = GetChain(g, 'R', 'G');
        var c3 = GetChain(v, 'Y', 'V');

        var bb = new List<string>();
        var rr = new List<string>();
        var yy = new List<string>();

        if (c1.Length > 0) bb.Add(c1);
        if (c2.Length > 0) rr.Add(c2);
        if (c3.Length > 0) yy.Add(c3);

        if (o > 0) b -= (o + 1);
        if (g > 0) r -= (g + 1);
        if (v > 0) y -= (v + 1);

        while (b-- > 0) bb.Add("B");
        while (r-- > 0) rr.Add("R");
        while (y-- > 0) yy.Add("Y");


        var q1 = new Queue() { Name = 'B', Items = bb };
        var q2 = new Queue() { Name = 'R', Items = rr };
        var q3 = new Queue() { Name = 'Y', Items = yy };

        var q = new List<Queue>() { q1, q2, q3 };

        q.Sort();
        q.Reverse();

        if (q[0].Items.Count > q[1].Items.Count + q[2].Items.Count)
        {
            SetAnswer("IMPOSSIBLE");
            return;
        }

        var fullAnswer = new List<string>();
        while (q[0].Count > 1)
        {
            fullAnswer.Add(q[0].DropOne());

            if (q[1].Count > q[2].Count)
            {
                fullAnswer.Add(q[1].DropOne());
            }
            else
            {
                fullAnswer.Add(q[2].DropOne());
            }
        }

        fullAnswer.Add(q[0].DropOne());
        if (q[1].Count > 1 + q[2].Count)
        {
            SetAnswer("IMPOSSIBLE");
            return;
        }

        while (q[1].Count > 0)
        {
            fullAnswer.Add(q[1].DropOne());

            if (q[2].Count > 0)
            {
                fullAnswer.Add(q[2].DropOne());
            }
        }

        SetAnswer(string.Join("", fullAnswer));
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
        var path = @"C:\Users\v-sers\Downloads\B-small-attempt0.in";
        path = @"C:\Users\v-sers\Downloads\B-Large.in";
        var outputFile = path.Replace(".in", ".out");
        var data = File.ReadAllText(path);

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