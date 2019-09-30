using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class hawawa
{
  static Printer sw = new Printer(Console.OpenStandardOutput()) { AutoFlush = false };

  static void Main()
  {
    Console.SetOut(sw);
    solve();
    Console.Out.Flush();
  }
  

  static void solve()
  {
    Scanner scanner = new Scanner();
    int q = scanner.nextInt();
    Set<int> set = new Set<int>();
    while(q-- != 0)
    {
      int t = scanner.nextInt(), x = scanner.nextInt();
      switch (t)
      {
        case 1:
          set.Insert(x);
          break;
        case 2:
          Console.WriteLine(set[x - 1]);
          set.Remove(set[x - 1]);
          break;
      }
    }
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
    if (i < s.Length) return s[i++];
    string st = Console.ReadLine();
    while (st == "") st = Console.ReadLine();
    s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
    i = 0;
    return next();
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

class Printer : StreamWriter
{
  public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
  public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
  public Printer(Stream stream, Encoding encoding) : base(stream, encoding) { }
}

/// <summary>
/// Self-Balancing Binary Search Tree
/// (using Randamized BST)
/// </summary>
public class SB_BinarySearchTree<T> where T : IComparable
{
  public class Node
  {
    public T Value;
    public Node LChild;
    public Node RChild;
    public int Count;     //size of the sub tree

    public Node(T v)
    {
      Value = v;
      Count = 1;
    }
  }

  static Random _rnd = new Random();

  public static int Count(Node t)
  {
    return t == null ? 0 : t.Count;
  }

  static Node Update(Node t)
  {
    t.Count = Count(t.LChild) + Count(t.RChild) + 1;
    return t;
  }

  public static Node Merge(Node l, Node r)
  {
    if (l == null || r == null) return l == null ? r : l;

    if ((double)Count(l) / (double)(Count(l) + Count(r)) > _rnd.NextDouble())
    {
      l.RChild = Merge(l.RChild, r);
      return Update(l);
    }
    else
    {
      r.LChild = Merge(l, r.LChild);
      return Update(r);
    }
  }

  /// <summary>
  /// split as [0, k), [k, n)
  /// </summary>
  public static Tuple<Node, Node> Split(Node t, int k)
  {
    if (t == null) return new Tuple<Node, Node>(null, null);
    if (k <= Count(t.LChild))
    {
      var s = Split(t.LChild, k);
      t.LChild = s.Item2;
      return new Tuple<Node, Node>(s.Item1, Update(t));
    }
    else
    {
      var s = Split(t.RChild, k - Count(t.LChild) - 1);
      t.RChild = s.Item1;
      return new Tuple<Node, Node>(Update(t), s.Item2);
    }
  }

  public static Node Remove(Node t, T v)
  {
    if (Find(t, v) == null) return t;
    return RemoveAt(t, LowerBound(t, v));
  }

  public static Node RemoveAt(Node t, int k)
  {
    var s = Split(t, k);
    var s2 = Split(s.Item2, 1);
    return Merge(s.Item1, s2.Item2);
  }

  public static bool Contains(Node t, T v)
  {
    return Find(t, v) != null;
  }

  public static Node Find(Node t, T v)
  {
    while (t != null)
    {
      var cmp = t.Value.CompareTo(v);
      if (cmp > 0) t = t.LChild;
      else if (cmp < 0) t = t.RChild;
      else break;
    }
    return t;
  }

  public static Node FindByIndex(Node t, int idx)
  {
    if (t == null) return null;

    var currentIdx = Count(t) - Count(t.RChild) - 1;
    while (t != null)
    {
      if (currentIdx == idx) return t;
      if (currentIdx > idx)
      {
        t = t.LChild;
        currentIdx -= (Count(t == null ? null : t.RChild) + 1);
      }
      else
      {
        t = t.RChild;
        currentIdx += (Count(t == null ? null : t.LChild) + 1);
      }
    }

    return null;
  }

  public static int UpperBound(Node t, T v)
  {
    var torg = t;
    if (t == null) return -1;

    var ret = Int32.MaxValue;
    var idx = Count(t) - Count(t.RChild) - 1;
    while (t != null)
    {
      var cmp = t.Value.CompareTo(v);

      if (cmp > 0)
      {
        ret = Math.Min(ret, idx);
        t = t.LChild;
        idx -= (Count(t == null ? null : t.RChild) + 1);
      }
      else if (cmp <= 0)
      {
        t = t.RChild;
        idx += (Count(t == null ? null : t.LChild) + 1);
      }
    }
    return ret == Int32.MaxValue ? Count(torg) : ret;
  }

  public static int LowerBound(Node t, T v)
  {
    var torg = t;
    if (t == null) return -1;

    var idx = Count(t) - Count(t.RChild) - 1;
    var ret = Int32.MaxValue;
    while (t != null)
    {
      var cmp = t.Value.CompareTo(v);
      if (cmp >= 0)
      {
        if (cmp == 0) ret = Math.Min(ret, idx);
        t = t.LChild;
        if (t == null) ret = Math.Min(ret, idx);
        idx -= t == null ? 0 : (Count(t.RChild) + 1);
      }
      else if (cmp < 0)
      {
        t = t.RChild;
        idx += (Count(t == null ? null : t.LChild) + 1);
        if (t == null) return idx;
      }
    }
    return ret == Int32.MaxValue ? Count(torg) : ret;
  }

  public static Node Insert(Node t, T v)
  {
    var ub = LowerBound(t, v);
    return InsertByIdx(t, ub, v);
  }

  static Node InsertByIdx(Node t, int k, T v)
  {
    var s = Split(t, k);
    return Merge(Merge(s.Item1, new Node(v)), s.Item2);
  }

  public static IEnumerable<T> Enumerate(Node t)
  {
    var ret = new List<T>();
    Enumerate(t, ret);
    return ret;
  }

  static void Enumerate(Node t, List<T> ret)
  {
    if (t == null) return;
    Enumerate(t.LChild, ret);
    ret.Add(t.Value);
    Enumerate(t.RChild, ret);
  }
}

/// <summary>
/// C-like set
/// </summary>
public class Set<T> where T : IComparable
{
  protected SB_BinarySearchTree<T>.Node _root;

  public T this[int idx] { get { return ElementAt(idx); } }

  public int Count()
  {
    return SB_BinarySearchTree<T>.Count(_root);
  }

  public virtual void Insert(T v)
  {
    if (_root == null) _root = new SB_BinarySearchTree<T>.Node(v);
    else
    {
      if (SB_BinarySearchTree<T>.Find(_root, v) != null) return;
      _root = SB_BinarySearchTree<T>.Insert(_root, v);
    }
  }

  public void Clear()
  {
    _root = null;
  }

  public void Remove(T v)
  {
    _root = SB_BinarySearchTree<T>.Remove(_root, v);
  }

  public bool Contains(T v)
  {
    return SB_BinarySearchTree<T>.Contains(_root, v);
  }

  public T ElementAt(int k)
  {
    var node = SB_BinarySearchTree<T>.FindByIndex(_root, k);
    if (node == null) throw new IndexOutOfRangeException();
    return node.Value;
  }

  public int Count(T v)
  {
    return SB_BinarySearchTree<T>.UpperBound(_root, v) - SB_BinarySearchTree<T>.LowerBound(_root, v);
  }

  public int LowerBound(T v)
  {
    return SB_BinarySearchTree<T>.LowerBound(_root, v);
  }

  public int UpperBound(T v)
  {
    return SB_BinarySearchTree<T>.UpperBound(_root, v);
  }

  public Tuple<int, int> EqualRange(T v)
  {
    if (!Contains(v)) return new Tuple<int, int>(-1, -1);
    return new Tuple<int, int>(SB_BinarySearchTree<T>.LowerBound(_root, v), SB_BinarySearchTree<T>.UpperBound(_root, v) - 1);
  }

  public List<T> ToList()
  {
    return new List<T>(SB_BinarySearchTree<T>.Enumerate(_root));
  }
}

/// <summary>
/// C-like multiset
/// </summary>
public class MultiSet<T> : Set<T> where T : IComparable
{
  public override void Insert(T v)
  {
    if (_root == null) _root = new SB_BinarySearchTree<T>.Node(v);
    else _root = SB_BinarySearchTree<T>.Insert(_root, v);
  }
}