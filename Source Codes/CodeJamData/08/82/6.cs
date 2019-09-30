using System;
using System.Collections;
using System.Text;

public class B
{
    public static void Main(string[] args)
    {
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            int N = int.Parse(Console.ReadLine());
            string[] color = new string[N];
            int[] A = new int[N];
            int[] B = new int[N];
            for (int i = 0; i < N; i++)
            {
                string[] p = Console.ReadLine().Split();
                color[i] = p[0];
                A[i] = int.Parse(p[1]);
                B[i] = int.Parse(p[2]);
            }
            State ans = null;
            PriorityQueue<State> Q = new PriorityQueue<State>();
            Q.Push(new State(0, 0));
            while (Q.Count > 0)
            {
                State top = Q.Pop();
                if (top.act == 10000)
                {
                    ans = top;
                    break;
                }
                for (int i = 0; i < N; i++)
                {
                    if (A[i] <= top.act + 1 && top.act < B[i] && (top.colors.Count < 3 || top.colors.Contains(color[i])))
                    {
                        State newstate = new State(B[i], top.numoffers + 1);
                        foreach (object c in top.colors) newstate.colors.Add(c);
                        if (!newstate.colors.Contains(color[i]))
                            newstate.colors.Add(color[i]);
                        Q.Push(newstate);
                    }
                }
            }
            Console.WriteLine("Case #" + CASE + ": " + (ans == null ? "IMPOSSIBLE" : ans.numoffers.ToString()));
        }
    }

    public class State : IComparable<State>
    {
        public ArrayList colors = new ArrayList();
        public int act, numoffers;

        public State(int a, int o)
        {
            act = a;
            numoffers = o;
        }

        public int CompareTo(State other)
        {
            return numoffers - other.numoffers;
        }
    }
}

public class PriorityQueue<T>
{
    private T[] list;
    public int Count;
    public System.Collections.Generic.Comparer<T> Comparer;

    public PriorityQueue()
    {
        list = new T[16];
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
