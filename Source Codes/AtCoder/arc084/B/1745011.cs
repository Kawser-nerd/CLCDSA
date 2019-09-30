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

            if (r == '\r')
            {
                if (_reader.Peek() == '\n') _reader.Read();
                break;
            }
            else if (r == -1 || r == ' ' || r == '\n')
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
        return int.Parse(Word());
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

    public int[] Ns(int count)
    {
        return count.MakeArray(_ => N());
    }

    public long[] Ls(int count)
    {
        return count.MakeArray(_ => L());
    }

    public double[] Fs(int count)
    {
        return count.MakeArray(_ => F());
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

    private int Capacity
    {
        get
        {
            return _buffer.Length;
        }
    }

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

        Rebuild(Math.Max(Capacity + Capacity / 2, capacity));
    }

    public void Push(T value)
    {
        EnsureCapacity(_count + 1);

        _offset = (_offset - 1 + Capacity) % Capacity;

        _buffer[_offset] = value;
        _count++;
    }

    public void Enqueue(T value)
    {
        EnsureCapacity(_count + 1);

        _buffer[Shift(_count)] = value;
        _count++;
    }

    public T Pop()
    {
        if (_count == 0)
            throw new InvalidOperationException("Deque has no value.");

        var i = _offset;
        _count--;
        _offset = (_offset + 1) % Capacity;

        return _buffer[i];
    }

    public T Dequeue()
    {
        if (_count == 0)
            throw new InvalidOperationException("Deque has no value.");

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


public struct State
{
    public int Value { get; set; }
    public int Sum { get; set; }
}

public sealed partial class Program
{
    int K;

    private long Solve()
    {
        var done = K.MakeArray(i => false);

        var q = new Deque<State>();
        q.Push(new State { Value = 1, Sum = 1 });

        while (true)
        {
            var state = q.Pop();
            if (done[state.Value]) continue;
            done[state.Value] = true;

            if (state.Value == 0)
            {
                return state.Sum;
            }

            q.Push(new State { Value = (state.Value * 10) % K, Sum = state.Sum });
            q.Enqueue(new State { Value = (state.Value + 1) % K, Sum = state.Sum + 1 });
        }
    }

    private void Read()
    {
        var a = _scanner;
        K = a.N();
    }

    public void EntryPoint()
    {
        Read();
        WriteLine(Solve());
    }
}