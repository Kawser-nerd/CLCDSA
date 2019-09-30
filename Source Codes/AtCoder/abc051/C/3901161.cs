using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    struct P
    {
        public int x;
        public int y;
        public P(int x,int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    static void Main(string[] args)
    {
        var st = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ps = new HashSet<P>();
        var result = "";
        var s = new P(st[0], st[1]);
        var t = new P(st[2], st[3]);
        for(var i = 0; i < 4; i++)
        {
            var isend = false;
            if (i % 2 == 0)
                dfs(ps, st[0], st[1], st[2], st[3], ref isend, ref result,true);
            else
                dfs(ps, st[2], st[3], st[0], st[1], ref isend,ref result,false);
            if (ps.Contains(s))
                ps.Remove(s);
            if (ps.Contains(t))
                ps.Remove(s);
        }
        WriteLine(result);
    }
    private static void dfs(HashSet<P> ps,int x,int y,int gx,int gy,ref bool isEnd,ref string result,bool mode)
    {
        if (x == gx && y == gy) {
            isEnd = true; return;
        }
        if (mode)
        {
            if(x+1<=gx&&!ps.Contains(new P(x + 1, y))&&!isEnd)
            {
                ps.Add(new P(x + 1, y));
                result += "R";
                dfs(ps, x + 1, y, gx, gy, ref isEnd, ref result,mode);
            }
            else if(!isEnd&&ps.Contains(new P(x+1,y))&&ps.Contains(new P(x, y + 1)))
            {
                ps.Add(new P(x, y - 1));
                result += "D";
                dfs(ps, x, y - 1, gx, gy, ref isEnd, ref result,mode);
            }

            if(y+1<=gy&&!ps.Contains(new P(x, y + 1)) && !isEnd){
                ps.Add(new P(x, y + 1));
                result += "U";
                dfs(ps, x, y + 1, gx, gy, ref isEnd, ref result,mode);
            }
            else if(!isEnd&&ps.Contains(new P(x, y + 1)))
            {
                ps.Add(new P(x + 1, y));
                result += "R";
                dfs(ps, x + 1, y, gx, gy, ref isEnd, ref result,mode);
            }
            else if (!isEnd)
            {
                ps.Add(new P(x - 1, y));
                result += "L";
                dfs(ps, x - 1, y, gx, gy, ref isEnd, ref result, mode);
            }
        }
        else
        {
            if(x-1>=gx&&!ps.Contains(new P(x - 1, y)) && !isEnd)
            {
                ps.Add(new P(x - 1, y));
                result += "L";
                dfs(ps, x - 1, y, gx, gy, ref isEnd, ref result,mode);
            }
            else if(!isEnd&&ps.Contains(new P(x-1,y))&&ps.Contains(new P(x, y - 1)))
            {
                ps.Add(new P(x, y + 1));
                result += "U";
                dfs(ps, x, y + 1, gx, gy, ref isEnd, ref result,mode);
            }

            if(y-1>=gy&&!ps.Contains(new P(x, y - 1)) && !isEnd)
            {
                ps.Add(new P(x, y - 1));
                result += "D";
                dfs(ps, x, y - 1, gx, gy, ref isEnd, ref result,mode);
            }else if(!isEnd&&ps.Contains(new P(x, y - 1)))
            {
                ps.Add(new P(x - 1, y));
                result += "L";
                dfs(ps, x - 1, y, gx, gy, ref isEnd, ref result,mode);
            }
            else if (!isEnd)
            {
                ps.Add(new P(x + 1, y));
                result += "R";
                dfs(ps, x + 1, y, gx, gy, ref isEnd, ref result, mode);
            }
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}