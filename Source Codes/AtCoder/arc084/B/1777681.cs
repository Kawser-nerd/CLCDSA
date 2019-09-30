using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;
using System.Diagnostics;

class Scanner
{
    private readonly char Separator = ' ';
    private int Index = 0;
    private string[] Line = new string[0];
    public string Next()
    {
        if (Index >= Line.Length)
        {
            Line = Console.ReadLine().Split(Separator);
            Index = 0;
        }
        var ret = Line[Index];
        Index++;
        return ret;
    }

    public int NextInt()
    {
        return int.Parse(Next());
    }

    private long NextLong()
    {
        return long.Parse(Next());
    }
}

class Deque<T>
{
    class DequeNode<T>
    {
        public T Item;
        public DequeNode<T> Parent;
        public DequeNode<T> Child;
        public DequeNode(T i, DequeNode<T> p, DequeNode<T> c)
        {
            Item = i;
            Parent = p;
            Child = c;
        }
    }
    private DequeNode<T> First;
    private DequeNode<T> Last;
    public int Count { get; private set; }
    public Deque()
    {
        Count = 0;
        First = null;
        Last = null;
    }
    private void ZeroPush(T item)
    {
        First = new DequeNode<T>(item, null, null);
        Last = First;
    }
    public void PushFront(T item)
    {
        if (Count == 0)
        {
            ZeroPush(item);
        }
        else
        {
            First.Parent = new DequeNode<T>(item, null, First); ;
            First = First.Parent;
        }
        Count++;
    }
    public void PushBack(T item)
    {
        if (Count == 0)
        {
            ZeroPush(item);
        }
        else
        {
            Last.Child = new DequeNode<T>(item, Last, null);
            Last = Last.Child;
        }
        Count++;
    }
    public T PopFront()
    {
        var result = First;
        First = First.Child;
        Count--;
        return result.Item;
    }
    public T PopBack()
    {
        var result = Last;
        Last = Last.Parent;
        Count--;
        return result.Item;
    }
}

struct S
{
    public int Num, Sum;

    public S(int num, int sum)
    {
        this.Num = num;
        this.Sum = sum;
    }
}

class Program
{
    private int K;

    private void Scan()
    {
        var sc = new Scanner();
        K = sc.NextInt();
    }

    public void Solve()
    {
        Scan();
        var ans = new int[K];
        var q = new Deque<S>();
        q.PushBack(new S(1, 1));
        while (q.Count > 0)
        {
            var t = q.PopBack();
            if (ans[t.Num] != 0)
            {
                continue;
            }
            ans[t.Num] = t.Sum;
            q.PushBack(new S((t.Num * 10) % K, t.Sum));
            q.PushFront(new S((t.Num + 1) % K, t.Sum + 1));
        }
        Console.WriteLine(ans[0]);
    }

    static public void Main()
    {
        new Program().Solve();
    }
}