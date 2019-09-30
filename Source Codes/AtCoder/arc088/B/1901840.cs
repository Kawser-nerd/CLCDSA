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



public sealed class Deque<T>
    : IReadOnlyList<T>
{
    private T[] _buffer = new T[0];
    private int _offset = 0;
    private int _count = 0;

    public int Count
    {
        get
        {
            return _count;
        }
    }

    public int Capacity
    {
        get
        {
            return _buffer.Length;
        }
    }

    /// <summary>
    /// Converts an index to the deque into one to the underlying buffer.
    /// </summary>
    private int Shift(int index)
    {
        Debug.Assert(Capacity > 0 && 0 <= index && index <= _count);
        return (_offset + index) % Capacity;
    }

    public T this[int index]
    {
        get
        {
            if (!(0 <= index && index < _count))
                throw new ArgumentOutOfRangeException("index");
            return _buffer[Shift(index)];
        }
        set
        {
            if (!(0 <= index && index < _count))
                throw new ArgumentOutOfRangeException("index");
            _buffer[Shift(index)] = value;
        }
    }

    private void Rebuild(int newCapacity)
    {
        Debug.Assert(newCapacity > _count);

        var oldBuffer = _buffer;
        var newBuffer = new T[newCapacity];

        if (_offset + _count <= oldBuffer.Length)
        {
            Array.Copy(oldBuffer, _offset, newBuffer, 0, _count);
        }
        else
        {
            var firstCount = oldBuffer.Length - _offset;
            Array.Copy(oldBuffer, _offset, newBuffer, 0, firstCount);
            Array.Copy(oldBuffer, 0, newBuffer, firstCount, _count - firstCount);
        }

        _buffer = newBuffer;
        _offset = 0;
    }

    public void EnsureCapacity(int capacity)
    {
        if (capacity <= Capacity) return;

        var grown = Capacity + Capacity / 2;
        Rebuild(Math.Max(16, Math.Max(grown, capacity)));
    }

    public void PushFront(T value)
    {
        EnsureCapacity(_count + 1);

        _offset = (_offset - 1 + Capacity) % Capacity;

        _buffer[_offset] = value;
        _count++;
    }

    public void PushBack(T value)
    {
        EnsureCapacity(_count + 1);

        _buffer[Shift(_count)] = value;
        _count++;
    }

    public T PopFront()
    {
        if (_count == 0)
            throw new InvalidOperationException("Deque is empty.");

        var i = _offset;
        _count--;
        _offset = (_offset + 1) % Capacity;

        return _buffer[i];
    }

    public T PopBack()
    {
        if (_count == 0)
            throw new InvalidOperationException("Deque is empty.");

        _count--;
        var i = Shift(_count);

        return _buffer[i];
    }

    public void Clear()
    {
        _offset = 0;
        _count = 0;
    }

    public void Shrink()
    {
        if (Capacity == _count) return;
        Rebuild(_count);
    }

    #region IEnumerable
    public IEnumerator<T> GetEnumerator()
    {
        for (var i = 0; i < Count; i++)
        {
            yield return this[i];
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
    #endregion
}

public static class Deque
{
    public static Deque<X> Create<X>()
    {
        return new Deque<X>();
    }

    public static Deque<X> FromEnumerable<X>(IEnumerable<X> xs)
    {
        var deque = new Deque<X>();
        foreach (var x in xs)
        {
            deque.PushBack(x);
        }
        return deque;
    }
}

public sealed partial class Program
{
    string S;

    private long Solve()
    {
        var xs = new List<int>();
        {
            var i = 0;
            var j = 1;
            var current = S[0];
            while (true)
            {
                while (j < S.Length && S[j] == current)
                {
                    j++;
                }

                if (j > i)
                {
                    xs.Add(j - i);
                }

                if (j == S.Length)
                {
                    break;
                }

                current = S[j];
                i = j;
            }

            //Console.WriteLine(xs.Intercalate(", "));
        }

        if (xs.Count <= 2)
        {
            return xs.Max();
        }

        {
            var lx = 0;
            var rx = 0;

            var li = 0;
            var ri = xs.Count - 1;
            var x = S.Length;

            var n = 0;
            var K = S.Length;

            while (n < xs.Count)
            {
                var lk = Math.Max(lx + xs[li], x - (lx + xs[li]));
                var rk = Math.Max(rx + xs[ri], x - (rx + xs[ri]));

                if (lk >= rk)
                {
                    K = Math.Min(K, lk);
                    lx += xs[li];
                    li++;
                }
                else
                {
                    K = Math.Min(K, rk);
                    rx += xs[ri];
                    ri--;
                }

                n++;
            }

            return K;
        }
    }

    public void EntryPoint()
    {
        var I = _scanner;
        S = _input.ReadLine();

        WriteLine(Solve());
    }
}