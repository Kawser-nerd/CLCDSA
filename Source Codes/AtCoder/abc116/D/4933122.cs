using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using Debug;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        Solve();
        //WriteLine(Solve());
    }
    class G:IComparable<G>
    {
        public int t;
        public int d;
        public G(int[] td)
        {
            t = td[0];
            d = td[1];
        }
        public int CompareTo(G g)
            => d.CompareTo(g.d);
    }
    static void Solve()
    {
        var nk = Input.ar;
        var gs = Enumerable.Repeat(0, nk[0]).Select(_ => new G(Input.ar)).ToArray();
        gs = gs.OrderByDescending(v => v).ToArray();
        var pq = new PriorityQueue<G>(new G(new[] { -1, int.MaxValue }), false);
        var ct = 0L;
        var ts = new bool[nk[0]];
        var sum = 0L;
        var res = 0L;
        for(var i = 0; i < nk[0]; i++)
        {
            if (i < nk[1])
            {
                sum += gs[i].d;
                if (!ts[gs[i].t - 1])
                {
                    ct++;
                    ts[gs[i].t - 1] = true;
                }
                else
                    pq.Enqueue(gs[i]);
            }
            else
            {
                if (ts[gs[i].t - 1]||pq.isEmpty) continue;
                ct++;
                sum += gs[i].d;
                ts[gs[i].t - 1] = true;
                sum -= pq.Dequeue().d;
            }
            res = Max(res, ct * ct + sum);
        }
        WriteLine(res);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static char[][] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read.ToCharArray()).ToArray();
    public static int[][] ar2D(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] arL2D(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
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
    
    public PriorityQueue(T MinValue,bool IsMax=true)
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
        return ChangeKey(Size-1, key);
    }

    private bool Delete(int index)
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