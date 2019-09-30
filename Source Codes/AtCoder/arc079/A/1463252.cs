using System;
using System.Collections.Generic;
using System.Linq;

public class MultiDictionary<TKey, TValue>
{
    private readonly Dictionary<TKey, List<TValue>> mDictionary = new Dictionary<TKey, List<TValue>>();

    /// <summary>
    /// ???????????????????????????????
    /// </summary>
    public List<TValue> this[TKey key]
    {
        get { return mDictionary[key]; }
        set { mDictionary[key] = value; }
    }

    /// <summary>
    /// ?????????????????????
    /// </summary>
    public Dictionary<TKey, List<TValue>>.KeyCollection Keys
    {
        get { return mDictionary.Keys; }
    }

    /// <summary>
    /// ???????????????????????
    /// </summary>
    public Dictionary<TKey, List<TValue>>.ValueCollection Values
    {
        get { return mDictionary.Values; }
    }

    /// <summary>
    /// ??????????????????????
    /// </summary>
    public int Count
    {
        get { return mDictionary.Count; }
    }

    /// <summary>
    /// ??????????????????????
    /// </summary>
    public void Add(TKey key, TValue value)
    {
        if (!mDictionary.ContainsKey(key))
        {
            mDictionary.Add(key, new List<TValue>());
        }
        mDictionary[key].Add(value);
    }

    /// <summary>
    /// ?????????????????????????
    /// </summary>
    public void Add(TKey key, params TValue[] values)
    {
        foreach (var n in values)
        {
            Add(key, n);
        }
    }

    /// <summary>
    /// ?????????????????????????
    /// </summary>
    public void Add(TKey key, IEnumerable<TValue> values)
    {
        foreach (var n in values)
        {
            Add(key, n);
        }
    }

    /// <summary>
    /// ????????????????
    /// </summary>
    public bool Remove(TKey key, TValue value)
    {
        return mDictionary[key].Remove(value);
    }

    /// <summary>
    /// ???????????????????
    /// </summary>
    public bool Remove(TKey key)
    {
        return mDictionary.Remove(key);
    }

    /// <summary>
    /// ?????????????????
    /// </summary>
    public void Clear()
    {
        mDictionary.Clear();
    }

    /// <summary>
    /// ??????????????????????????
    /// </summary>
    public bool Contains(TKey key, TValue value)
    {
        return mDictionary[key].Contains(value);
    }

    /// <summary>
    /// ????????????????????????
    /// </summary>
    public bool ContainsKey(TKey key)
    {
        return mDictionary.ContainsKey(key);
    }

    /// <summary>
    /// ??????????????
    /// </summary>
    public IEnumerator<KeyValuePair<TKey, List<TValue>>> GetEnumerator()
    {
        foreach (var n in mDictionary)
        {
            yield return n;
        }
    }

    public IEnumerable<KeyValuePair<TKey, TValue>> GetFlatten()
    {
        foreach (var n in mDictionary)
        {
            foreach (var v in n.Value)
            {
                yield return new KeyValuePair<TKey, TValue>(n.Key, v);
            }
        }
    }
}

class Solution
{
    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int n = vals[0];
        int m = vals[1];
        var link = new MultiDictionary<int, int>();
        for (int i = 0; i < m; i++)
        {
            vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            link.Add(vals[0], vals[1]);
        }

        var current = new HashSet<int>() { 1 };
        var next = new HashSet<int>(current.SelectMany(c => link.ContainsKey(c) ? link[c] : new List<int>()));
        if (next.Count == 0)
        {
            Console.WriteLine("IMPOSSIBLE");
            return;
        }
        current = next;
        next = new HashSet<int>(current.SelectMany(c => link.ContainsKey(c) ? link[c] : new List<int>()));
        if (next.Contains(n))
        {
            Console.WriteLine("POSSIBLE");
            return;
        }
        Console.WriteLine("IMPOSSIBLE");
        return;
    }
}