using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

public static partial class MyExtension
{
    public class Solution
    {
        /* Head ends here */

        public const int PAD_FACTOR = 7;

        struct mystate
        {
            public int Hd, Ad, Hk, Ak, HASH;
            public mystate(int Hd, int Ad, int Hk, int Ak)
            {
                this.Hd = Hd;
                this.Ad = Ad;
                this.Hk = Hk;
                this.Ak = Ak;
                HASH = BitConverter.ToInt32(new[]{
                    Hd, Ad, Hk, Ak
                }.Select(x => Convert.ToByte(x)).ToArray(), 0);
            }
            public void Compile()
            {
                HASH = BitConverter.ToInt32(new[]{
                    Hd, Ad, Hk, Ak
                }.Select(x => Convert.ToByte(x)).ToArray(), 0);
            }
            public override int GetHashCode()
            {
                return HASH;
            }
            public override bool Equals(object obj)
            {
                var temp = (mystate)obj;
                return this.HASH == temp.HASH;
            }
        }

        public void zStart()
        {
            foreach (var @__ in Enumerable.Range(1, ReadInt32_UNSIGNED(Console.ReadLine())))
            {
                // start...
                var solve = new Func<long>(() =>
                {
                    var init = new mystate(ReadInt32(), ReadInt32(), ReadInt32(), ReadInt32());
                    var B = ReadInt32();
                    var D = ReadInt32();
                    var visited = new HashSet<mystate>();
                    visited.Add(init);
                    long turn = 0;
                    var bfs = new LinkedList<mystate>();
                    bfs.AddLast(init);
                    while (bfs.Any())
                    {
                        turn++;
                        var q = new LinkedList<mystate>();
                        foreach (var state in bfs)
                        {
                            mystate a, b, c, d;
                            a = b = c = d = state;

                            a.Hk -= a.Ad;
                            if (a.Hk <= 0)
                                return turn;

                            b.Ad += B;

                            c.Hd = init.Hd;

                            d.Ak = Math.Max(0, d.Ak - D);

                            var temp = new[] { a, b, c, d }
                                .Select(x => { x.Hd -= x.Ak; return x; })
                                .Where(x => x.Hd > 0)
                                .Select(x => { x.Compile(); return x; })
                                .Where(x => visited.Add(x))
                                .ForEach(x => q.AddLast(x))
                                ;
                        }
                        bfs = q;
                    }
                    return -1;
                });
                // end...
                {
                    //...
                    var temp = solve();
                    object ans = temp;
                    if (temp < 1) ans = "IMPOSSIBLE";
                    //

                    Console.Write("Case #{0}: ", @__);
                    Console.WriteLine(ans);
                }
                Debug.WriteLine(".");
            }
        }

        /* Tail starts here */
    }

#if TORIQ
    static void zTestSuite()
    {
        Directory.CreateDirectory(@"D:\download\codejam");
        //File.Delete(@"D:\download\codejam\1-OUTPUT.TXT");
        Test(File.ReadAllText("input.txt"), File.ReadAllText("output.txt"));
        //
        
    }
#endif

    // =============================================================================================

    #region ASSERT
    [DebuggerNonUserCode]
    static void Assert<T>(T actual, T expected)
    {
        if (object.Equals(actual, expected) == false)
        {
            Debug.WriteLine(actual, "ACTUAL");
            Debug.WriteLine(expected, "EXPECTED");
            Assert(false);
        }
    }
    [DebuggerNonUserCode]
    static void Assert(bool mustBeTrue)
    {
        if (mustBeTrue == false)
            throw new ApplicationException("ASSERTION FAILED");
    }
    #endregion
    #region faSTDIO

    static void Main(String[] args)
    {
#if TORIQ
        zTestSuite();
        //new Solution().zInternalTestSuite();
        return;
#endif
#if GOOGLE
        zGoogle();
        return;
#endif
        new Solution().zStart();
    }

