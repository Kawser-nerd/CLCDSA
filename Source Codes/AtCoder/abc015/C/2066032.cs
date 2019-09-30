using System.Linq;
using System.Collections.Generic;
using System;

public  class Calc
{
    public int t { get; set; }
    public int x { get; set; }
}

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var a = new int[n, k];
        for (int i = 0; i < n; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < k; j++) a[i, j] = int.Parse(line[j]);
        }
        Console.WriteLine(getSelect(n, k, a) ? "Found" : "Nothing");
    }
    public static bool getSelect (int n , int k , int[,] a)
    {
        var st = new Stack<Calc>();
        for (int i = 0; i < k; i++)
            st.Push    (new Calc { t = 0, x = a[0, i] });
        while (st.Count() > 0)
        {
            var w = st.Pop();
            if (w.t == n - 1)
                if (w.x == 0) return true;
                else continue;
            for (int i = 0; i < k; i++)
                st.Push(new Calc { t = w.t + 1, x = w.x ^ a[w.t + 1, i] });
        }
        return false;
    }
}