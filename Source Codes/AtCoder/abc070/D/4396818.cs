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
        public List<int> ad;
        public Dictionary<int, int> weights;
        public long Weight;
        public P(int index,long weight)
        {
            this.index = index;
            ad = new List<int>();
            weights = new Dictionary<int, int>();
            this.Weight = weight;
        }
        public int CompareTo(P p)
        {
            return Weight.CompareTo(p.Weight);
        }
    }
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ps = new P[num];
        for (var i = 0; i < num; i++)
            ps[i] = new P(i,long.MaxValue);
        for(var i = 0; i < num-1; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            for(var j = 0; j < 2; j++)
            {
                ps[input[j] - 1].ad.Add(input[(j + 1) % 2] - 1);
                ps[input[j] - 1].weights[input[(j + 1) % 2] - 1] = input[2];
            }
        }
        var qk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var NIL = new P(-1,long.MaxValue);
        var priQueue = new PriorityQueue<P>(false,NIL);
        ps[qk[1]-1].Weight = 0;
        priQueue.Enqueue(ps[qk[1]-1]);
        var set = new HashSet<int>();
        while (!priQueue.isEmpty)
        {
            var u = priQueue.Dequeue();
            set.Add(u.index);
            foreach (var ad in u.ad)
            {
                if (!set.Contains(ad) && ps[ad].Weight > u.Weight + u.weights[ad])
                {
                    ps[ad].Weight = u.Weight + u.weights[ad];
                    priQueue.Enqueue(ps[ad]);
                }
            }
        }

        var res = new long[qk[0]];
        for(var i = 0; i < qk[0]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            res[i] = ps[input[0] - 1].Weight + ps[input[1] - 1].Weight;
        }
        res.ToList().ForEach(v => WriteLine(v));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
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

    private bool MaxHeapify(int num)
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
        return true;
    }

    private bool MinHeapify(int num)
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
        return true;
    }

    private bool BuildHeap()
    {
        for (var i = (int)Math.Ceiling((double)Size / 2) - 1; i >= 0; i--)
        {
            if (IsMax) MaxHeapify(i);
            else MinHeapify(i);
        }
        return true;
    }

    private bool ChangeKey(int index, T reValue)
    {
        if (IsMax && items[index].CompareTo(reValue) == 1)
            throw new ArgumentException("???value???value???????????????");
        if (!IsMax && items[index].CompareTo(reValue) == -1)
            throw new ArgumentException("???value???value???????????????");
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
        ChangeKey(Size - 1, key);
        return true;
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