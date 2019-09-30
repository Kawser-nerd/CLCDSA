using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    struct P
    {
        public int h;
        public int w;
        public int len;
        public P(int h,int w,int len)
        {
            this.h = h;
            this.w = w;
            this.len = len;
        }
    }
    static void Main(string[] args)
    {
        var hw = Input.ar;
        var gred = new string[hw[0]];
        for (var i = 0; i < hw[0]; i++)
            gred[i] = ReadLine();
        var white = gred.Sum(str => str.Count(c => c == '.'));
        var que = new Queue<P>();
        var bo = new bool[hw[0], hw[1]];
        bo[0, 0] = true;
        que.Enqueue(new P(0, 0, 1));
        var gH = new[] { 0, 0, 1, -1 };
        var gW = new[] { 1, -1, 0, 0 };
        var go = new P(-1, -1, -1);
        while (que.Count != 0)
        {
            var p = que.Dequeue();
            if (p.h == hw[0] - 1 && p.w == hw[1] - 1)
            {
                go = p;
                break;
            }
            for(var i = 0; i < 4; i++)
            {
                var h = p.h + gH[i];
                var w = p.w + gW[i];
                if (0 <= h && h < hw[0] && 0 <= w && w < hw[1] && !bo[h, w] && gred[h][w] != '#')
                {
                    bo[h, w] = true;
                    que.Enqueue(new P(h, w, p.len + 1));
                }
            }
        }
        WriteLine(go.len != -1 ? white - go.len : -1);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  
static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}