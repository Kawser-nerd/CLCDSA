using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class A
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            int N = int.Parse(Console.ReadLine());
            d = new int[N];
            l = new int[N];
            for (int i = 0; i < N; i++)
            {
                string[] p = Console.ReadLine().Split();
                d[i] = int.Parse(p[0]);
                l[i] = int.Parse(p[1]);
            }
            int D = int.Parse(Console.ReadLine());
            bool[] done = new bool[N];
            bool[] inQ = new bool[N];
            bool ans = false;
            PriorityQueue<State> Q = new PriorityQueue<State>();
            Q.Push(new State(0, d[0]));
            while (Q.Count > 0)
            {
                State top = Q.Pop();
                if (done[top.i]) continue;
                done[top.i] = true;
                for (int j = top.i + 1; j < N; j++)
                {
                    if (d[top.i] + Math.Min(l[top.i], top.reachl) < d[j]) break;
                    if (inQ[j]) continue;
                    Q.Push(new State(j, d[j] - d[top.i]));
                    inQ[j] = true;
                }
                if (d[top.i] + Math.Min(l[top.i], top.reachl) >= D)
                {
                    ans = true;
                    break;
                }
            }

            Console.WriteLine("Case #" + CASE + ": " + (ans ? "YES": "NO"));
        }
    }
    static int[] l, d;
    
    class State : IComparable<State>
    {
        public int i, reachl;

        public State(int i, int reachl)
        {
            this.i = i;
            this.reachl = reachl;
        }

        public int CompareTo(State other)
        {
            if (i != other.i) return i.CompareTo(other.i);
            return other.reachl.CompareTo(reachl);
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
