using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var dic = new Dictionary<int, int>();
        for (int i = 0; i < n; i++) dic[a[i]] = i;
        dic = dic.OrderByDescending(x => x.Key).ToDictionary(x => x.Key, x => x.Value);
        foreach (int i in dic.Values) Console.WriteLine(i + 1);
    }
}