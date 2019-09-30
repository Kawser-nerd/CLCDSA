using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class C : X, IABC
{
    public C() { }
    public C(int i) : base(i) { }

    public void solve()
    {
        ReadLine();
        int n = ReadInt();
        int mod = 100003;
        int[] x = new int[n-2];
        int r = 1;  
        for (int c = 0; c < n-2; c++)
        {
            for (int i = 0; i < n-2; i++)
            {
                x[i] = i <= c ? 1 : 0;
            }
            var p = new Permutation.Permutation<int>(x);
            foreach (var y in p)
            {
                int[] z = new int[c+2];
                int pos = 0;
                //for (int i = n - 2; i >= 0; i--)
                for (int i = 0; i < n-2; i++)
                {
                    if (y[i] == 1)
                        z[pos++] = i+2;
                }
                z[pos] = n;
                r += help(n, z);
                r = r % mod;
            }
        }
        WriteCase("{1}", r);
    }

    private int help(int n, int[] z)
    {

        int x;
        int[] p=new int[n+1];
        for (int i = 0; i < z.Length; i++) p[z[i]]=i+1;

        x=n;
        while (x > 1)
            x=p[x];
                //foreach (int i in z)  
                //{
                //    Console.Write(i);
                //}
                //Console.WriteLine();
                //return 0;
        return x;
    }
}
