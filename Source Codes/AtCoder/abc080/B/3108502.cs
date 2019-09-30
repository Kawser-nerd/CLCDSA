#pragma warning disable

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Diagnostics;
using System.Numerics;
using System.Collections;

static class MainClass
{
    public static void Main()
    {
        var n = Console.ReadLine();
        var har = n.ToList().Sum(x => int.Parse(x.ToString()));
        Console.WriteLine(n.ToInt32() % har == 0 ? "Yes" : "No");
    }


    #region ?????
    #region ????
    public static int LowerBound<T>(this IEnumerable<T> ar, int start, int end, T value, IComparer<T> comparer)
    {
        var arr = ar.ToArray();
        int low = start;
        int high = end;
        int mid;
        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (comparer.Compare(arr[mid], value) < 0)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    public static int LowerBound<T>(this IEnumerable<T> arr, T value) where T : IComparable
    {
        return LowerBound(arr, 0, arr.Count(), value, Comparer<T>.Default);
    }

    public static int UpperBound<T>(this IEnumerable<T> ar, int start, int end, T value, IComparer<T> comparer)
    {
        var arr = ar.ToArray();
        int low = start;
        int high = end;
        int mid;
        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (comparer.Compare(arr[mid], value) <= 0)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    public static int UpperBound<T>(this IEnumerable<T> arr, T value)
    {
        return UpperBound(arr, 0, arr.Count(), value, Comparer<T>.Default);
    }
    #endregion
    #region?bit???
    /// <summary>
    /// Bit??????????
    /// </summary>
    /// <param name="len">???????(len?0???????)</param>
    /// <returns>?????</returns>
    public static List<List<bool>> CreateBits(int len)
    {
        return CreateBitsPri(new List<List<bool>>(), len, 0);
    }

    private static List<List<bool>> CreateBitsPri(List<List<bool>> bits, int len, int count)
    {
        if (count == 0)
        {
            var lss = new List<bool>();
            lss.Add(true);
            bits.Add(lss);
            var lx = new List<bool>();
            lx.Add(false);
            bits.Add(lx);
            count++;
            return CreateBitsPri(bits, len, count);
        }
        if (len - count == 0)
            return bits;
        count++;
        var ls = new List<List<bool>>();
        foreach (var item in bits)
        {
            var x = item.ToList();
            x.Add(true);
            item.Add(false);
            ls.Add(item);
            ls.Add(x);
        }
        return CreateBitsPri(ls, len, count);
    }
    #endregion
    #region ?????

    public static int ToInt32(this string str)
    {
        return int.Parse(str);
    }
    public static List<string> SplittedStringToList(this string str)
    {
        return str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
            .ToList();
    }
    public static List<int> SplittedStringToInt32List(this string str)
    {
        return str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    }
    #endregion
    #region ?????????
    /**
     * MIT License

Copyright (c) 2018 gushwell

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
     **/
    public class BoundedBoolArray
    {
        private BitArray _array;
        private int _lower;

        public BoundedBoolArray(int lower, int upper)
        {
            _array = new BitArray(upper - lower + 1);
            _lower = lower;
        }

        public bool this[int index]
        {
            get
            {
                return _array[index - _lower];
            }
            set
            {
                _array[index - _lower] = value;
            }
        }
    }
    public static IEnumerable<int> GeneratePrimes()
    {
            var primes = new List<int>() { 2, 3 };
            foreach (var p in primes)
                yield return p;
            int ix = 0;
            while (true)
            {
                int prime1st = primes[ix];
                int prime2nd = primes[++ix];
                var lower = prime1st * prime1st;
                var upper = prime2nd * prime2nd - 1;
                var sieve = new BoundedBoolArray(lower, upper);
                foreach (var prime in primes.Take(ix))
                {
                    var start = (int)Math.Ceiling((double)lower / prime) * prime;
                    for (int index = start; index <= upper; index += prime)
                        sieve[index] = true;
                }
                for (int i = lower; i <= upper; i++)
                {
                    if (sieve[i] == false)
                    {
                        primes.Add(i);
                        yield return i;
                    }
                }
        }
    }
    #endregion
    #region DeepClone
    public static T DeepClone<T>(this T src)
    {
        using (var memoryStream = new MemoryStream())
        {
            var binaryFormatter
              = new BinaryFormatter();
            binaryFormatter.Serialize(memoryStream, src);
            memoryStream.Seek(0, SeekOrigin.Begin);
            return (T)binaryFormatter.Deserialize(memoryStream);
        }
    }
    #endregion
    #region ???????
    public static List<List<int>> GeneratePermutations(int n)
    {
        if (n > 14)
            throw new ArgumentOutOfRangeException();
        var ls = new List<List<int>>();
        ls.Add(new List<int>() { 1 });

        for (int i = 0; i < n - 1; i++)
        {
            var newls = new List<List<int>>();
            ls.ForEach(x =>
            {
                var len = x.Count;
                for (int j = 0; j <= len; j++)
                {
                    var item = x.DeepClone();
                    item.Insert(j, i + 2);
                    newls.Add(item);
                }
            });
            ls = newls;
        }
        return ls;

    }
    #endregion
    #endregion
}