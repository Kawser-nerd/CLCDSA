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
    static void Main(string[] args)
    {
        Solve();
        //WriteLine(Solve());
    }
    static void Solve()
    {
        var hwab = Input.ar;
        var com = new Modulo.Combination(hwab[0] + hwab[1]);
        var res = 0L;
        for(var i = hwab[3]; i < hwab[1]; i++)
        {
            var calc = (long)com.Comb(hwab[0] - hwab[2] + i-1, i) * com.Comb(hwab[1]  - i-2 + hwab[2], hwab[2]-1) % Input.MOD;
            res += calc;
            res %= Input.MOD;
        }
        WriteLine(res);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static char[][] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read.ToCharArray()).ToArray();
    public static int[][] ar2D(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] arL2D(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class Modulo
{
    private static int Multiple(int num1, int num2)
        => (int)(BigMul(num1, num2) % Input.MOD);

    public static int Pow(int m, int n)
    {
        if (n == 0) return 1;
        if (n % 2 == 0) return Pow(Multiple(m, m), n / 2);
        else return Multiple(Pow(Multiple(m, m), n / 2), m);
    }

    public static int Div(int a, int b)
        => Multiple(a, Pow(b, Input.MOD - 2));

    public class Combination
    {
        private int[] _fac;
        public Combination(int num)//??????
        {
            _fac = new int[num + 1];
            _fac[0] = 1;
            for (var i = 1; i <= num; i++)
                _fac[i] = Multiple(_fac[i - 1], i);
        }
        public int Comb(int n, int r)
        {
            if (n < r) return 0;
            if (n == r) return 1;
            var calc = _fac[n];
            calc = Div(calc, _fac[r]);
            calc = Div(calc, _fac[n - r]);
            return calc;
        }
        public int fac(int num)
            => _fac[num];
    }

}