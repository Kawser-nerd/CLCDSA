using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;

class Program
{
    static int Q;

    static void Main()
    {
        Q = int.Parse(Console.ReadLine());

        RSQ rsq = new RSQ(200001);
        for (int i = 0; i < Q; i++)
        {
            int[] tx = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int t = tx[0];
            int x = tx[1];
            if (t == 1)
            {
                rsq[x]++;
            }
            else
            {
                int l = -1;
                int r = 200001;
                while (r - l > 1)
                {
                    int m = (l + r) / 2;
                    if (rsq.Query(0, m + 1) >= x) r = m;
                    else l = m;
                }
                Console.WriteLine(l + 1);
                rsq[l + 1]--;
            }
        }
    }
}

struct RSQ
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
    public RSQ(int n)
    {
        Length = n;
        this.n = 1;
        while (this.n < n) this.n *= 2;
        dat = new long[2 * this.n];
        for (int i = 0; i < 2 * this.n - 1; i++)
            dat[i] = 0;
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