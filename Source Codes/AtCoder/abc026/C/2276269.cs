using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using System.Threading.Tasks;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] b = new int[n];
        List<int>[] s = Enumerable.Repeat(0, n).Select(_ => new List<int>()).ToArray();
        for (int i = 1; i < n; i++)
        {
            int p = int.Parse(Console.ReadLine()) - 1;
            s[p].Add(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i].Count == 0)
            {
                b[i] = 1;
            }
            else
            {
                b[i] = s[i].Max(x => b[x]) + s[i].Min(x => b[x]) + 1;
            }
        }
        Console.WriteLine(b[0]);
    }
}