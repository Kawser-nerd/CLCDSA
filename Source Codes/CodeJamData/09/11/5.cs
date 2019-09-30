using System;
using System.Collections.Generic;

public class Myon
{
    public Myon() { }
    public static int Main(){
        new Myon().myon();
        return 0;
    }

    bool[,] flag = new bool[11, 10000];

    public void myon()
    {
        int i,j;
        int m = int.Parse(Console.ReadLine());
        for (i = 1; i < 10000; i++)
        {
            for (j = 2; j < 11; j++)
            {
                flag[j, i] = check(i, j, false);
            }
        }

        for (int loop=1;loop<=m ;loop++)
        {
            int[] num;
            string[] st = Console.ReadLine().Split(' ');
            num = new int[st.Length];
            for (i = 0; i < st.Length; i++) num[i] = int.Parse(st[i]);
            Console.WriteLine("Case #{0}: {1}",loop,func(num));
        }
    }

    public bool check(int a,int b,bool f)
    {
        int i;
        if (a == 1) return true;
        int c = a;
        for (i = 0; i < 100; i++)
        {
            if (c < 10000 && c < a) return flag[b, c];
            if (c < 10000 && c <= a && f) return flag[b, c];
            int d = 0;
            while (c != 0)
            {
                int e = c % b;
                d += e * e;
                c /= b;
            }
            c = d;
        }
        return false;
    }

    public int func(int[] ar)
    {
        int i,j;
        for (i = 2; ; i++)
        {
            for (j = 0; j < ar.Length; j++)
            {
                if (!check(i, ar[j], true)) break;
            }
            if (j == ar.Length) return i;
        }
    }
}