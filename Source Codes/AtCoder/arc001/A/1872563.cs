using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int a = int.Parse(Console.ReadLine());
        int[] n = Console.ReadLine().ToCharArray().Select(b => int.Parse(b.ToString())).ToArray();
        foreach (int i in n) {
            if (dic.ContainsKey(i)) dic[i]++;
            else dic.Add(i, 1);
        }

        var sorted_a = dic.OrderByDescending((x) => x.Value);
        var sorted_b = dic.OrderBy((x) => x.Value);
        if(dic.Count() == 1) Console.WriteLine(sorted_a.First().Value + " 0");
        else Console.WriteLine(sorted_a.First().Value + " " + sorted_b.First().Value);
    }
}