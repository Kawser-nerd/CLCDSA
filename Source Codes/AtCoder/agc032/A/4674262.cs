using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using static System.Math;
using Debug = System.Diagnostics.Debug;


static class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select(int.Parse).ToList();
        List<int> operations = new List<int>();
        for (int i = 1; i <= n; i++)
        {
            //????n??????????
            int currentBack = 0;
            int insertOps = 0;
            for (int j = a.Count - 1; j >= 0; j--)
            {
                if (a[j] < i) currentBack++;
                if (a[j] == i)
                {
                    if (operations.Count < currentBack + insertOps + i - 1)
                    {
                        Console.WriteLine(-1);
                        return;
                    }
                    else
                    {
                        operations.Insert(currentBack + insertOps + i - 1, i);
                        insertOps++;
                    }
                }
            }
        }
        Console.WriteLine(string.Join("\n", operations));
    }
}