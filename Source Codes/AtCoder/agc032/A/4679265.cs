using System.Text;
using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = new List<int>();
        for (int i = 0; i < n; i++)
            a.Add(int.Parse(line[i]));
        getAns(a);
    }
    static void getAns(List<int> a)
    {
        var ans = new List<int>();
        while (a.Count() > 0)
        {
            var ac = a.Count();
            var find = false;
            for (int i = ac - 1; i >= 0; i--)
            {
                if (a[i] == i + 1)
                {
                    ans.Add(a[i]);
                    a.RemoveAt(i);
                    find = true;
                    break;
                }
            }
            if (!find) { Console.WriteLine(-1); return; }
        }
        ans.Reverse();
        var sb = new StringBuilder();
        foreach (var x in ans) sb.Append(string.Format("{0}\n", x));
        Console.Write(sb);
    }
}