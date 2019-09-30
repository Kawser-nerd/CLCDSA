using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    private static int num;
    static void Main(string[] args)
    {
        num = Input.num;
        var str = ReadLine();
        var res = new string[num];
        var sw = new[] { "S", "W" };
        if (str[0] == 'o')
            for(var i=0;i<2;i++)
            {
                res = new string[num];
                res[0] = "S";
                res[num - 1] = sw[i];
                if (ss(res, str, 1, sw[i]))
                {
                    WriteLine(string.Join("", res));
                    return;
                }
            }
        else for(var i = 0; i < 2; i++)
            {
                res = new string[num];
                res[0] = "S";
                res[num - 1] = sw[i];
                if (ss(res, str, 1, sw[1 - i]))
                {
                    WriteLine(string.Join("", res));
                    return;
                }
            }
        if (str[0] == 'x')
            for (var i = 0; i < 2; i++)
            {
                res = new string[num];
                res[0] = "W";
                res[num - 1] = sw[i];
                if (ss(res, str, 1, sw[i]))
                {
                    WriteLine(string.Join("", res));
                    return;
                }
            }
        else for (var i = 0; i < 2; i++)
            {
                res = new string[num];
                res[0] = "W";
                res[num - 1] = sw[i];
                if (ss(res, str, 1, sw[1 - i]))
                {
                    WriteLine(string.Join("", res));
                    return;
                }
            }
        WriteLine(-1);
    }
    private static bool ss(string[] res, string str, int index, string state)
    {
        if (!string.IsNullOrEmpty(res[index]) && res[index] != state)
            return false;
        if (index == 0) return true;
        res[index] = state;
        if (state == "S")
        {
            if (str[index] == 'o')
               return ss(res, str, (index + 1) % num, res[index - 1]);
            else return ss(res, str, (index + 1) % num, res[index - 1] == "S" ? "W" : "S");
        }
        else
        {
            if (str[index] == 'o')
                return ss(res, str, (index + 1) % num, res[index - 1] == "S" ? "W" : "S");
            else return ss(res, str, (index + 1) % num, res[index - 1]);
        }
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