using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Data;
using System.Numerics;

struct Point
{
    public int pos;
    public int type;
    public int pop;
    public Point(int pos, int type, int pop)
    {
        this.pos = pos;
        this.type = type;
        this.pop = pop;
    }    
}

class GCJ
{
    StreamReader sr = new StreamReader("A-large.in");
    StreamWriter sw = new StreamWriter("output.txt");
    char[] splitors = { ' ' };
    int N, M;
    Point[] p;
    Int64 mod = 1000002013;

    public Int64 Cost(int s, int t, int num)
    {
        if (s == t)
            return 0;
        Int64 dis = t - s;
        dis = ((dis + 1) * dis) / 2;
        dis %= mod;
        Int64 ans = t - s;
        ans *= N + 1;
        ans -= dis;
        ans %= mod;
        ans *= num;
        ans %= mod;
        return ans;
    }

    public Int64 Search()
    {
        int n = M * 2;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                if (p[i].pos < p[j].pos)
                    continue;
                else if (p[i].pos == p[j].pos && p[i].type < p[j].type)
                    continue;
                else
                {
                    Point temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }

        Int64 ret = 0;
        Stack<int> pos = new Stack<int>();
        Stack<int> pop = new Stack<int>();

        for (int i = 0; i < n; i++)
        {
            if (p[i].type == 0)
            {
                pos.Push(p[i].pos);
                pop.Push(p[i].pop);
            }
            else
            {
                int out_pos = p[i].pos;
                int out_pop = p[i].pop;
                while (true)
                {
                    int in_pos = pos.Pop();
                    int in_pop = pop.Pop();
                    if (out_pop <= in_pop)
                    {
                        ret += Cost(in_pos, out_pos, out_pop);
                        ret %= mod;
                        in_pop -= out_pop;
                        if (in_pop > 0)
                        {
                            pos.Push(in_pos);
                            pop.Push(in_pop);
                        }
                        break;
                    }
                    else
                    {
                        ret += Cost(in_pos, out_pos, in_pop);
                        ret %= mod;
                        out_pop -= in_pop;
                    }
                }
            }
        }
        return ret;
    }

    public void Run()
    {
        int testcases = int.Parse(sr.ReadLine());
        for (int i = 1; i <= testcases; i++)
        {
            string[] str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
            N = int.Parse(str[0]);
            M = int.Parse(str[1]);
            p = new Point[M * 2];

            Int64 ret = 0;
            for (int j = 0; j < M; j++)
            {
                str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
                int s = int.Parse(str[0]);
                int t = int.Parse(str[1]);
                int num = int.Parse(str[2]);
                ret += Cost(s, t, num);
                ret %= mod;
                p[j * 2] = new Point(s, 0, num);
                p[j * 2 + 1] = new Point(t, 1, num);
            }
            sw.WriteLine("Case #" + i + ": " + ((ret - Search() + mod) % mod));
            sw.Flush();
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        GCJ program = new GCJ();
        program.Run();
    }
}