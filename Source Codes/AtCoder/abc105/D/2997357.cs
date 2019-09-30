using System;
using static System.Console;
using static System.Math;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        var input = ReadLine().Split();
        int n = int.Parse(input[0]);
        int m = int.Parse(input[1]);
        int[] a = Array.ConvertAll(ReadLine().Split(), int.Parse);

        Dictionary<long,long> dic = new Dictionary<long,long>();
        dic.Add(0,0);
        long[] sum = new long[n+1];

        foreach(int i in EnumerableCommon.Range(n))
        {
            sum[i + 1] = (sum[i] + a[i]) % m;
        }

        long ans = 0;
        foreach(int i in EnumerableCommon.Range(sum.Length))
        {
            if (dic.ContainsKey(sum[i]))
            {
                ans += dic[sum[i]];
            }
            else dic.Add(sum[i], 0);
                dic[sum[i]]++;
        }

        WriteLine(ans);
    }
    public static partial class EnumerableCommon
    {
        public static IEnumerable<int> Range(int count)
        {
            return Enumerable.Range(0, count);
        }
    }
}