using System;
using System.Collections.Generic;
using System.Linq;
//using System.Threading.Tasks;
//using System.Numerics;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().calc();
    }

    void init()
    {

    }

    long mod = 1000002013;
    void calc()
    {
        Scanner cin = new Scanner();
        int testCase = cin.nextInt();
        init();

        for (int test = 1; test <= testCase; test++)
        {
            Console.Write("Case #{0}: ", test);
            int ret = -1;
            int n = cin.nextInt();
            int m = cin.nextInt();
            int p = cin.nextInt();

            int[] u = new int[m];
            int[] v = new int[m];
            long[] a = new long[m];
            long[] b = new long[m];

            for (int i = 0; i < m; i++)
            {
                u[i] = cin.nextInt() - 1;
                v[i] = cin.nextInt() - 1;
                a[i] = cin.nextInt();
                b[i] = cin.nextInt();
            }
            int[] route = new int[p];
            for (int i = 0; i < p; i++)
            {
                route[i] = cin.nextInt() - 1;
            }

            List<long>[] l1 = new List<long>[n];
            List<long>[] l2 = new List<long>[n];
            for (int i = 0; i < n; i++)
            {
                l1[i] = new List<long>();
                l2[i] = new List<long>();
            }

            for (int i = 0; i < m; i++)
            {

                l1[u[i]].Add((a[i] << 16) + v[i]);
                l2[u[i]].Add((b[i] << 16) + v[i]);
            }

            long MAX = 1L << 40;
            long[,] dist1 = getdist(l1, n, MAX);
            long[,] dist2 = getdist(l2, n, MAX);

            long precost = 0;

            bool[] ok = new bool[n];
            for (int j = 0; j < n; j++)
            {
                ok[j] = true;
            }
            for (int i = 0; i < p; i++)
            {
                int from = u[route[i]];
                int to = v[route[i]];
                long cost = a[route[i]];

                long tcost = 0;
                long tempnew = MAX;
                for (int j = 0; j < p; j++)
                {
                    int tfrom = u[route[j]];
                    tempnew = Math.Min(tempnew, tcost + dist2[tfrom, 1]);
                    tcost += a[route[j]];
                }


                for (int j = 0; j < n; j++)
                {
                    long tempcost = dist1[to, j] + cost + dist1[j, 1] + precost;
                    long newcost = Math.Min(dist2[from, j] + dist1[j, 1], dist2[from, 1]) + precost;
                    newcost = Math.Min(newcost, tempnew);
                    if (tempcost > newcost) ok[j] = false;
                    //Console.WriteLine(tempcost + " " + newcost);

                }
                /*
                for (int j = 0; j < n; j++)
                {
                    if(ok[j]) Console.Write("o");
                    else Console.Write("x");
                }
                Console.WriteLine();
                 */
                if (!getdist2(l1, n, MAX, to, 1, ok))
                {
                    ret = route[i];
                    break;
                }
                precost += cost;
            }



            if (ret == -1)
            {
                Console.WriteLine("Looks Good To Me");
            }
            else Console.WriteLine(ret + 1);
        }

    }

    long[,] getdist(List<long>[] l, int n, long MAX)
    {
        long[,] ret = new long[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret[i, j] = MAX;
            }
            ret[i, i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            Heap<long> h = new Heap<long>();
            h.push(i);
            bool[] check = new bool[n];
            while (h.top != null)
            {
                long now = h.pop();
                int pos = (int)(now & ((1 << 16) - 1));
                long cost = now >> 16;
                if (check[pos]) continue;
                check[pos] = true;
                foreach (var item in l[pos])
                {
                    int to = (int)(item % (1 << 16));
                    long add = item >> 16;
                    long nextcost = cost + add;
                    if (ret[i, to] > nextcost)
                    {
                        ret[i, to] = nextcost;
                        h.push((nextcost << 16) + to);
                    }
                }

            }
        }

        return ret;
    }

    bool getdist2(List<long>[] l, int n, long MAX, int start, int goal, bool[] ok)
    {
        long[,] ret = new long[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret[i, j] = MAX;
            }
            ret[i, i] = 0;
        }

        for (int i = start; i <= start; i++)
        {
            Heap<long> h = new Heap<long>();
            h.push(i);
            bool[] check = new bool[n];
            while (h.top != null)
            {
                long now = h.pop();
                int pos = (int)(now & ((1 << 16) - 1));
                long cost = now >> 16;
                if (check[pos]) continue;
                if (!ok[pos]) continue;
                if (pos == goal) return true;

                check[pos] = true;
                foreach (var item in l[pos])
                {
                    int to = (int)(item % (1 << 16));
                    long add = item >> 16;
                    long nextcost = cost + add;
                    if (ret[i, to] > nextcost)
                    {
                        ret[i, to] = nextcost;
                        h.push((nextcost << 16) + to);
                    }
                }

            }
        }

        return false;
    }

}

class Heap<T> where T : IComparable
{
    public HeapNode<T> top;

    public Heap() { }

    public void push(T val)
    {
        top = HeapNode<T>.meld(top, new HeapNode<T>(val));
    }

    public T pop()
    {
        T ret = top.val;
        top = HeapNode<T>.meld(top.r, top.l);
        return ret;
    }

    public void merge(Heap<T> h2)
    {
        top = HeapNode<T>.meld(top, h2.top);
    }

    public class HeapNode<NT> where NT : IComparable
    {
        public HeapNode<NT> l, r;
        public NT val;

        public HeapNode(NT _val)
        {
            val = _val;
        }

        public static HeapNode<NT> meld(HeapNode<NT> a, HeapNode<NT> b)
        {
            if (a == null) return b;
            if (b == null) return a;
            if (a.val.CompareTo(b.val) > 0)
            {
                HeapNode<NT> temp = a;
                a = b;
                b = temp;
            }
            a.r = meld(a.r, b);
            HeapNode<NT> temph = a.l;
            a.l = a.r;
            a.r = temph;
            return a;
        }
    }
}





class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }
}