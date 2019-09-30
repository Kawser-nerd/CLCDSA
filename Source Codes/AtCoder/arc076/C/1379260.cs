using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
//using System.Numerics;  //comment out if AOJ
using System.Text;

using Problem = Tmp.Problem;
using MyIO;

#pragma warning disable   //for AOJ

namespace Tmp
{
    class Problem : IDisposable
    {
        bool IsGCJ;
        int Repeat;
        Scanner sc;
        Printer pr;
        public Problem(bool isGCJ, Scanner scanner, Printer printer)
        {
            sc = scanner;
            pr = printer;
            IsGCJ = isGCJ;
            if (isGCJ) Repeat = sc.nextInt();
            else Read();
        }
        public Problem(bool isGCJ) : this(isGCJ, new Scanner(), new Printer()) { }
        public Problem(bool isGCJ, Scanner scanner) : this(isGCJ, scanner, new Printer()) { }
        public Problem(bool isGCJ, Printer printer) : this(isGCJ, new Scanner(), printer) { }
        public void Solve()
        {
            if (IsGCJ) for (var i = 0; i < Repeat; i++) { Read(); pr.Write("Case #" + (i + 1) + ": "); SolveOne(); }
            else SolveOne();
        }
        public void Dispose()
        {
            sc.Dispose();
            pr.Dispose();
        }
        public int Size { get { return 1; } }
        public const long Mod = 1000000007;

        // ????????????
        // string S;
        // int a;
        
        /// <summary>
        /// ????????????
        /// </summary>
        void Read()
        {

        }
        /// <summary>
        /// ???????????
        /// </summary>
        void SolveOne()
        {
            long r = sc.nextLong();
            long c = sc.nextLong();
            long n = sc.nextLong();
            long big = 10000000000;

            PriorityQueue<Data> p = new PriorityQueue<Data>();

            for (int i = 0; i < n; i++)
            {
                long x1 = sc.nextLong();
                long y1 = sc.nextLong();
                long x2 = sc.nextLong();
                long y2 = sc.nextLong();
                if(((x1 == 0 || x1 ==r) || (y1 == 0 || y1 == c)) &&
                    ((x2 == 0 || x2 == r) || (y2 == 0 || y2 == c)))
                {
                    long place = 0;
                    Data d;
                    if(x1 == 0)
                    {
                        place = big * 6 - y1;
                    }
                    else if(x1 == r)
                    {
                        place = big * 2 + y1;
                    }
                    else if(y1 ==0)
                    {
                        place = x1;
                    }
                    else //(y1==r)
                    {
                        place = big * 4 - x1;
                    }
                    d = new Data(i, place);
                    p.Enqueue(d);

                    if (x2 == 0)
                    {
                        place = big * 6 - y2;
                    }
                    else if (x2 == r)
                    {
                        place = big * 2 + y2;
                    }
                    else if (y2 == 0)
                    {
                        place = x2;
                    }
                    else //(y2==r)
                    {
                        place = big * 4 - x2;
                    }
                    d = new Data(i, place);
                    p.Enqueue(d);
                }
            }
            Stack<long> s = new Stack<long>();
            bool ok = true;
            while(p.Count>0)
            {
                Data d = p.Dequeue();
                if (s.Count == 0) s.Push(d.num);
                else
                {
                    if (s.Peek() == d.num) s.Pop();
                    else s.Push(d.num);
                }
            }
            if (s.Count==0) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
}
class Data:IComparable<Data>
{
    public long num, place;
    public Data(long num, long place)
    {
        this.num = num;
        this.place = place;
    }

    public int CompareTo(Data other)
    {
        return place.CompareTo(other.place);
    }
}

class Program
{
    //public static RandomSFMT rand = new RandomSFMT();
    public static bool IsJudgeMode = true;
    public static bool IsGCJMode = false;
    public static bool IsSolveCreated = true;
    static void Main()
    {
        if (IsJudgeMode)
            if (IsGCJMode) using (var problem = new Problem(true, new Scanner("C-large-practice.in.txt"), new Printer("output.txt"))) problem.Solve();
            else using (var problem = new Problem(false, new Printer())) problem.Solve();
        else
        {
            var num = 1;
            int size = 0;
            decimal time = 0;
            for (var tmp = 0; tmp < num; tmp++)
            {
                using (var P = IsSolveCreated ? new Problem(false, new Scanner("input.txt"), new Printer()) : new Problem(false))
                {
                    size = P.Size;
                    //time += Func.MeasureTime(() => P.Solve());
                }
            }
            Console.WriteLine("{0}, {1}ms", size, time / num);
        }
    }
}

/// <summary>
/// ????????IO
/// </summary>
namespace MyIO
{
    class Printer : IDisposable
    {
        bool isConsole;
        TextWriter file;
        public Printer() { file = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false }; isConsole = true; }
        public Printer(string path) { file = new StreamWriter(path, false) { AutoFlush = false }; isConsole = false; }
        public void Write<T>(T value) { file.Write(value); }
        public void Write(bool b) { file.Write(b ? "YES" : "NO"); }
        public void Write(string str, params object[] args) { file.Write(str, args); }
        public void WriteLine() { file.WriteLine(); }
        public void WriteLine<T>(T value) { file.WriteLine(value); }
        public void WriteLine(bool b) { file.WriteLine(b ? "YES" : "NO"); }
        public void WriteLine<T>(IEnumerable<T> list) { foreach (var x in list) file.WriteLine(x); }
        public void WriteLine<T>(List<T> list) { foreach (var x in list) file.WriteLine(x); }
        public void WriteLine<T>(T[] list) { foreach (var x in list) file.WriteLine(x); }
        public void WriteLine(string str, params object[] args) { file.WriteLine(str, args); }
        public void Dispose() { file.Flush(); if (!isConsole) file.Dispose(); }
    }
    class Scanner : IDisposable
    {
        bool isConsole;
        TextReader file;
        public Scanner() { file = Console.In; }
        public Scanner(string path) { file = new StreamReader(path); isConsole = false; }
        public void Dispose() { if (!isConsole) file.Dispose(); }

