using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;

class Program
{
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    static Scan sc = new Scan();
    static void Main(string[] args)
    {
        int n = sc.Int;
        var a = sc.IntArr;
        Array.Sort(a);
        int sum = a.Sum();
        int lim = sum / 2 + 1;
        var dp = new Bitset(lim);
        dp[0] = true;
        for (int i = 0; i < n; i++)
            dp = dp | dp << a[i];

        for (int i = lim - 1; i >= 0 ; i--)
        {
            if (dp[i]) {
                Prt(sum - i);
                break;
            }
        }
        sw.Flush();
    }
    static void Prt(string a) => sw.WriteLine(a);
    static void Prt<T>(IEnumerable<T> a) => Prt(string.Join(" ", a));
    static void Prt(params object[] a) => Prt(string.Join(" ", a));
}

class Scan
{
    public int Int => int.Parse(Str);
    public long Long => long.Parse(Str);
    public double Double => double.Parse(Str);
    public string Str => Console.ReadLine().Trim();
    public int[] IntArr => StrArr.Select(int.Parse).ToArray();
    public long[] LongArr => StrArr.Select(long.Parse).ToArray();
    public double[] DoubleArr => StrArr.Select(double.Parse).ToArray();
    public string[] StrArr => Str.Split(new []{' '}, System.StringSplitOptions.RemoveEmptyEntries);
}
class Bitset
{
    int size;
    ulong[] bits;
    public Bitset(int n) {
        size = n;
        bits = new ulong[(n + 63) / 64];
    }
    public void fill(bool b) {
        for (int i = 0; i < bits.Length; i++) bits[i] = b ? ulong.MaxValue : 0;
        if ((size & 63) > 0) bits[bits.Length - 1] &= (1UL << (size & 63)) - 1UL;
    }
    public bool this[int i] {
        set {
            if (value) bits[i >> 6] |= 1UL << (i & 63);
            else       bits[i >> 6] &= ~(1UL << (i & 63));
        }
        get {
            return (bits[i >> 6] >> (i & 63) & 1) == 1;
        }
    }
    public static Bitset operator&(Bitset a, Bitset b) {
        var ret = new Bitset(a.size);
        for (int i = 0; i < ret.bits.Length; i++) ret.bits[i] = a.bits[i] & b.bits[i];
        return ret;
    }
    public static Bitset operator|(Bitset a, Bitset b) {
        var ret = new Bitset(a.size);
        for (int i = 0; i < ret.bits.Length; i++) ret.bits[i] = a.bits[i] | b.bits[i];
        return ret;
    }
    public static Bitset operator^(Bitset a, Bitset b) {
        var ret = new Bitset(a.size);
        for (int i = 0; i < ret.bits.Length; i++) ret.bits[i] = a.bits[i] ^ b.bits[i];
        return ret;
    }
    public static Bitset operator<<(Bitset a, int k) {
        if (k < 0) return a >> -k;
        if ((k & 63) == 0) return a.Lshift(k >> 6);
        if (k > 64) return a.Lshift(k >> 6) << (k & 63);
        var ret = new Bitset(a.size);
        for (int i = 0; i < ret.bits.Length; i++)
            ret.bits[i] = a.bits[i] << k | (i > 0 ? a.bits[i - 1] >> 64 - k : 0);
        if ((ret.size & 63) > 0) ret.bits[ret.bits.Length - 1] &= (1UL << (ret.size & 63)) - 1UL;
        return ret;
    }
    public static Bitset operator>>(Bitset a, int k) {
        if (k < 0) return a << -k;
        if ((k & 63) == 0) return a.Rshift(k >> 6);
        if (k > 64) return a.Rshift(k >> 6) >> (k & 63);
        var ret = new Bitset(a.size);
        for (int i = 0; i < ret.bits.Length; i++)
            ret.bits[i] = a.bits[i] >> k | (i < ret.bits.Length - 1 ? a.bits[i + 1] << 64 - k : 0);
        return ret;
    }
    Bitset Lshift(int k) {
        if (k < 0) return Rshift(-k);
        var ret = new Bitset(size);
        for (int i = k; i < ret.bits.Length; i++) ret.bits[i] = bits[i - k];
        if ((ret.size & 63) > 0) ret.bits[ret.bits.Length - 1] &= (1UL << (ret.size & 63)) - 1UL;
        return ret;
    }
    Bitset Rshift(int k) {
        if (k < 0) return Lshift(-k);
        var ret = new Bitset(size);
        for (int i = 0; i + k < ret.bits.Length; i++) ret.bits[i] = bits[i + k];
        return ret;
    }
}