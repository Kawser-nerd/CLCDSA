using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Enumerable.Repeat(0, n).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        var adist = a.Distinct();
        Dictionary<int,int> zaatsu = adist.OrderBy(x => x).Zip(Enumerable.Range(0,adist.Count()),(x,y) => new Tuple<int,int>(x,y)).ToDictionary(x => x.Item1,y => y.Item2);
        for (int i = 0; i < a.Length; i++) Console.WriteLine(zaatsu[a[i]]);
    }
}