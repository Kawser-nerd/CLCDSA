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
    const string name = "B-large";

    struct state
    {
        public int me, port1, port2, count;
        public state(int m, int p1, int p2, int c)
        {
            me = m; port1 = p1; port2 = p2; count=c;
        }
    }
    void Solve()
    {
        SplitLine();
        int R = GetInt();
        int C = GetInt();
        string[] map = new string[R];
        int myx=-1, myy=-1;
        int cakex=-1, cakey=-1;
        for (int i = 0; i < R; i++)
        {
            map[i] = ReadLine();
            if (map[i].Contains("O")) { myx = map[i].IndexOf('O'); myy = i; }
            if (map[i].Contains("X")) { cakex = map[i].IndexOf('X'); cakey = i; }
        }
        int cake = cakex + 15 * cakey;
        bool[, ,] visit = new bool[225, 226, 226];
        Queue<state> q1 = new Queue<state>();
        Queue<state> q2 = new Queue<state>();
        q1.Enqueue(new state(myx + 15 * myy, 225, 225, 0));
        visit[myx+15*myy, 225, 225] = true;
        while (q1.Count > 0 || q2.Count>0)
        {
            if (q1.Count == 0) { q1 = q2; q2 = new Queue<state>(); }
            state s = q1.Dequeue();
            int x = s.me % 15;
            int y = s.me / 15;
            if (s.me == 47)
            {
            }
            if (x == cakex && y == cakey)
            {
                WriteLine("Case #{0}: {1}", cas, s.count);
                return;
            }
            if (s.me == s.port1 && s.port2!=225)
            {
                state s2 = s;
                s2.me = s.port2;
                s2.count += 1;
                if (s2.me == cake)
                {
                    WriteLine("Case #{0}: {1}", cas, s2.count);
                    return;
                }
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q2.Enqueue(s2);
                }
            }
            if (s.me == s.port2 && s.port1 != 225)
            {
                state s2 = s;
                s2.me = s.port1;
                s2.count += 1;
                if (s2.me == cake)
                {
                    WriteLine("Case #{0}: {1}", cas, s2.count);
                    return;
                }
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q2.Enqueue(s2);
                }
            }
            if (x < C - 1 && map[y][x+1] != '#')
            {
                state s2 = s;
                s2.me += 1;
                s2.count += 1;
                if (s2.me == cake)
                {
                    WriteLine("Case #{0}: {1}", cas, s2.count);
                    return;
                }
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q2.Enqueue(s2);
                }
            }
            if (x >0 && map[y][x - 1] != '#')
            {
                state s2 = s;
                s2.me -= 1;
                s2.count += 1;
                if (s2.me == cake)
                {
                    WriteLine("Case #{0}: {1}", cas, s2.count);
                    return;
                }
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q2.Enqueue(s2);
                }
            }
            if (y < R - 1 && map[y+1][x] != '#')
            {
                state s2 = s;
                s2.me += 15;
                s2.count += 1;
                if (s2.me == cake)
                {
                    WriteLine("Case #{0}: {1}", cas, s2.count);
                    return;
                }
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q2.Enqueue(s2);
                }
            }
            if (y > 0 && map[y-1][x] != '#')
            {
                state s2 = s;
                s2.me -= 15;
                s2.count += 1;
                if (s2.me == cake)
                {
                    WriteLine("Case #{0}: {1}", cas, s2.count);
                    return;
                }
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q2.Enqueue(s2);
                }
            }
            int[] newport = new int[4];
            int nx = x, ny = y;
            while (nx < C && map[ny][nx] != '#') nx += 1;
            nx -= 1;
            newport[0] = nx + 15 * ny;

            nx = x; ny = y;
            while (nx >=0 && map[ny][nx] != '#') nx -= 1;
            nx += 1;
            newport[1] = nx + 15 * ny;

            nx = x; ny = y;
            while (ny < R && map[ny][nx] != '#') ny += 1;
            ny -= 1;
            newport[2] = nx + 15 * ny;

            nx = x; ny = y;
            while (ny >= 0 && map[ny][nx] != '#') ny -= 1;
            ny += 1;
            newport[3] = nx + 15 * ny;

            for (int i = 0; i < 4; i++)
            {
                state s2 = s;
                s2.port1 = newport[i];
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q1.Enqueue(s2);
                }
                s2 = s;
                s2.port2 = newport[i];
                if (!visit[s2.me, s2.port1, s2.port2])
                {
                    visit[s2.me, s2.port1, s2.port2] = true;
                    q1.Enqueue(s2);
                }

            }
        }
        WriteLine("Case #{0}: THE CAKE IS A LIE", cas);

    }


}