    static IEnumerable<char> Read()
    {
        int cin;
        var empty = true;
        while ((cin = Console.Read()) > -1)
        {
            var c = (char)cin;
            if (c == ' ' || c == '\n' || c == '\r' || c == '\t')
            {
                if (empty) continue;
                else break;
            }
            yield return c;
            empty = false;
        }
    }
    static T Read<T>(Converter<string, T> convert, int capacity = 20)
    { var temp = ReadString(capacity); return convert(temp); }
    static string ReadString(int capacity = 1000000)
    {
        capacity += Solution.PAD_FACTOR;
        var ans = new System.Text.StringBuilder(capacity);
        foreach (var c in Read()) ans.Append(c);
        return ans.ToString();
    }
    static int ReadInt32() { return Read(Convert.ToInt32); }
    static long ReadLong64() { return Read(Convert.ToInt64); }
    static int ReadInt32_UNSIGNED() { return ReadInt32_UNSIGNED(Read()); }
    static int ReadInt32_UNSIGNED(IEnumerable<char> s) { return Convert.ToInt32(ReadLong64_UNSIGNED(s)); }
    static long ReadLong64_UNSIGNED() { return ReadLong64_UNSIGNED(Read()); }
    static long ReadLong64_UNSIGNED(IEnumerable<char> s)
    {
        var empty = true;
        var ans = 0L;
        foreach (var c in s)
        {
            if (ans >= 9e17 || ans >= 1e18)
                throw new OverflowException("Exceeds Int64.");
            var temp = c - '0';
            if (temp < 0 || temp > 9) throw new FormatException(string.Format(
                "Invalid char : {0} ({1})",
                c, temp));
            ans *= 10;
            ans += temp;
            empty = false;
        }
        if (empty)
            throw new EndOfStreamException("Unable to get any digit.");
        return ans;
    }

    #endregion
    #region LOOP
    static int Count(int left, int right) { return right - left + 1; }
    static long Count(long left, long right) { return right - left + 1; }
    static int Right(int left, int length) { return left + length - 1; }
    static int Left(int length, int right) { return right - length + 1; }
    static IEnumerable<T> ForEach<T>(this IEnumerable<T> range, Action<T> action)
    { foreach (var elem in range) action(elem); return range; }
    static IEnumerable<int> Range(int left, int right)
    { for (var i = left; i <= right; i++) yield return i; }
    static IEnumerable<int> RangeReverse(int right, int left)
    { for (var i = right; i >= left; i--) yield return i; }
    static int Capacity_PAD(double capacity) { return ((int)capacity) + Solution.PAD_FACTOR; }
    #endregion
    #region ARRAY / LIST / RANDOM-ACCESS
    static T[] ToArrayPadded<T>(this IEnumerable<T> stream, int size, int pad = Solution.PAD_FACTOR)
    {
        var arr = new T[size + pad];
        var idx = 0;
        foreach (var elem in stream) arr[idx++] = elem;
        return arr;
    }
    static T[] NewArrayPadded<T>(int minSize, Func<T> setValue = null, int pad = Solution.PAD_FACTOR)
    {
        var ans = new T[minSize + pad];
        if (setValue != null)
        {
            for (var i = 0; i < ans.Length; i++)
                ans[i] = setValue();
        }
        return ans;
    }
    static T[][] NewArrayPadded<T>(int minSize, T[] prototype, int pad = Solution.PAD_FACTOR) where T : struct
    {
        return NewArrayPadded(minSize, () =>
        {
            var arr = new T[prototype.Length];
            Array.Copy(prototype, arr, prototype.Length);
            return arr;
        }, pad);
    }
    static T NewArrayMultiDimensionPadded<T>(params int[] sizes) where T : class, System.Collections.IList
    {
        for (var i = 0; i < sizes.Length; i++) sizes[i] += Solution.PAD_FACTOR;
        return Array.CreateInstance(typeof(T), sizes) as T;
    }
    static T RefElementIndexed<T>(this T[] arr, Func<T, T> transformer, int index)
    { var ans = transformer(arr[index]); arr[index] = ans; return ans; }
    static T RefElementIndexed<T>(this Array arr, Func<T, T> transformer, params int[] indices)
    { var ans = transformer((T)arr.GetValue(indices)); arr.SetValue(ans, indices); return ans; }
    static bool BinarySearch(int rawIndex, out int insertIndex)
    {
        if (rawIndex < 0)
        {
            insertIndex = ~rawIndex;
            return false;
        }
        else
        {
            insertIndex = rawIndex;
            return true;
        }
    }
    #endregion

    // =============================================================================================


}
