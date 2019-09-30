using System;
using static System.Console;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        var res = MyUtil.ReadIntArray();
        int a = res[0];
        int b = res[1];
        int c = res[2];

        if (a == b && b == c)
            WriteLine(1);
        else if (a == b || b == c || c == a)
            WriteLine(2);
        else
            WriteLine(3);
        ReadKey();
    }
}

static class MyUtil
{
    public static int[] ReadIntArray()
    {
        return ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
    }

    /// <summary>
    /// <see cref="IEnumerable{T}"/>?????????????????????????????????????????
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="ts"></param>
    public static void WriteToConsole<T>(this IEnumerable<T> ts)
    {
        StringBuilder stringBuilder = new StringBuilder();
        foreach (T t in ts)
        {
            stringBuilder.Append(t.ToString());
            stringBuilder.Append(" ");
        }
        stringBuilder.Remove(stringBuilder.Length - 1, 1);
        Console.WriteLine(stringBuilder.ToString());
    }
}