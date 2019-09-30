using System;
using System.Collections.Generic;

public class CSharp
{
    public static void Main()
    {
        Kyopuro chokudai = new Kyopuro();
        chokudai.AtCoder();
    }
}

public class Kyopuro
{
    public void AtCoder()
    {
        int n = int.Parse(Console.ReadLine());
        string[] s = Console.ReadLine().Split(' ');
        int[] b = new int[n];
        for (int i = 0; i < n; i++) b[i] = int.Parse(s[i]);
        int[] a = new int[n];
        int[] x = new int[n];
        bool[] f = new bool[n];
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if (b[j] < b[i]) x[i]++;
            }
        }
        int c = n - 1;
        int d = 0;
        bool ans = true;
        for(int i=0; i<n; i++)
        {
            c = n - 1;       
            while (c > -1)
            {
                ans = true;
                d = 0;
                if (!f[c])
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (f[j]) d++;
                    }
                    if (d < b[c] - 1)
                    {
                        ans = false;
                    }
                    d = 0;
                    for(int j=c; j<n; j++)
                    {
                        if (f[j]) d++;
                    }
                    if (d < x[c])
                    {
                        ans = false;
                    }
                }
                else ans = false;
                
                if(ans)
                {
                    a[i] = b[c];
                    f[c] = true;
                    c = 0;
                }
                c--;
            }
        }
        ans = true;
        for (int i = 0; i < n; i++) if (!f[i]) ans = false;
        if (ans)
        {
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(a[i]);             
            }
        }
        else Console.WriteLine(-1);

    }
    public static void DebugWL(object x) { System.Diagnostics.Debug.WriteLine(x); }
}