//#define TEST

using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static string s;
    static List<int> dx; // x????????
    static List<int> dy; // y????????
    static int x;
    static int y;

    static void Main()
    {
        s = Console.ReadLine();
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        x = input[0];
        y = input[1];
        dx = new List<int>();
        dy = new List<int>();

        int c = 0;
        bool f = false; // true??x????false??y???
        int st = 0;
        while (st < s.Length && s[st] != 'T')
            st++;
        dx.Add(st);
        for (int i = st + 1; i < s.Length; i++)
        {
            if (s[i] == 'F')
            {
                c++;
                continue;
            }
            if (f && c > 0)
                dx.Add(c);
            else if (!f && c > 0)
                dy.Add(c);
            c = 0;
            f = !f;
        }
        if (f)
            dx.Add(c);
        else
            dy.Add(c);

#if TEST
        foreach (var i in dx)
            Console.Write("{0} ", i);
        Console.WriteLine();
        foreach (var i in dy)
            Console.Write("{0} ", i);
        Console.WriteLine();
#endif

        /* dpx[x,i] : dx?i+1???????x-8000?????? */
        bool[,] dpx = new bool[16001, dx.Count];
        dpx[dx[0] + 8000, 0] = true;
        for (int i = 1; i < dx.Count; i++)
        {
            int xl = dx[i];
            for (int j = 0; j <= 16000; j++)
            {
                if (j - xl >= 0)
                {
                    dpx[j, i] = dpx[j - xl, i - 1];
                }
                if (j + xl <= 16000)
                {
                    dpx[j, i] = dpx[j, i] || dpx[j + xl, i - 1];
                }
            }
        }
        bool xf = dpx[x + 8000, dx.Count - 1];

#if TEST
        Console.WriteLine(xf);
#endif

        /* dpy[y,i] : dy?i???????y-8000?????? */
        bool[,] dpy = new bool[16001, dy.Count + 1];
        dpy[8000, 0] = true;
        for (int i = 0; i < dy.Count; i++)
        {
            int yl = dy[i];
            for (int j = 0; j <= 16000; j++)
            {
                if (j - yl >= 0)
                {
                    dpy[j, i + 1] = dpy[j - yl, i];
                }
                if (j + yl <= 16000)
                {
                    dpy[j, i + 1] = dpy[j, i + 1] || dpy[j + yl, i];
                }
            }
        }
        bool yf = dpy[y + 8000, dy.Count];
#if TEST
        Console.WriteLine(yf);
#endif

        Console.WriteLine((xf && yf) ? "Yes" : "No");
    }
}