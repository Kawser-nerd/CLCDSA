using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (?°?°)??e??????????????????????????
public class Solver
{
    public class Treap<T>
    {
        private static Random rnd = new Random(13);

        public T Max, Min;

        public class Node
        {
            public readonly T Value;
            public readonly int Priority;
            public Node Left, Right;
            public Node(T value)
            {
                Value = value;
                Priority = rnd.Next();
            }
        }

        private class NodePair
        {
            public Node Left, Right;
            public NodePair(Node left, Node right)
            {
                Left = left;
                Right = right;
            }
        }

        private Node root;
        private readonly Comparison<T> compare;

        public Treap()
            : this(Comparer<T>.Default.Compare)
        {
        }

        public Treap(Comparison<T> compare)
        {
            this.compare = compare;
        }

        public void Add(T value)
        {
            NodePair pair = Split(root, value);
            root = Merge(Merge(pair.Left, new Node(value)), pair.Right);
            if (compare(Max, value) < 0)
                Max = value;
            if (compare(Min, value) > 0)
                Min = value;
        }

        public void Remove(T value)
        {
            root = Remove(root, value);
            if (compare(Min, value) == 0)
                Min = pMin(root);
            if (compare(Max, value) == 0)
                Max = pMax(root);
        }

        private NodePair Split(Node node, T value)
        {
            if (node == null)
                return new NodePair(null, null);
            if (compare(node.Value, value) >= 0)
            {
                NodePair leftSplit = Split(node.Left, value);
                node.Left = leftSplit.Right;
                leftSplit.Right = node;
                return leftSplit;
            }
            else
            {
                NodePair rightSplit = Split(node.Right, value);
                node.Right = rightSplit.Left;
                rightSplit.Left = node;
                return rightSplit;
            }
        }

        private Node Remove(Node node, T value)
        {
            if (node == null)
                return null;
            if (compare(value, node.Value) < 0)
            {
                node.Left = Remove(node.Left, value);
                return node;
            }
            if (compare(value, node.Value) > 0)
            {
                node.Right = Remove(node.Right, value);
                return node;
            }
            return Merge(node.Left, node.Right);
        }

        private static Node Merge(Node left, Node right)
        {
            if (left == null)
                return right;
            if (right == null)
                return left;
            if (left.Priority > right.Priority)
            {
                left.Right = Merge(left.Right, right);
                return left;
            }
            else
            {
                right.Left = Merge(left, right.Left);
                return right;
            }
        }

        private T pMin(Node node)
        {
            if (node.Left != null)
                return pMin(node.Left);
            return node.Value;
        }

        private T pMax(Node node)
        {
            if (node.Right != null)
                return pMax(node.Right);
            return node.Value;
        }
    }

    public class Heap<T>
    {
        private readonly List<T> data;
        private readonly Comparison<T> compare;

        public Heap(Comparison<T> compare)
        {
            this.compare = compare;
            data = new List<T> { default(T) };
        }

        public int Count
        {
            get { return data.Count - 1; }
        }

        public T Peek()
        {
            return data[1];
        }

        public void Push(T item)
        {
            data.Add(item);
            var curPlace = Count;
            while (curPlace > 1 && compare(item, data[curPlace / 2]) < 0)
            {
                data[curPlace] = data[curPlace / 2];
                data[curPlace / 2] = item;
                curPlace /= 2;
            }
        }

        public T Pop()
        {
            var ret = data[1];
            data[1] = data[Count];
            data.RemoveAt(Count);
            var curPlace = 1;
            while (true)
            {
                var max = curPlace;
                if (Count >= curPlace * 2 && compare(data[max], data[2 * curPlace]) > 0)
                    max = 2 * curPlace;
                if (Count >= curPlace * 2 + 1 && compare(data[max], data[2 * curPlace + 1]) > 0)
                    max = 2 * curPlace + 1;
                if (max == curPlace)
                    break;
                var item = data[max];
                data[max] = data[curPlace];
                data[curPlace] = item;
                curPlace = max;
            }

            return ret;
        }
    }

