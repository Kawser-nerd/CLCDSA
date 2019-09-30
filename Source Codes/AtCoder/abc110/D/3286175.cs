using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Int32;
using static System.Math;

class Program
{
    const int WARU = 1000000007;
    static void Main(string[] args)
    {
        label:
        var sp = ReadLine().Split();
        int n = Parse(sp[0]);
        long m = Parse(sp[1]);
        if (m == 1)
        {
            WriteLine(1);
        }
        else
        {
            var kusi = new bool[(int)Sqrt(m) + 2];
            int sq = (int)Sqrt(kusi.Length) + 1;
            for (int i = 2; i <= sq; ++i)
            {
                if (kusi[i]) continue;
                for (int j = 2; ; ++j)
                {
                    int index = i * j;
                    if (index < kusi.Length) kusi[index] = true;
                    else break;
                }
            }
            var sosu = new List<int>(3401);
            for (int i = 2; i < kusi.Length; ++i)
            {
                if (!kusi[i])
                {
                    sosu.Add(i);
                }
            }
            var list = new SortedList<long, int>();
            foreach (int i in sosu)
            {
                if (m % i == 0)
                {
                    list[i] = 0;
                    do
                    {
                        ++list[i];
                        m /= i;
                    } while (m % i == 0);
                    if (m < i * i)
                    {
                        break;
                    }
                }
            }
            if (1 < m)
            {
                list[m] = 1;
            }
            long result = 1;
            var array = dd(n, list.Values.Max());
            foreach(var count in list.Values)
            {
                result *= array[count - 1];
                result %= WARU;
            }
            WriteLine(result);
        }
        //WriteLine(hoge() ? "Yes" : "No");
        //goto label;
    }
    static long[] dd(int n, int count)
    {
        var result = new long[count];
        result[0] = n;
        var array = new long[n];
        for (int i = 0; i < array.Length; ++i)
        {
            array[i] = 1;
        }
        for (int i = 1; i < count; ++i)
        {
            for (int j = 1; j < array.Length; ++j)
            {
                array[j] += array[j - 1];
                if (WARU <= array[j]) array[j] -= WARU;
            }
            result[i] = array.Sum() % WARU;
        }
        return result;
    }
}