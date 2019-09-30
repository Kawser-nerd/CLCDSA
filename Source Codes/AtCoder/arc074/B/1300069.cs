using System;
using System.Collections.Generic;
using System.Linq;
using System.Collections;
using System.Linq.Expressions;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N;
    private int[] A;
    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        A = new int[N * 3];
        var line = Console.ReadLine().Split(' ');
        for (int i = 0; i < N * 3; i++)
        {
            A[i] = int.Parse(line[i]);
        }
    }

    public void Solve()
    {
        Scan();
        PriortyQueue<int>pq = new PriortyQueue<int>((a, b) => -a.CompareTo(b));
        long[] memoR = new long[N+1];
        long sum = 0;
        for(int i = 0; i < N; i++)
        {
            pq.Add(A[i]);
            sum += A[i];
        }
        memoR[0] = sum;
        for(int i = 0; i < N; i++)
        {
            sum += A[N + i];
            pq.Add(A[N + i]);
            sum -= pq.Poll();
            memoR[i + 1] = sum;
        }
        sum = 0;
        pq = new PriortyQueue<int>((a, b) => a.CompareTo(b));
        long[] memoL = new long[N + 1];
        for(int i = 0; i < N; i++)
        {
            pq.Add(A[3 * N - 1 - i]);
            sum += A[3 * N - 1 - i];
        }
        memoL[N] = sum;
        for(int i = 0; i < N; i++)
        {
            sum += A[2 * N - 1 - i];
            pq.Add(A[2 * N - 1 - i]);
            sum -= pq.Poll();
            memoL[N - 1 - i] = sum;
        }
        long ans = long.MinValue;
        for(int i = 0; i <= N; i++)
        {
            ans = Math.Max(ans, memoR[i] - memoL[i]);
        }
        Console.WriteLine(ans);
    }
}

public class PriortyQueue<T>
{
    private Comparison<T> Comparator;
    private List<T> L;
    public PriortyQueue(Comparison<T> comparator)
    {
        Clear();
        Comparator = comparator;
    }
    public PriortyQueue(PriortyQueue<T> queue)
    {
        L = queue.ToList();
        Comparator = queue.Comparator;
    }
    public void Add(T item)
    {
        int n = L.Count;
        L.Add(item);
        while (n > 0)
        {
            int i = (n - 1) / 2;
            if (Comparator(L[n], L[i]) > 0)
            {
                Swap(n, i);
            }
            n = i;
        }
    }
    public T Poll()
    {
        T ret = Peak();
        Pop();
        return ret;
    }
    public void Pop()
    {
        int n = L.Count - 1;
        L[0] = L[n];
        L.RemoveAt(n);
        for (int i = 0, j; (j = 2 * i + 1) < n;)
        {
            if ((j != n - 1) && (Comparator(L[j], L[j + 1]) < 0))
            {
                j++;
            }

            if (Comparator(L[i], L[j]) < 0)
            {
                Swap(i, j);
            }
            i = j;
        }
    }
    public T Peak()
    {
        return L[0];
    }
    public T[] ToArray()
    {
        return L.ToArray();
    }
    public List<T> ToList()
    {
        return L.ToList();
    }
    public void Clear()
    {
        L = new List<T>();
    }
    public int Size
    {
        get { return L.Count; }
    }
    public bool IsEmpty
    {
        get { return L.Count == 0; }
    }
    private void Swap(int a, int b)
    {
        T temp = L[a];
        L[a] = L[b];
        L[b] = temp;
    }
}