using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;

    int MAX = 999999;
    
    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] A = cin.ArrayInt(N, -1);


        prePos = new int[N];
        List<int> AList = new List<int>();
        List<int> BList = new List<int>();
        for (int i = 0; i < A.Length; i++)
        {
            if (i % 2 == 0) AList.Add(MAX - A[i]);
            else BList.Add(MAX - A[i]);
            prePos[A[i]] = i;
        }

        seg = new Segtree[2];
        seg[0] = new Segtree(AList.Count, AList.ToArray());
        seg[1] = new Segtree(BList.Count, BList.ToArray());

        a = new List<int>();
        b = new List<int>();
        h = new PriorityQueue<long>();
        next = new List<int>[N];
        nowID = 0;
        
        q = new Queue<Tuple<int, int, int>>();
        q.Enqueue(Tuple.Create(0, N, -1));
        while(q.Count != 0)
        {
            var nextQuery = q.Dequeue();
            dfs(nextQuery.Item1, nextQuery.Item2, nextQuery.Item3);
        }

        h.Enqueue(-hash(a[0], b[0], 0));

        List<long> ansArray = new List<long>();
        while (h.Count != 0)
        {
            var nextNode = -h.Dequeue();
            long anum = (nextNode >> 40);
            long bnum = (nextNode >> 20) & 0xFFFFF;
            ansArray.Add(MAX - anum + 1);
            ansArray.Add(MAX - bnum + 1);
            int id = (int)(nextNode & 0xFFFFF);
            foreach (var item in next[id])
            {
                h.Enqueue(-hash(a[item], b[item], item));
            }
        }
        Console.WriteLine(string.Join(" ", ansArray));
    }

    List<int> a;
    List<int> b;
    List<int>[] next;
    PriorityQueue<long> h;
    int nowID;

    int[] prePos;
    Segtree[] seg;

    long hash(long a, long b, long c)
    {
        return (a << 40) + (b << 20) + c;
    }

    Queue<Tuple<int, int, int>> q;

    void dfs(int l, int r, int preID)
    {
        if (r - l <= 0) return;
        int lid = l % 2;
        int lpos = l / 2;
        int rid = 1 - lid;
        int rpos = (r + 1 - l%2) / 2;

        int left = seg[lid].getMax(lpos, rpos);
        int leftPos = prePos[MAX - left];

        int right = seg[rid].getMax((leftPos + 1) / 2, (r + l % 2) / 2);
        int rightPos = prePos[MAX - right];

        a.Add(left);
        b.Add(right);
        int nid = nowID;
        next[nowID] = new List<int>();
        if(preID != -1)
        {
            next[preID].Add(nid);
        }
        nowID++;
        q.Enqueue(Tuple.Create(l, leftPos, nid));
        q.Enqueue(Tuple.Create(leftPos + 1, rightPos, nid));
        q.Enqueue(Tuple.Create(rightPos + 1, r, nid));
    }
    
    /// <summary>
    /// ??????????????????????????????????????????????????
    /// </summary>
    /// <typeparam name="T">?????????????????????</typeparam>
    /// <remarks>?????????????????????????</remarks>
    public class PriorityQueue<T>
    {
        readonly List<T> heap = new List<T>();
        readonly IComparer<T> cmp;

        /// <summary>
        /// ????????????????????????????
        /// </summary>
        /// <remarks>????? O(1) ????????</remarks>
        public PriorityQueue() { cmp = Comparer<T>.Default; }

        /// <summary>
        /// ????????????????????????????????????
        /// </summary>
        /// <param name="comparison"></param>
        /// <remarks>????? O(1) ????????</remarks>
        public PriorityQueue(Comparison<T> comparison) { cmp = Comparer<T>.Create(comparison); }

        /// <summary>
        /// ???????????????????????????
        /// </summary>
        /// <param name="comparer"></param>
        /// <remarks>????? O(1) ????????</remarks>
        public PriorityQueue(IComparer<T> comparer) { cmp = comparer; }

        /// <summary>
        /// ??????????????????
        /// </summary>
        /// <param name="item">????????????????</param>
        /// <remarks>????? O(log N) ????????</remarks>
        public void Enqueue(T item)
        {
            var pos = heap.Count;
            heap.Add(item);
            while (pos > 0)
            {
                var par = (pos - 1) / 2;
                if (cmp.Compare(heap[par], item) <= 0)
                    break;
                heap[pos] = heap[par];
                pos = par;
            }
            heap[pos] = item;

        }

        /// <summary>
        /// ?????????????????????????????
        /// </summary>
        /// <returns>??????????????????</returns>
        /// <remarks>????? O(log N) ????????</remarks>
        public T Dequeue()
        {
            var ret = heap[0];
            var pos = 0;
            var x = heap[heap.Count - 1];

            while (pos * 2 + 1 < heap.Count - 1)
            {
                var lch = pos * 2 + 1;
                var rch = pos * 2 + 2;
                if (rch < heap.Count - 1 && cmp.Compare(heap[rch], heap[lch]) < 0) lch = rch;
                if (cmp.Compare(heap[lch], x) >= 0)
                    break;
                heap[pos] = heap[lch];
                pos = lch;
            }
            heap[pos] = x;
            heap.RemoveAt(heap.Count - 1);
            return ret;

        }
        /// <summary>
        ///  ?????????????????????????????????
        /// </summary>
        /// <returns>???????????????????????</returns>
        /// <remarks>????? O(1) ????????</remarks>
        public T Peek() { return heap[0]; }

        /// <summary>
        /// ?????????????????????
        /// </summary>
        /// <returns>???????????????</returns>
        /// <remarks>????? O(1) ????????</remarks>
        public int Count { get { return heap.Count; } }
        /// <summary>
        /// ?????????????????????? O(1) ???????
        /// </summary>
        /// <returns>????????????????????? true?????????false?</returns>
        /// <remarks>????? O(1) ????????</remarks>
        public bool Any() { return heap.Count > 0; }

        /// <summary>
        /// ???????????????????????????
        /// </summary>
        /// <remarks>???????? O(N log N)????????</remarks>
        public T[] Items
        {
            get
            {
                var ret = heap.ToArray();
                Array.Sort(ret, cmp);
                return ret;
            }
        }
    }


    class Segtree
    {
        int N;
        int[] L;
        int[] R;
        int[] M;
        int[,] np;

        public Segtree(int _N, int[] Array)
        {
            N = 1;
            while (N < _N) N *= 2;
            init();

            L = new int[N * 2];
            R = new int[N * 2];
            M = new int[N * 2];
            np = new int[N * 2, 2];
            L[0] = 0;
            R[0] = N;
            M[0] = N / 2;

            for (int i = 0; i < N - 1; i++)
            {
                np[i, 0] = i * 2 + 1;
                np[i, 1] = i * 2 + 2;
                L[np[i, 0]] = L[i];
                R[np[i, 0]] = L[np[i, 1]] = (L[i] + R[i]) / 2;
                R[np[i, 1]] = R[i];
            }
            for (int i = 0; i < N; i++)
            {
                M[i] = (L[i] + R[i]) / 2;
            }

            for (int i = L.Length - 1; i >= 0; i--)
            {
                if (L[i] == R[i]) continue;
                if (L[i] + 1 == R[i])
                {
                    if(L[i] < Array.Length) max[i] = Array[L[i]];
                }
                else
                {
                    merge(i);
                }
            }
        }
        
        int[] max;

        void init()
        {
            max = new int[2 * N];
        }
        

        //??????
        public void merge(int p)
        {
            max[p] = Math.Max(max[np[p, 0]], max[np[p, 1]]);
        }
        

        public int getMax(int l, int r, int p = 0)
        {
            if (l == r) return 0;
            if (l == L[p] && r == R[p])
            {
                //?????
                return max[p];
            }
            else
            {
                //????
                int ans = 0;
                if (l < M[p]) ans = Math.Max(ans, getMax(l, Math.Min(M[p], r), np[p, 0]));
                if (r > M[p]) ans = Math.Max(ans, getMax(Math.Max(l, M[p]), r, np[p, 1]));

                return ans;
            }
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
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}