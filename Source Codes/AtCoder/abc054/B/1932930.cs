using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NM = Console.ReadLine().Split().Select(int.Parse).ToArray();
        string[] A = new string[NM[0]].Select(x => Console.ReadLine()).ToArray();
        string[] B = new string[NM[1]].Select(x => Console.ReadLine()).ToArray();

        for (int i = 0; i <= NM[0] - NM[1]; i++)
        {
            string[] atemp = A.Where((_,x) => i <= x && x < NM[1] + i).ToArray();
            for (int j = 0; j <= NM[0] - NM[1]; j++)
            {
                string[] a = atemp.Select(x => x.Substring(j, NM[1])).ToArray();
                bool b = true;
                for (int k = 0; k < a.Length; k++)
                {
                    if (a[k] != B[k])
                    {
                        b = false;
                        break;
                    }
                }
                if (b)
                {
                    Console.WriteLine("Yes");
                    return;
                }
            }
        }
        Console.WriteLine("No");
    }
}