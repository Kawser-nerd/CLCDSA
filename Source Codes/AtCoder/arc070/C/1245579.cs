using System;
using System.Collections.Generic;

class Solver
{
    static Scanner cin;
    public Solver() {}
    public static int Main()
    {
        cin = new Scanner();
        new Solver().solve();
        return 0;
    }
 
    public void solve()
    {
        int n;
        n = cin.nextInt();
        long[] l, r, mid, width;
        l = new long[n];
        r = new long[n];
        mid = new long[n];
        width = new long[n];
        for (int i = 0; i < n; ++i) {
            l[i] = cin.nextLong();
            r[i] = cin.nextLong();
            l[i] *= 2;
            r[i] *= 2;
            width[i] = r[i] - l[i];
            mid[i] = (r[i] + l[i]) / 2;
        }
        long leftOffset, rightOffset;
        leftOffset = rightOffset = 0;
        long minValue = 0;
        
        var left = new PriorityQueue<long>();
        var right = new PriorityQueue<long>((long x, long y) => x > y);
        
        left.Push(mid[0]);
        right.Push(mid[0]);
        
        for (int i = 1; i < n; ++i) {
            long myWidth = (width[i] + width[i-1]) / 2;
            leftOffset -= myWidth;
            rightOffset += myWidth;
            long maxLeft = left.Top();
            long minRight = right.Top();
            
            if (maxLeft + leftOffset <= mid[i] && mid[i] <= minRight + rightOffset) {
                left.Push(mid[i] - leftOffset);
                right.Push(mid[i] - rightOffset);
            } else {
                if (mid[i] < maxLeft + leftOffset) {
                    minValue += maxLeft + leftOffset - mid[i];
                    
                    right.Push(maxLeft + leftOffset - rightOffset);
                    left.Pop();
                    left.Push(mid[i] - leftOffset);
                    left.Push(mid[i] - leftOffset);
                } else {
                    minValue += mid[i] - (minRight + rightOffset);
                    
                    left.Push(minRight + rightOffset - leftOffset);
                    right.Pop();
                    right.Push(mid[i] - rightOffset);
                    right.Push(mid[i] - rightOffset);
                }
            }
        }
        
        Console.WriteLine(minValue / 2);
    }
}

class PriorityQueue<T> where T: IComparable, new()
{
    private List<T> _heap;
    private Func<T, T, bool> _compare;
    
    public PriorityQueue(Func<T, T, bool> compare)
    {
        this.Init();
        _compare = compare;
    }
    
    public PriorityQueue()
    {
        this.Init();
        this._compare = (T x, T y) => x.CompareTo(y) < 0;
    }
    
    public void Init()
    {
        _heap = new List<T>();
        _heap.Add(new T());
    }
    
    public void Push(T x)
    {
        _heap.Add(x);
        for (int i = _heap.Count - 1; i > 1; i /= 2) {
            if (_compare(_heap[i], _heap[i / 2])) {
                return;
            } else {
                Swap(_heap, i, i / 2);
            }
        }
    }
    
    public void Pop()
    {
        int _size = _heap.Count - 1;
        _heap[1] = _heap[_size];
        _heap.RemoveAt(_size);
        _size -= 1;
        for (int i = 1; ;) {
            int j = 2 * i;
            int k = 2 * i + 1;
            if (j > _size) {
                return;
            }
            if (k > _size) {
                if (_compare(_heap[j], _heap[i])) {
                    return;
                }
                Swap(_heap, i, j);
                i = j;
                continue;
            }
            if (_compare(_heap[j], _heap[i]) && _compare(_heap[k], _heap[i])) {
                return;
            }
            if (_compare(_heap[j], _heap[k])) {
                Swap(_heap, i, k);
                i = k;
            } else {
                Swap(_heap, i, j);
                i = j;
            }
        }
    }
    
    public T Top()
    {
        if (this.IsEmpty())
        {
            throw new InvalidOperationException("A priority queue is empty.");
        }
        return _heap[1];
    }
    
    public int GetSize()
    {
        return _heap.Count - 1;
    }
    
    public bool IsEmpty()
    {
        return this.GetSize() == 0;
    }
    
    public void Swap(ref T x, ref T y)
    {
        
        T tmp = x;
        x = y;
        y = tmp;
    }
    
    public void Swap(List<T> list, int indexA, int indexB)
    {
        
        T tmp = list[indexA];
        list[indexA] = list[indexB];
        list[indexB] = tmp;
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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
 
    public double nextDouble()
    {
        return double.Parse(next());
    }
}