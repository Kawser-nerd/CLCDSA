using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    class G
    {
        public int h;
        public int w;
        public long Weight;
        public bool isWhite;
        public G(int h,int w,bool isWhite)
        {
            this.h = h;
            this.w = w;
            Weight = Input.Inf;
            this.isWhite = isWhite;
        }
    }
    static void Main(string[] args)
    {
        var hwt = Input.ar;
        var gred = Enumerable.Repeat(0, hwt[0]).Select(v => ReadLine()).ToArray();
        var gs = new G[hwt[0], hwt[1]];
        var st = new Tuple<int, int>(-1,-1);
        var go = new Tuple<int, int>(-1, -1);
        for (var i = 0; i < hwt[0]; i++)
            for (var j = 0; j < hwt[1]; j++)
            {
                if (gred[i][j] == 'S')
                    st = new Tuple<int, int>(i, j);
                if (gred[i][j] == 'G')
                    go = new Tuple<int, int>(i, j);
                gs[i, j] = new G(i, j, gred[i][j] != '#');
            }
        var gh = new[] { 0, 0, -1, 1 };
        var gw = new[] { 1, -1, 0, 0 };
        gs[st.Item1, st.Item2].Weight = 0;
        var left = 0L;
        long right = hwt[2];
        while (right - left > 1)
        {
            var mid = (right + left) / 2;
            var bo = new bool[hwt[0], hwt[1]];
            for (var i = 0; i < hwt[0]; i++)
                for (var j = 0; j < hwt[1]; j++)
                    if (st.Item1 != i || st.Item2 != j)
                        gs[i, j].Weight = Input.Inf;
            while (true)
            {
                var minVal = Input.Inf;
                var u = new G(-1, -1, false);
                for(var i=0;i<hwt[0];i++)
                    for(var j=0;j<hwt[1];j++)
                        if (!bo[i,j]&&minVal > gs[i, j].Weight)
                        {
                            u = gs[i, j];
                            minVal = u.Weight;
                        }
                if (u.h == -1) break;
                bo[u.h, u.w] = true;
                for(var i = 0; i < 4; i++)
                {
                    var h = gh[i] + u.h;
                    var w = gw[i] + u.w;
                    if (Search.IsInside(h, w, hwt) && !bo[h, w] && gs[h, w].Weight > u.Weight + (gs[h, w].isWhite ? 1 : mid))
                        gs[h, w].Weight = u.Weight + (gs[h, w].isWhite ? 1 : mid);
                }
            }
            if (gs[go.Item1,go.Item2].Weight > hwt[2]) right = mid;
            else left = mid;
        }
        WriteLine(left);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static string[] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read).ToArray();
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public static Tuple<int, int, long> MakeEdge(int num1, int num2, long weight=Inf)
        => new Tuple<int, int, long>(num1, num2, weight);
    public const long Inf = (long)1e18;
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class Search
{
    public static int UpperBound<T>(T[] array,T value)
        where T:IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) == 1) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static int LowerBound<T>(T[] array,T value)
        where T : IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) != -1) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static T Max<T>(params T[] array)
        => array.Max();
    public static T Min<T>(params T[] array)
        => array.Min();
    public static bool IsInside(int h, int w, int[] hw)
        => 0 <= h && h < hw[0] && 0 <= w && w < hw[1];
    public static bool IsPrime(long num)
    {
        if (num % 2 == 0) return false;
        for (var i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
}