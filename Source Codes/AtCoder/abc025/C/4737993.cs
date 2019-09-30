using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using Debug;
//using static System.Globalization.CultureInfo;

class Program
{
    static int[][] b;
    static int[][] c;
    static int[][] state;
    static void Main(string[] args)
    {
        b = Input.twodim(2);
        c = Input.twodim(3);
        state = Enumerable.Repeat(0, 3).Select(v => new int[3]).ToArray();
        var res = dfs(0);
        var sum = b.Sum(v => v.Sum()) + c.Sum(v => v.Sum());
        WriteLine($"{res}\n{sum - res}");
    } 
    private static int dfs(int depth)
    {
        if (depth == 9)
        {
            var res = 0;
            for (var i = 0; i < 3; i++)
                for (var j = 0; j < 2; j++)
                    if (state[i][j] == state[i][j + 1])
                        res += c[i][j];
            for (var i = 0; i < 2; i++)
                for (var j = 0; j < 3; j++)
                    if (state[i][j] == state[i + 1][j])
                        res += b[i][j];
            return res;
        }
        var calc = depth % 2 == 0 ? int.MinValue : int.MaxValue;
        for(var i=0;i<3;i++)
            for(var j = 0; j < 3; j++)
            {
                if (state[i][j] != 0) continue;
                state[i][j] = 1 + ToInt32(depth % 2 != 0);
                if (depth % 2 == 0)
                    calc = Max(calc, dfs(depth + 1));
                else calc = Min(calc, dfs(depth + 1));
                state[i][j] = 0;
            }
        return calc;
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
    public const long Inf = (long)1e18;
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}