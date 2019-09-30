using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
using static System.Math;

class Program
{
    static int N;
    static int K;
    static long[] a;

    static void Main()
    {
        /* ??????? */
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        K = input[1];
        a = new long[N];
        for (int i = 0; i < N; i++)
            a[i] = long.Parse(Console.ReadLine());

        /* b[i] = a[i] - K???? */
        long[] b = a.Select(s => s - K).ToArray();

        /* b???? */
        long[] sum = new long[N + 1];
        for (int i = 0; i < N; i++)
            sum[i + 1] = sum[i] + b[i];

        Console.WriteLine(Calc(sum));
    }

    /* i < j?????a[i] <= a[j]??(i,j)??????? */
    public static long Calc(long[] a)
    {
        int n = a.Length;
        SortedSet<long> s = new SortedSet<long>();
        foreach (var i in a) s.Add(i);
        long[] sorted_a = s.ToArray();
        RSQ1 rsq = new RSQ1(s.Count);
        long ans = 0;
        for (int j = 0; j < n; j++)
        {
            int i = Search(sorted_a, a[j]);
            ans += rsq.Query(0, i + 1);
            rsq[i] += 1;
        }
        return ans;
    }

    /* ???array??s?????????index???(??????????1?) */
    public static int Search(long[] array, long s)
    {
        int l = 0;
        int r = array.Length - 1;
        while (l != r)
        {
            int m = l + (r - l) / 2;
            if (array[m] == s) return m;
            if (array[m] < s) l = m + 1;
            if (array[m] > s) r = m - 1;
        }
        return l;
    }
}

struct RSQ1
{
    private int n;
    private long[] dat;
    public int Length { get; private set; }
    public long this[int i]
    {
        get
        {
            if (i < 0 || i >= this.Length)
                throw new IndexOutOfRangeException();
            return dat[i + n - 1];
        }
        set { this.Update(i, value); }
    }

    /* n???????????0???? */
    public RSQ1(int n)
    {
        Length = n;
        this.n = 1;
        while (this.n < n) this.n *= 2;
        dat = new long[2 * this.n];
    }

    /* k??(0-indexed)?a??? */
    public void Update(int k, long a)
    {
        k += n - 1;
        dat[k] = a;
        while (k > 0)
        {
            k = (k - 1) / 2;
            dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
        }
    }

    private long Query_(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return dat[k];
        long v1 = Query_(a, b, k * 2 + 1, l, (l + r) / 2);
        long v2 = Query_(a, b, k * 2 + 2, (l + r) / 2, r);
        return v1 + v2;
    }

    /* [a,b)?????? */
    public long Query(int a, int b)
    {
        return Query_(a, b, 0, 0, n);
    }
}