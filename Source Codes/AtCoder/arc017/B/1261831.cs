using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;
using System.Linq;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, K;
    private int[] A;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        K = int.Parse(line[1]);
        A = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = int.Parse(Console.ReadLine());
        }
    }

    public void Solve()
    {
        Scan();
        int cnt = 1;
        int ans = K==1?1:0;
        for (int i = 0; i < N-1; i++)
        {
            if (A[i] < A[i + 1])
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            if (K <= cnt)
            {
                ans++;
            }
        }
        Console.WriteLine(ans);
    }
}