    public void Solve()
    {
        int n = ReadInt();
        var a = ReadIntMatrix(n);

        var q = new Heap<int[]>((t1, t2) => t1[0].CompareTo(t2[0]));
        var tr1 = new Treap<int>();
        var tr2 = new Treap<int>();
        tr1.Max = tr2.Max = int.MinValue;
        tr1.Min = tr2.Min = int.MaxValue;
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] > a[i][1])
            {
                int t = a[i][0];
                a[i][0] = a[i][1];
                a[i][1] = t;
            }
            q.Push(a[i]);
            tr1.Add(a[i][0]);
            tr2.Add(a[i][1]);
        }

        long ans = 1L * (tr1.Max - tr1.Min) * (tr2.Max - tr2.Min);
        while (q.Count > 0)
        {
            var t = q.Pop();
            tr1.Add(t[1]);
            tr1.Remove(t[0]);
            tr2.Add(t[0]);
            tr2.Remove(t[1]);
            ans = Math.Min(ans, 1L * (tr1.Max - tr1.Min) * (tr2.Max - tr2.Min));
        }

        Write(ans);
    }

    #region Main

    protected static TextReader reader;
    protected static TextWriter writer;
    static void Main()
    {
#if DEBUG
        reader = new StreamReader("..\\..\\input.txt");
        //reader = new StreamReader(Console.OpenStandardInput());
        writer = Console.Out;
        //writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("input.txt");
        //writer = new StreamWriter("output.txt");
#endif
        try
        {
            new Solver().Solve();
            //var thread = new Thread(new Solver().Solve, 1024 * 1024 * 256);
            //thread.Start();
            //thread.Join();
        }
        catch (Exception ex)
        {
#if DEBUG
            Console.WriteLine(ex);
#else
            throw;
#endif
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read / Write
    private static Queue<string> currentLineTokens = new Queue<string>();
    private static string[] ReadAndSplitLine() { return reader.ReadLine().Split(new[] { ' ', '\t', }, StringSplitOptions.RemoveEmptyEntries); }
    public static string ReadToken() { while (currentLineTokens.Count == 0)currentLineTokens = new Queue<string>(ReadAndSplitLine()); return currentLineTokens.Dequeue(); }
    public static int ReadInt() { return int.Parse(ReadToken()); }
    public static long ReadLong() { return long.Parse(ReadToken()); }
    public static double ReadDouble() { return double.Parse(ReadToken(), CultureInfo.InvariantCulture); }
    public static int[] ReadIntArray() { return ReadAndSplitLine().Select(int.Parse).ToArray(); }
    public static long[] ReadLongArray() { return ReadAndSplitLine().Select(long.Parse).ToArray(); }
    public static double[] ReadDoubleArray() { return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray(); }
    public static int[][] ReadIntMatrix(int numberOfRows) { int[][] matrix = new int[numberOfRows][]; for (int i = 0; i < numberOfRows; i++)matrix[i] = ReadIntArray(); return matrix; }
    public static int[][] ReadAndTransposeIntMatrix(int numberOfRows)
    {
        int[][] matrix = ReadIntMatrix(numberOfRows); int[][] ret = new int[matrix[0].Length][];
        for (int i = 0; i < ret.Length; i++) { ret[i] = new int[numberOfRows]; for (int j = 0; j < numberOfRows; j++)ret[i][j] = matrix[j][i]; } return ret;
    }
    public static string[] ReadLines(int quantity) { string[] lines = new string[quantity]; for (int i = 0; i < quantity; i++)lines[i] = reader.ReadLine().Trim(); return lines; }
    public static void WriteArray<T>(IEnumerable<T> array) { writer.WriteLine(string.Join(" ", array)); }
    public static void Write(params object[] array) { WriteArray(array); }
    public static void WriteLines<T>(IEnumerable<T> array) { foreach (var a in array)writer.WriteLine(a); }
    private class SDictionary<TKey, TValue> : Dictionary<TKey, TValue>
    {
        public new TValue this[TKey key]
        {
            get { return ContainsKey(key) ? base[key] : default(TValue); }
            set { base[key] = value; }
        }
    }
    private static T[] Init<T>(int size) where T : new() { var ret = new T[size]; for (int i = 0; i < size; i++)ret[i] = new T(); return ret; }
    #endregion
}