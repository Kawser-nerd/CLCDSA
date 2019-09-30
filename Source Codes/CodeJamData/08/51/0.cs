#region Template code
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Globalization;

class Program
{
    static void Main(string[] args)
    {
        System.Threading.Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        Solution sol = new Solution();
        sol.go();
    }
}

partial class Solution
{
    #region I/O
    protected TextReader input = null;
    protected TextWriter output = null;

    string[] line;
    int index;
    protected string ReadLine()
    {
        line = null;
        return input.ReadLine();
    }

    protected int ReadLine_int()
    {
        line = null;
        return Convert.ToInt32(input.ReadLine());
    }

    protected string[] SplitLine()
    {
        index = 0;
        return line = input.ReadLine().Split();
    }

    protected List<int> SplitLine_int()
    {
        index = 0;
        line = input.ReadLine().Split();

        List<int> result = new List<int>();
        foreach (string s in line)
        {
            result.Add(Convert.ToInt32(s));
        }
        return result;
    }

    protected string GetString()
    {
        return line[index++];
    }

    protected int GetInt()
    {
        return Convert.ToInt32(line[index++]);
    }

    protected long GetLong()
    {
        return Convert.ToInt64(line[index++]);
    }

    protected double GetDouble()
    {
        return Convert.ToDouble(line[index++], CultureInfo.InvariantCulture);
    }

    protected void Write(string s)
    {
        output.Write(s);
        Console.Out.Write(s);
    }

    protected void Write(string format, params object[] ss)
    {
        output.Write(format, ss);
        Console.Out.Write(format, ss);
    }

    protected void WriteLine()
    {
        output.WriteLine();
        Console.Out.WriteLine();
    }

    protected void WriteLine(string s)
    {
        output.WriteLine(s);
        Console.Out.WriteLine(s);
    }

    protected void WriteLine(string format, params object[] ss)
    {
        output.WriteLine(format, ss);
        Console.Out.WriteLine(format, ss);

    }

    #endregion

    static string hex(int x)
    {
        return String.Format("{0:x}", x);
    }

    public void go()
    {
        Environment.CurrentDirectory = "../..";
        input = File.OpenText(name + ".in");
        output = File.CreateText(name + ".out");
        int N = ReadLine_int();
        for (cas = 1; cas <= N; cas++)
        {
            Solve();
        }

        output.Close();
        input.Close();
        Console.In.ReadLine();
    }
    int cas = -1;
}
#endregion

partial class Solution
{
    const string name = "A-large";

    void Solve()
    {
        int L = ReadLine_int();
        SplitLine();
        int x = 3010;
        int y = 3010;
        int dir = 1;
        int area = 0;
        int[] minx = new int[6020]; for (int i = 0; i < 6020; i++) minx[i] = 1000000;
        int[] maxx = new int[6020]; for (int i = 0; i < 6020; i++) maxx[i] = -1;
        int[] miny = new int[6020]; for (int i = 0; i < 6020; i++) miny[i] = 1000000;
        int[] maxy = new int[6020]; for (int i = 0; i < 6020; i++) maxy[i] = -1;
        for (int i = 0; i < L; i++)
        {
            if (index >= line.Length) SplitLine();
            string S = GetString();
            int T = GetInt();
            for (int j = 0; j < T; j++)
            {
                foreach (char c in S)
                {
                    if (c == 'L') { dir = (dir + 1) % 4; continue; }
                    if (c == 'R') { dir = (dir + 3) % 4; continue; }
                    switch (dir)
                    {
                        case 0:
                            area += -y;
                            if (y < miny[x]) miny[x] = y;
                            if (y > maxy[x]) maxy[x] = y;
                            x += 1;
                            break;
                        case 1:
                            area += x;
                            if (x < minx[y]) minx[y] = x;
                            if (x > maxx[y]) maxx[y] = x;
                            y += 1;
                            break;
                        case 2:
                            area += y;
                            if (y < miny[x - 1]) miny[x - 1] = y;
                            if (y > maxy[x - 1]) maxy[x - 1] = y;
                            x -= 1;
                            break;
                        case 3:
                            area += -x;
                            if (x < minx[y - 1]) minx[y - 1] = x;
                            if (x > maxx[y - 1]) maxx[y - 1] = x;
                            y -= 1;
                            break;
                    }
                }
            }

        }
        area = Math.Abs(area) / 2;
        int area2 = 0;
        byte[,] map = new byte[6020, 6020];
        {
            for (int xx = 0; xx < 6020; xx++)
            {
                if (maxy[xx] > 0)
                {
                    int y1 = miny[xx]; int y2 = maxy[xx];
                    for (int yy = y1; yy < y2; yy++)
                    {
                        map[xx, yy] = 1;
                    }
                }
            }
            for (int yy = 0; yy < 6020; yy++)
            {
                if (maxx[yy] > 0)
                {
                    int x1 = minx[yy]; int x2 = maxx[yy];
                    for (int xx = x1; xx < x2; xx++)
                    {
                        map[xx, yy] = 1;
                    }
                }
            }
            for (int xx = 0; xx < 6020; xx++)
            {
                for (int yy = 0; yy < 6020; yy++)
                {
                    area2 += map[xx, yy];
                }
            }
        }
        WriteLine("Case #{0}: {1}", cas, area2 - area);
    }


}

