using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Magatro
{
    private int N;
    private int[] A, B, C;

    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        A = new int[N];
        B = new int[N];
        C = new int[N];
        var l = Console.ReadLine().Split(' ');
        for (int i = 0; i < N; i++)
        {
            A[i] = int.Parse(l[i]);
        }
        l = Console.ReadLine().Split(' ');
        for (int i = 0; i < N; i++)
        {
            B[i] = int.Parse(l[i]);
        }
        l = Console.ReadLine().Split(' ');
        for (int i = 0; i < N; i++)
        {
            C[i] = int.Parse(l[i]);
        }
    }

    private int SearchA(int n)//n??????????
    {
        int l = -1;
        int r = N;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (A[mid] >= n)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return l + 1;
    }

    private int SearchC(int n)
    {
        int l = -1;
        int r = N;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (C[mid] > n)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return N - r;
    }

    public void Solve()
    {
        Scan();
        Array.Sort(A);
        Array.Sort(B);
        Array.Sort(C);
        long ans = 0;
        foreach (int n in B)
        {
            ans += (long)SearchA(n) * SearchC(n);
        }
        Console.WriteLine(ans);
    }
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}