using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    class G:IComparable<G>
    {
        public int h;
        public int w;
        public long Weight;
        public bool isWhite;
        public G(int h,int w,bool isWhite,long Weight=Input.Inf)
        {
            this.h = h;
            this.w = w;
            this.Weight = Weight;
            this.isWhite = isWhite;
        }
        public int CompareTo(G g)
        => Weight.CompareTo(g.Weight);
    }
    static void Main(string[] args)
    {
        var hwt = Input.ar;
        var gred = Enumerable.Repeat(0, hwt[0]).Select(v => ReadLine()).ToArray();
        var gs = new G[hwt[0], hwt[1]];
        var st = new Tuple<int, int>(-1,-1);
        var go = new Tuple<int, int>(-1, -1);
        for (var i = 0; i < hwt[0]; i++)
            for (var j = 0; j < hwt[1]; j++)
            {
                if (gred[i][j] == 'S')
                    st = new Tuple<int, int>(i, j);
                if (gred[i][j] == 'G')
                    go = new Tuple<int, int>(i, j);
                gs[i, j] = new G(i, j, gred[i][j] != '#');
            }
        var gh = new[] { 0, 0, -1, 1 };
        var gw = new[] { 1, -1, 0, 0 };
        gs[st.Item1, st.Item2].Weight = 0;
        var left = 0L;
        long right = hwt[2];
        while (right - left > 1)
        {
            var mid = (right + left) / 2;
            var pq = new PriorityQueue<G>(false, new G(-1, -1, false, long.MaxValue));
            for (var i = 0; i < hwt[0]; i++)
                for (var j = 0; j < hwt[1]; j++)
                    if (st.Item1 != i || st.Item2 != j)
                        gs[i, j].Weight = Input.Inf;
            pq.Enqueue(gs[st.Item1, st.Item2]);
            while (!pq.isEmpty)
            {
                var p = pq.Dequeue();
                for(var i = 0; i < 4; i++)
                {
                    var h = gh[i] + p.h;
                    var w = gw[i] + p.w;
                    if (Search.IsInside(h, w, hwt) && gs[h, w].Weight > p.Weight + (gs[h, w].isWhite ? 1 : mid))
                    {
                        gs[h, w].Weight = p.Weight + (gs[h, w].isWhite ? 1 : mid);
                        pq.Enqueue(gs[h, w]);
                    }
                }
            }
            if (gs[go.Item1,go.Item2].Weight > hwt[2]) right = mid;
            else left = mid;
        }
        WriteLine(left);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static string[] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read).ToArray();
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public static Tuple<int, int, long> MakeEdge(int num1, int num2, long weight=Inf)
        => new Tuple<int, int, long>(num1, num2, weight);
    public const long Inf = (long)1e18;
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class Search
{
    public static int UpperBound<T>(T[] array,T value)
        where T:IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) == 1) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static int LowerBound<T>(T[] array,T value)
        where T : IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) != -1) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static T Max<T>(params T[] array)
        => array.Max();
    public static T Min<T>(params T[] array)
        => array.Min();
    public static bool IsInside(int h, int w, int[] hw)
        => 0 <= h && h < hw[0] && 0 <= w && w < hw[1];
    public static bool IsPrime(long num)
    {
        if (num % 2 == 0) return false;
        for (var i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
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