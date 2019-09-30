using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Deque<T>
{
    T[] buf;
    int offset, count, capacity;

    public int Count { get { return count; } }

    public Deque(int cap)
    {
        buf = new T[capacity = cap];
    }

    public Deque()
    {
        buf = new T[capacity = 16];
    }

    public T this [int index]
    {
        get { return buf[getIndex(index)]; }
        set { buf[getIndex(index)] = value; }
    }

    private int getIndex(int index)
    {
        if (index >= capacity)
            throw new IndexOutOfRangeException("out of range");
        var ret = index + offset;
        if (ret >= capacity)
            ret -= capacity;
        return ret;
    }

    public void PushFront(T item)
    {
        if (count == capacity)
            Extend();
        if (--offset < 0)
            offset += buf.Length;
        buf[offset] = item;
        ++count;
    }

    public T PopFront()
    {
        if (count == 0)
            throw new InvalidOperationException("collection is empty");
        --count;
        var ret = buf[offset++];
        if (offset >= capacity)
            offset -= capacity;
        return ret;
    }

    public void PushBack(T item)
    {
        if (count == capacity)
            Extend();
        var id = count++ + offset;
        if (id >= capacity)
            id -= capacity;
        buf[id] = item;
    }

    public T PopBack()
    {
        if (count == 0)
            throw new InvalidOperationException("collection is empty");
        return buf[getIndex(--count)];
    }

    public void Insert(int index, T item)
    {
        if (index > count)
            throw new IndexOutOfRangeException();
        this.PushFront(item);
        for (int i = 0; i < index; i++)
            this[i] = this[i + 1];
        this[index] = item;
    }

    public T RemoveAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();
        var ret = this[index];
        for (int i = index; i > 0; i--)
            this[i] = this[i - 1];
        this.PopFront();
        return ret;
    }

    private void Extend()
    {
        T[] newBuffer = new T[capacity << 1];
        if (offset > capacity - count)
        {
            var len = buf.Length - offset;
            Array.Copy(buf, offset, newBuffer, 0, len);
            Array.Copy(buf, 0, newBuffer, len, count - len);
        }
        else
            Array.Copy(buf, offset, newBuffer, 0, count);
        buf = newBuffer;
        offset = 0;
        capacity <<= 1;
    }

    public T[] Items//????????????????????
    {
        get
        {
            var a = new T[count];
            for (int i = 0; i < count; i++)
                a[i] = this[i];
            return a;
        }
    }
}

class Scanner
{
    private string[] Line;
    private int Index;

    public Scanner()
    {
        Line = new string[0];
        Index = 0;
    }

    public string Next()
    {
        if (Index >= Line.Length)
        {
            Line = Console.ReadLine().Split(' ');
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