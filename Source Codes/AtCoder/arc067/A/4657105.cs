using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{ 
    static void Main(string[] args)
    {
        var num = Input.num;
        var dic = new Dictionary<long, long>();
        for (var i = 2; i <= num; i++)
        {
            var d = Calculation.Factorization(i);
            foreach (var pair in d)
                if (dic.ContainsKey(pair.Key))
                    dic[pair.Key] += pair.Value;
                else dic[pair.Key] = pair.Value;
        }
        var res = 1L;
        foreach (var val in dic.Values)
            res = (res * (val + 1)) % Input.MOD;
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
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class Calculation
{
    public static int LCM(int num1, int num2)
    {
        return num1 / GCD(num1, num2) * num2;
    }

    public static long LCM(long num1, long num2)
    {
        return num1 / GCD(num1, num2) * num2;
    }

    public static int GCD(int num1, int num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }

    public static long GCD(long num1, long num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }

    public static List<int> GetPrime(long num)
    {
        if (num < 2) return new List<int>();
        var prime = new List<int> { 2 };
        var bo = new bool[num + 1];
        for (var i = 3; i <= num; i += 2)
            if (!bo[i])
            {
                prime.Add(i);
                for (var j = 3 * i; j <= num; j += 2 * i)
                    bo[j] = true;
            }
        return prime;
    }

    public static Dictionary<long,int> Factorization(long num)
    {
        var dic = new Dictionary<long, int>();
        for(var i = 2; i * i <= num; i++)
        {
            var ct = 0;
            while (num % i == 0)
            {
                ct++;
                num /= i;
            }
            if (ct != 0) dic[i] = ct;
        }
        if (num != 1) dic[num] = 1;
        return dic;
    }
        
    
}