using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    class P:IComparable<P>
    {
        public int index;
        public List<int>[] adj;
        public Dictionary<int, int>[] weights;
        public long Weight;
        public P(int index)
        {
            this.index = index;
            adj = new List<int>[2];
            adj[0] = new List<int>();
            adj[1] = new List<int>();
            weights = new Dictionary<int, int>[2];
            weights[0] = new Dictionary<int, int>();
            weights[1] = new Dictionary<int, int>();
            Weight = long.MaxValue;
        }
        public int CompareTo(P p)
            => Weight.CompareTo(p.Weight);
    }
    static void Main(string[] args)
    {
        var nmt = Input.ar;
        var ar = Input.ar;
        var ps = Enumerable.Range(0, nmt[0]).Select(v => new P(v)).ToArray();
        for (var i = 0; i < nmt[1]; i++)
        {
            var inp = Input.ar;
            ps[inp[0] - 1].adj[0].Add(inp[1] - 1);
            ps[inp[0] - 1].weights[0][inp[1] - 1] = inp[2];
            ps[inp[1] - 1].adj[1].Add(inp[0] - 1);
            ps[inp[1] - 1].weights[1][inp[0] - 1] = inp[2];
        }
        var wei = new[] { new long[nmt[0]], new long[nmt[0]] };
        for (var i = 0; i < 2; i++) {
            if (i == 1)
                for (var j = 0; j < nmt[0]; j++)
                    ps[j].Weight = long.MaxValue;
            var priQueue = new PriorityQueue<P>(false, new P(-1));
            ps[0].Weight = 0;
            priQueue.Enqueue(ps[0]);
            var bo = new bool[nmt[0]];
            while (!priQueue.isEmpty)
            {
                var u = priQueue.Dequeue();
                bo[u.index] = true;
                foreach (var ad in u.adj[i])
                    if (!bo[ad] && ps[ad].Weight > u.Weight + u.weights[i][ad])
                    {
                        ps[ad].Weight = u.Weight + u.weights[i][ad];
                        wei[i][ad] = ps[ad].Weight;
                        priQueue.Enqueue(ps[ad]);
                    }
            }
        }
        var max = (long)nmt[2]*ar[0];
        for (var i = 1; i < nmt[0]; i++)
            if (wei[0][i] != 0 && wei[1][i] != 0)
            {
                var mo = (nmt[2] - wei[0][i] - wei[1][i]) * ar[i];
                max = Max(max, mo);
            }
        WriteLine(max);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class PriorityQueue<T> where T : IComparable<T>
{
    private readonly List<T> items;
    private T MinValue { get; }//?????????

    public bool IsMax { get; }
    public int Size { get { return items.Count; } }
    public bool isEmpty { get { return items.Count == 0; } }
    
    public PriorityQueue(T minValue) : this(true, minValue)
    {

    }

    public PriorityQueue(bool IsMax, T MinValue)
    {
        this.items = new List<T>();
        this.IsMax = IsMax;
        this.MinValue = MinValue;
    }

    private int Parent(int num)
    {
        return (int)Math.Ceiling((double)num / 2) - 1;
    }
    private int Left(int num)
    { 
        return 2 * num + 1;
    }
    private int Right(int num)
    { 
        return 2 * (num + 1);
    }

    private void MaxHeapify(int num)
    {
        var left = Left(num);
        var right = Right(num);
        var largest = 0;
        if (Size >= left + 1 && items[left].CompareTo(items[num]) == 1)
            largest = left;
        else largest = num;
        if (Size >= right + 1 && items[right].CompareTo(items[largest]) == 1)
            largest = right;
        if (largest != num)
        {
            var value = items[largest];
            items[largest] = items[num];
            items[num] = value;
            MaxHeapify(largest);
        }
    }

    private void MinHeapify(int num)
    {
        var left = Left(num);
        var right = Right(num);
        var smallest = 0;
        if (Size >= left + 1 && items[num].CompareTo(items[left]) == 1) smallest = left;
        else smallest = num;
        if (Size >= right + 1 && items[smallest].CompareTo(items[right]) == 1) smallest = right;
        if (smallest != num)
        {
            var value = items[smallest];
            items[smallest] = items[num];
            items[num] = value;
            MinHeapify(smallest);
        }
    }

    private void BuildHeap()
    {
        for (var i = (int)Math.Ceiling((double)Size / 2) - 1; i >= 0; i--)
        {
            if (IsMax) MaxHeapify(i);
            else MinHeapify(i);
        }
    }

    private bool ChangeKey(int index, T reValue)
    {
        if (IsMax && items[index].CompareTo(reValue) == 1)
            return false;
        if (!IsMax && items[index].CompareTo(reValue) == -1)
            return false;
        items[index] = reValue;
        if (IsMax)
        {
            while (index > 0 && items[Parent(index)].CompareTo(items[index]) == -1)
            {
                var value = items[Parent(index)];
                items[Parent(index)] = items[index];
                items[index] = value;
                index = Parent(index);
            }
        }
        else
        {
            while (index > 0 && items[Parent(index)].CompareTo(items[index]) == 1)
            {
                var value = items[Parent(index)];
                items[Parent(index)] = items[index];
                items[index] = value;
                index = Parent(index);
            }
        }
        return true;
    }

    public T Peek { get { return items[0]; } }

    public T Dequeue()
    {
        if (Size <= 0) return default(T);
        var value = items[0];
        items[0] = items[Size - 1];
        items.RemoveAt(Size - 1);
        if (IsMax) MaxHeapify(0);
        else MinHeapify(0);
        return value;
    }

    public bool Enqueue(T key)
    {
        items.Add(MinValue);
        return ChangeKey(Size - 1, key);
    }

    public bool Delete(int index)
    {
        if (index >= Size)
            return false;
        var value = items[index];
        items[index] = items[Size - 1];
        items[Size - 1] = value;
        items.RemoveAt(Size - 1);
        if (IsMax) MaxHeapify(0);
        else MinHeapify(0);
        return true;
    }
}