using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public static class TemplateExtension
{
    public static X[] MakeArray<X>(this int count, Func<int, X> func)
    {
        var xs = new X[count];
        for (var i = 0; i < count; i++)
        {
            xs[i] = func(i);
        }
        return xs;
    }

    public static int[] Range(this int count, int start = 0)
    {
        return count.MakeArray(i => i + start);
    }

    public static string Intercalate<X>(this IEnumerable<X> @this, string separator)
    {
        return string.Join(separator, @this);
    }

    public sealed class ValueIndexPair<T>
        : Tuple<T, int>
    {
        public T Value { get { return Item1; } }
        public int Index { get { return Item2; } }

        public ValueIndexPair(T value, int index)
            : base(value, index)
        {
        }
    }

    public static IEnumerable<ValueIndexPair<X>> Indexed<X>(this IEnumerable<X> @this)
    {
        var i = 0;
        foreach (var x in @this)
        {
            yield return new ValueIndexPair<X>(x, i);
            i++;
        }
    }
}

public sealed class Scanner
{
    private readonly TextReader _reader;
    private readonly StringBuilder _sb = new StringBuilder();

    /// <summary>
    /// Reads next word separated by spaces.
    /// </summary>
    public string Word()
    {
        _sb.Clear();

        while (true)
        {
            var r = _reader.Read();

            if (r == ' ' || r == '\r' || r == '\n')
            {
                if (r == '\r' && _reader.Peek() == '\n')
                {
                    _reader.Read();
                }

                // Ignore leading spaces.
                if (_sb.Length == 0) continue;

                break;
            }
            else if (r == -1)
            {
                break;
            }
            else
            {
                _sb.Append((char)r);
            }
        }

        return _sb.ToString();
    }

    /// <summary>
    /// Reads next word as <see cref="int"/>.
    /// </summary>
    public int N()
    {
        return int.Parse(Word().Trim());
    }

    /// <summary>
    /// Reads next word as <see cref="long"/>.
    /// </summary>
    public long L()
    {
        return long.Parse(Word());
    }

    /// <summary>
    /// Reads next word as <see cref="double"/>.
    /// </summary>
    public double F()
    {
        return double.Parse(Word());
    }

    /// <summary>
    /// Reads next line and splits it by spaces.
    /// </summary>
    public X[] Words<X>(Func<string, X> func)
    {
        return _reader.ReadLine().Split(' ').Select(func).ToArray();
    }

    public Scanner(TextReader reader)
    {
        _reader = reader;
    }
}

public partial class Program
{
    private readonly TextReader _input;
    private readonly TextWriter _output;
    private readonly Scanner _scanner;

    private void WriteLine(int value)
    {
        _output.WriteLine(value);
    }

    private void WriteLine(long value)
    {
        _output.WriteLine(value);
    }

    private void WriteLine(double value)
    {
        _output.WriteLine(value);
    }

    private void WriteLine(char value)
    {
        _output.WriteLine(value);
    }

    private void WriteLine(string value)
    {
        _output.WriteLine(value);
    }

    public Program(TextReader input, TextWriter output)
    {
        _input = input;
        _output = output;
        _scanner = new Scanner(input);
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).EntryPoint();
    }
}

class MyBitArray
     : IEnumerable<bool>
{
    const int W = 64;

    ulong[] _array;
    long _length;

    public long Length
    {
        get
        {
            return _length;
        }
    }

    public bool this[long index]
    {
        get
        {
            return (_array[index / W] & (1UL << (int)(index % W))) != 0;
        }
        set
        {
            _array[index / W] |= (1UL << (int)(index % W));
        }
    }

    public void SetLength(long length)
    {
        if (_array.Length == ArrayLength(length)) return;

        var array = new ulong[ArrayLength(length)];
        Array.Copy(_array, array, Math.Min(_array.Length, array.Length));

        _array = array;
        _length = length;
    }

    public void LeftShift(int count)
    {
        if (count == 0) return;

        var arrayShift = count / W;
        var merge = count % W;

        if (arrayShift > 0)
        {
            Array.Copy(_array, 0, _array, arrayShift, _array.Length - arrayShift);
            Array.Clear(_array, 0, arrayShift);
        }

        if (merge > 0)
        {
            for (var i = _array.Length - 1; i >= 0; i--)
            {
                var low = i == 0 ? 0 : (_array[i - 1] >> (W - merge));
                var high = _array[i] << merge;
                _array[i] = low | high;
            }
        }
    }

    public void Or(MyBitArray other)
    {
        SetLength(Math.Max(Length, other.Length));

        for (var i = 0; i < other._array.Length; i++)
        {
            _array[i] |= other._array[i];
        }
    }

    public MyBitArray Clone()
    {
        var array = new ulong[_array.Length];
        Array.Copy(_array, array, _array.Length);
        return new MyBitArray(array);
    }

    public IEnumerator<bool> GetEnumerator()
    {
        for (var i = 0; i < Length; i++)
        {
            yield return this[i];
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

    public override string ToString()
    {
        return string.Join("", this.ToArray().Select(t => t ? "1" : "0"));
    }

    public MyBitArray(bool[] bits)
    {
        var al = ArrayLength(bits.Length);
        var array = new ulong[al];
        for (var i = 0; i < bits.Length; i++)
        {
            if (!bits[i]) continue;
            array[i / W] = array[i / W] | (1UL << (i % W));
        }

        _array = array;
        _length = bits.Length;
    }

    public MyBitArray(ulong[] array)
    {
        _array = array;
        _length = array.Length * W;
    }

    private static int ArrayLength(long length)
    {
        return (int)((length + W - 1) / W);
    }
}

public sealed partial class Program
{
    int N;
    int[] A;

    public void Test()
    {
        var ba = new MyBitArray(new[] { 0x050607080A0B0C0DUL, 0x050607080A0B0C0DUL, 0x050607080A0B0C0DUL });
        var bac = ba.Clone();
        WriteLine(ba.ToString());
        WriteLine(bac.Clone().ToString());

        ba.LeftShift(70);
        WriteLine(ba.ToString());

        ba.Or(bac);
        WriteLine(ba.ToString());
    }

    private long Solve()
    {
        var total = A.Sum();
        var th = (total + 1) / 2;

        var bits = new bool[total + 1];
        bits[0] = true;
        var dp = new MyBitArray(bits);

        for (var i = 0; i < N; i++)
        {
            var dp2 = dp.Clone();
            dp2.LeftShift(A[i]);
            dp.Or(dp2);
        }

        var min = total;
        for (var s = th; s <= total; s++)
        {
            if (dp[s])
            {
                min = s;
                break;
            }
        }

        return min;
    }

    public void EntryPoint()
    {
        // Test();

        var I = _scanner;
        N = I.N();
        A = N.MakeArray(i => I.N());

        WriteLine(Solve());
    }
}