        #region next????
        string[] nextBuffer = new string[0];
        int BufferCnt = 0;

        char[] cs = new char[] { ' ' };

        public string next()
        {
            while (BufferCnt >= nextBuffer.Length)
            {
                string st = file.ReadLine();
                while (st == "") st = file.ReadLine();
                nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
                BufferCnt = 0;
            }
            return nextBuffer[BufferCnt++];
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

        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public string[] next(int n) { return enumerate(n, next); }
        public double[] nextDouble(int n) { return enumerate(n, nextDouble); }
        public int[] nextInt(int n) { return enumerate(n, nextInt); }
        public long[] nextLong(int n) { return enumerate(n, nextLong); }
        #endregion
    }
}

/// <summary>
/// ????
/// </summary>
static partial class Func
{
    public const int Inf = 1073741789;  // 2 * Inf < int.MaxValue, and Inf is a prime number
    public const long InfL = 4011686018427387913L;  // 2 * InfL < long.MaxValue, and InfL is a prime number
    public static Comparison<T> DefaultComparison<T>() { return (x, y) => Comparer<T>.Default.Compare(x, y); }
    public static Comparison<T> ToComparison<T>(this IComparer<T> comp) { return comp == null ? DefaultComparison<T>() : (x, y) => comp.Compare(x, y); }
    /// <summary>
    /// Find the first number x such that pred(x) is true
    /// if pred(x) is false for all min&lt;=x&lt;max, then return max
    /// in other words, pred(max) is assumed to be true
    /// </summary>
    /// <param name="min">inclusive lower limit</param>
    /// <param name="max">exclusive upper limit</param>
    /// <param name="pred">monotonous predicate, i.e. if pred(a) and a&lt;b, then pred(b)</param>
    /// <returns>first number such that satisfy pred</returns>
    public static long FirstBinary(long min, long max, Predicate<long> pred)
    {
        while (min < max)
        {
            var mid = (min + max) / 2;
            if (pred(mid)) max = mid;
            else min = mid + 1;
        }
        return min;
    }
    /// <summary>
    /// Find the first number x such that pred(x) is true
    /// if pred(x) is false for all min&lt;=x&lt;max, then return max
    /// in other words, pred(max) is assumed to be true
    /// </summary>
    /// <param name="min">inclusive lower limit</param>
    /// <param name="max">exclusive upper limit</param>
    /// <param name="pred">monotonous predicate, i.e. if pred(a) and a&lt;b, then pred(b)</param>
    /// <returns>first number such that satisfy pred</returns>
    public static int FirstBinary(int min, int max, Predicate<int> pred)
    {
        while (min < max)
        {
            var mid = (min + max) / 2;
            if (pred(mid)) max = mid;
            else min = mid + 1;
        }
        return min;
    }
    public static void Swap<T>(this IList<T> array, int i, int j) { var tmp = array[i]; array[i] = array[j]; array[j] = tmp; }
    public static void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
}


/// <summary>
/// C++?STL????
/// </summary>
#region STL
class PriorityQueue<T> : IEnumerable<T>, ICollection, IEnumerable, ICloneable
{
    Comparison<T> comp;
    List<T> list;
    public int Count { get; private set; }
    public bool IsEmpty { get { return Count == 0; } }
    public PriorityQueue(IEnumerable<T> source) : this((Comparison<T>)null, 0, source) { }
    public PriorityQueue(int capacity = 0, IEnumerable<T> source = null) : this((Comparison<T>)null, capacity, source) { }
    public PriorityQueue(IComparer<T> comp, IEnumerable<T> source) : this(comp.ToComparison(), source) { }
    public PriorityQueue(IComparer<T> comp, int capacity = 0, IEnumerable<T> source = null) : this(comp.ToComparison(), source) { list.Capacity = capacity; }
    public PriorityQueue(Comparison<T> comp, IEnumerable<T> source) : this(comp, 0, source) { }
    public PriorityQueue(Comparison<T> comp, int capacity = 0, IEnumerable<T> source = null) { this.comp = comp == null ? Func.DefaultComparison<T>() : comp; list = new List<T>(capacity); if (source != null) foreach (var x in source) Enqueue(x); }
    /// <summary>
    /// add an item
    /// this is an O(log n) operation
    /// </summary>
    /// <param name="x">item</param>
    public void Enqueue(T x)
    {
        var pos = Count++;
        list.Add(x);
        while (pos > 0)
        {
            var p = (pos - 1) / 2;
            if (comp(list[p], x) <= 0) break;
            list[pos] = list[p];
            pos = p;
        }
        list[pos] = x;
    }
    /// <summary>
    /// return the minimum element and remove it
    /// this is an O(log n) operation
    /// </summary>
    /// <returns>the minimum</returns>
    public T Dequeue()
    {
        var value = list[0];
        var x = list[--Count];
        list.RemoveAt(Count);
        if (Count == 0) return value;
        var pos = 0;
        while (pos * 2 + 1 < Count)
        {
            var a = 2 * pos + 1;
            var b = 2 * pos + 2;
            if (b < Count && comp(list[b], list[a]) < 0) a = b;
            if (comp(list[a], x) >= 0) break;
            list[pos] = list[a];
            pos = a;
        }
        list[pos] = x;
        return value;
    }
    /// <summary>
    /// look at the minimum element
    /// this is an O(1) operation
    /// </summary>
    /// <returns>the minimum</returns>
    public T Peek() { return list[0]; }
    public IEnumerator<T> GetEnumerator() { var x = (PriorityQueue<T>)Clone(); while (x.Count > 0) yield return x.Dequeue(); }
    void CopyTo(Array array, int index) { foreach (var x in this) array.SetValue(x, index++); }
    public object Clone() { var x = new PriorityQueue<T>(comp, Count); x.list.AddRange(list); return x; }
    public void Clear() { list = new List<T>(); Count = 0; }
    public void TrimExcess() { list.TrimExcess(); }
    /// <summary>
    /// check whether item is in this queue
    /// this is an O(n) operation
    /// </summary>
    public bool Contains(T item) { return list.Contains(item); }
    IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
    void ICollection.CopyTo(Array array, int index) { CopyTo(array, index); }
    bool ICollection.IsSynchronized { get { return false; } }
    object ICollection.SyncRoot { get { return this; } }
}
class Deque<T>
{
    T[] array;
    int offset, capacity;
    public int Count { get; protected set; }
    public Deque(int capacity) { array = new T[this.capacity = capacity]; Count = 0; offset = 0; }
    public Deque() : this(16) { }
    public T this[int index] { get { return array[GetIndex(index)]; } set { array[GetIndex(index)] = value; } }
    int GetIndex(int index) { var tmp = index + offset; return tmp >= capacity ? tmp - capacity : tmp; }
    public T PeekFront() { return array[offset]; }
    public T PeekBack() { return array[GetIndex(Count - 1)]; }
    public void PushFront(T item)
    {
        if (Count == capacity) Extend();
        if (--offset < 0) offset += array.Length;
        array[offset] = item;
        Count++;
    }
    public T PopFront()
    {
        Count--;
        var tmp = array[offset++];
        if (offset >= capacity) offset -= capacity;
        return tmp;
    }
    public void PushBack(T item)
    {
        if (Count == capacity) Extend();
        var id = (Count++) + offset;
        if (id >= capacity) id -= capacity;
        array[id] = item;
    }
    public T PopBack() { return array[GetIndex(--Count)]; }
    public void Insert(int index, T item)
    {
        PushFront(item);
        for (var i = 0; i < index; i++) this[i] = this[i + 1];
        this[index] = item;
    }
    public T RemoveAt(int index)
    {
        var tmp = this[index];
        for (var i = index; i > 0; i--) this[i] = this[i - 1];
        PopFront();
        return tmp;
    }
    void Extend()
    {
        var newArray = new T[capacity << 1];
        if (offset > capacity - Count)
        {
            var length = array.Length - offset;
            Array.Copy(array, offset, newArray, 0, length);
            Array.Copy(array, 0, newArray, length, Count - length);
        }
        else Array.Copy(array, offset, newArray, 0, Count);
        array = newArray;
        offset = 0;
        capacity <<= 1;
    }
}
class PairComparer<S, T> : IComparer<Pair<S, T>>
    where S : IComparable<S>
    where T : IComparable<T>
{
    public PairComparer() { }
    public int Compare(Pair<S, T> x, Pair<S, T> y)
    {
        var p = x.First.CompareTo(y.First);
        if (p != 0) return p;
        else return x.Second.CompareTo(y.Second);
    }
}
class Pair<S, T>
{
    public S First;
    public T Second;
    public Pair() { First = default(S); Second = default(T); }
    public Pair(S s, T t) { First = s; Second = t; }
    public override string ToString() { return string.Format("({0}, {1})", First, Second); }
    public override int GetHashCode() { return First.GetHashCode() ^ Second.GetHashCode(); }
    public override bool Equals(object obj)
    {
        if (ReferenceEquals(this, obj)) return true;
        else if (obj == null) return false;
        var tmp = obj as Pair<S, T>;
        return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
    }
}
#endregion //STL