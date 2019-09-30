using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class C
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            string[] ps = Console.ReadLine().Split();
            long N = long.Parse(ps[0]);
            long Q = long.Parse(ps[1]);
            long[] E = new long[N];
            long[] S = new long[N];
            for (int i = 0; i < N; i++)
            {
                ps = Console.ReadLine().Split();
                E[i] = long.Parse(ps[0]);
                S[i] = long.Parse(ps[1]);
            }
            long[,] dst = new long[N, N];
            for (int i = 0; i < N; i++)
            {
                ps = Console.ReadLine().Split();
                for (int j = 0; j < N; j++)
                    dst[i, j] = long.Parse(ps[j]);
            }

            Console.Write("Case #" + CASE + ":");
            for(int i = 0; i < Q; i++)
            {
                ps = Console.ReadLine().Split();
                int U = int.Parse(ps[0]) - 1;
                int V = int.Parse(ps[1]) - 1;

                PriorityQueue<State> QQ = new PriorityQueue<State>();
                HashSet<Index> done = new HashSet<Index>();
                
                QQ.Push(new State(U, U, E[U], 0));
                while (true)
                {
                    State top = QQ.Pop();
                    if(top.pos == V)
                    {
                        Console.Write(" " + top.time);
                        break;
                    }
                    Index idx = new Index(top.pos, top.horse, top.dist); //ugh
                    if (done.Contains(idx)) continue;
                    done.Add(idx);

                    for(int j = 0; j < N; j++)
                    {
                        if (dst[top.pos, j] == -1) continue;

                        // Keep our current horse
                        if (dst[top.pos, j] <= top.dist)
                            QQ.Push(new State(j, top.horse, top.dist - dst[top.pos, j], top.time + dst[top.pos, j] / (double)S[top.horse]));

                        // Take another one
                        if (dst[top.pos, j] <= E[top.pos])
                            QQ.Push(new State(j, top.pos, E[top.pos] - dst[top.pos, j], top.time + dst[top.pos, j] / (double)S[top.pos]));
                    }
                }

            }
            Console.WriteLine();
        }
    }

    public class State : IComparable<State>
    {
        public int pos, horse;
        public long dist;
        public double time;

        public State(int pos, int horse, long dist, double time)
        {
            this.pos = pos;
            this.horse = horse;
            this.dist = dist;
            this.time = time;
        }

        public int CompareTo(State other)
        {
            return time.CompareTo(other.time);
        }
    }

    public class Index
    {
        public int pos, horse;
        public long dist;

        public Index(int pos, int horse, long dist)
        {
            this.pos = pos;
            this.horse = horse;
            this.dist = dist;
        }

        public override bool Equals(object obj)
        {
            if (!(obj is Index)) return false;
            Index other = obj as Index;
            return other.pos == pos && other.horse == horse && other.dist == dist;
        }

        public override int GetHashCode()
        {
            return pos * 7 + horse * 3 + dist.GetHashCode();
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
