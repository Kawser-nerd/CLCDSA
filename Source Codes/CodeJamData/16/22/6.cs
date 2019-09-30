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

    static void Main(string[] args)
    {
        string path = @"C:\Users\Толик\Downloads\B-small-attempt0.in";
        string pathOut = path.Replace(".in", ".out");
        PushTestData(System.IO.File.ReadAllText(path));
        
        /*PushTestData(@"4
1? 2?
?2? ??3
? ?
?5 ?0");*/

        int t = ReadInt();
        var sb = new StringBuilder();

        for (int k = 0; k < t; k++)
        {
            var a = ReadStr();
            var b = ReadStr();

            int s = 10;


            for (int i = 1; i < a.Length; i++) s *= 10;

            long bestDif = long.MaxValue;
            int aa = -1;
            int bb = -1;

            for (int i1 = 0; i1 < s; i1++)
                if (IsMatched(a, i1))
                    for (int i2 = 0; i2 < s; i2++)
                        if (IsMatched(b, i2))
                        {
                            if (bestDif > Math.Abs(i2 - i1))
                            {
                                bestDif = Math.Abs(i2 - i1);
                                aa = i1;
                                bb = i2;
                            }
                        }

            sb.AppendFormat("Case #{0}: {1} {2}", k + 1, ToString(aa, a), ToString(bb, b));
            sb.AppendLine();
        }

        var str = sb.ToString();
        Console.WriteLine(str);
        System.IO.File.WriteAllText(pathOut, str);
        Console.WriteLine(pathOut);
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