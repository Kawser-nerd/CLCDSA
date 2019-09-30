using System;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var a = new int[n].Select(i => NextInt()).ToArray();

        if (Judge(a))
            WriteLine(Calc(a));
        else
            WriteLine(-1);
    }

    static int Calc(int[] a)
    {
        var result = 0;
        var dic = new int[0];

        foreach (var ai in a)
        {
            Array.Resize(ref dic, dic.Length + 1);
            dic[dic.Length - 1] = ai;
            if (dic.Sum() * a.Length == a.Sum() * dic.Length)
                dic = new int[0];
            else
                result++;
        }
        return result;
    }

    static bool Judge(int[] a)
    {
        if (a.Sum() % a.Length == 0) return true;
        return false;
    }

    static int NextInt()
    {
        return int.Parse(NextStr());
    }

    static string NextStr()
    {
        var result = "";
        while (true)
        {
            int tmp0 = Read();
            if (tmp0 < 0)
                break;
            var tmp = (char)tmp0;
            if (!string.IsNullOrWhiteSpace(tmp + ""))
                result += tmp;
            else if (tmp != '\r')
                break;
        }
        return result;
    }
}