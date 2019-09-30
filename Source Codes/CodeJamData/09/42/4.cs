using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            string[] parts = Console.ReadLine().Split();
            int R = int.Parse(parts[0]);
            int C = int.Parse(parts[1]);
            int F = int.Parse(parts[2]);
            string[] map = new string[R];
            for (int i = 0; i < R; i++)
            {
                map[i] = Console.ReadLine();
            }

            PriorityQueue<Node> Q = new PriorityQueue<Node>();
            Q.Push(new Node(0, 0, 0, 0, 0));
            bool[, , ,] done = new bool[R, C, 1 << 8, 1 << 8];
            string ret = "No";
            while (Q.Count > 0)
            {
                Node top = Q.Pop();
                if (done[top.r, top.c, top.maskl, top.maska])
                    continue;
                done[top.r, top.c, top.maskl, top.maska] = true;

                // Will we fall now?
                if (isEmpty(top.r + 1, top.c, top, map))
                {
                    int fall = 0;
                    int nr = top.r + 1;
                    while (nr < R && isEmpty(nr, top.c, top, map))
                    {
                        nr++;
                        fall++;
                    }
                    if (fall > F) continue;
                    if (nr == R)
                    {
                        ret = "Yes " + top.digs;
                        break;
                    }

                    Q.Push(new Node(nr - 1, top.c, fall == 1 ? top.maska : 0, 0, top.digs));
                    continue;
                }

                //  Walk
                if (top.c > 0 && isEmpty(top.r, top.c - 1, top, map))
                { // left
                    Q.Push(new Node(top.r, top.c - 1, top.maskl, top.maska, top.digs));
                }
                if (top.c < C - 1 && isEmpty(top.r, top.c + 1, top, map))
                { // right
                    Q.Push(new Node(top.r, top.c + 1, top.maskl, top.maska, top.digs));
                }

                // Dig
                if (top.c > 0 && isEmpty(top.r, top.c - 1, top, map) && !isEmpty(top.r + 1, top.c - 1, top, map))
                {
                    Q.Push(new Node(top.r, top.c, top.maskl, top.maska | (1 << (top.c - 1)), top.digs + 1));
                }
                if (top.c < C - 1 && isEmpty(top.r, top.c + 1, top, map) && !isEmpty(top.r + 1, top.c + 1, top, map))
                {
                    Q.Push(new Node(top.r, top.c, top.maskl, top.maska | (1 << (top.c + 1)), top.digs + 1));
                }
            }

            Console.WriteLine("Case #" + CASE + ": " + ret);
        }
    }

    public static bool isEmpty(int r, int c, Node n, string[] map)
    {
        return map[r][c] == '.' || (n.r == r && (n.maskl & (1 << c)) > 0) || (n.r + 1 == r && (n.maska & (1 << c)) > 0);
    }

    public class Node : IComparable<Node>
    {
        public int r, c, maskl, maska, digs;

        public Node(int r, int c, int maskl, int maska, int digs)
        {
            this.r = r;
            this.c = c;
            this.maskl = maskl;
            this.maska = maska;
            this.digs = digs;
        }

        public int CompareTo(Node other)
        {
            return digs - other.digs;
        }
    }


    public class PriorityQueue<T>
    {
        private T[] list;
        public int Count;
        public System.Collections.Generic.Comparer<T> Comparer;

        public PriorityQueue()
        {
            list = new T[1024];
            Count = 0;
            Comparer = System.Collections.Generic.Comparer<T>.Default;
        }

        public void Push(T value)
        {
            if (Count == list.Length)
            {
                T[] tmp = new T[list.Length * 2];
                System.Array.Copy(list, tmp, list.Length);
                list = tmp;
            }
            list[Count++] = value;
            int i = Count - 1;
            while (i > 0 && Comparer.Compare(list[i], list[parent(i)]) < 0)
            {
                T tmp = list[i];
                list[i] = list[parent(i)];
                list[parent(i)] = tmp;
                i = parent(i);
            }
        }

        public T Pop()
        {
            T ret = list[0];
            list[0] = list[--Count];
            int i = 0;
            while (true)
            {
                int left = (i * 2) + 1;
                if (left >= Count) break;
                int right = left + 1;
                int ind = left;
                if (right < Count && Comparer.Compare(list[left], list[right]) > 0)
                    ind = right;
                if (Comparer.Compare(list[i], list[ind]) >= 0)
                {
                    T tmp = list[i];
                    list[i] = list[ind];
                    list[ind] = tmp;
                    i = ind;
                }
                else break;
            }
            return ret;
        }

        private int parent(int i)
        {
            return (i - 1) / 2;
        }
    }
}
