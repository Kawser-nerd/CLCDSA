using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    class P
    {
        public int h;
        public int w;
        public int bre;
        public P(int h,int w,int bre)
        {
            this.h = h;
            this.w = w;
            this.bre = bre;
        }
    }
    static void Main(string[] args)
    {
        var hw = Input.ar;
        var gred = Enumerable.Repeat(0, hw[0]).Select(v => ReadLine()).ToArray();
        var gH = new[] { 0, 0, -1, 1 };
        var gW = new[] { 1, -1, 0, 0 };
        var queue = new Queue<P>();
        var bo = new bool[hw[0], hw[1], 3];
        var min = new int[hw[0], hw[1]];
        for (var i = 0; i < hw[0]; i++)
            for (var j = 0; j < hw[1]; j++)
                min[i, j] = 3;
        P st = new P(-1, -1, -1);
        P go = new P(-1, -1, -1);
        for (var h = 0; h < hw[0]; h++)
        {
            for (var w = 0; w < hw[1]; w++)
            {
                if (gred[h][w] == 's')
                    st = new P(h, w, 0);
                if (gred[h][w] == 'g')
                    go = new P(h, w, 0);
            }
        }
        min[st.h,st.w] = 0;
        bo[st.h, st.w, 0] = true;
        queue.Enqueue(st);
        while (queue.Count != 0)
        {
            var p = queue.Dequeue();
            if (p.h == go.h && p.w == go.w)
            {
                WriteLine("YES");
                return;
            }
            for(var i = 0; i < 4; i++)
            {
                var h = p.h + gH[i];
                var w = p.w + gW[i];
                if (0 <= h && h < hw[0] && 0 <= w && w < hw[1])
                {
                    var b = p.bre + ToInt32(gred[h][w] == '#');
                    if (b < min[h,w] && !bo[h, w, b])
                    {
                        bo[h, w, b] = true;
                        min[h, w] = b;
                        queue.Enqueue(new P(h, w, b));
                    }
                }
            }
        }
        WriteLine("NO");
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}