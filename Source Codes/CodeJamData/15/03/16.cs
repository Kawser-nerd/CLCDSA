using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;

namespace GoogleCodeJam
{
    class C
    {
        static void Main(string[] args)
        {
            //Console.WriteLine(Solver.CanGetDijkstra(1000L * 1000 * 1000 * 1000 + 1, "i" + new string('j', 99998) + "k"));
            var input = @"C:\Users\kaspir\Downloads\C-large.in";

            File.WriteAllLines(Path.ChangeExtension(input, "out"), Solver.Solve(File.ReadAllLines(input)));

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);

                var testCount = Int32.Parse(reader.Next());

                for (var i = 0; i < testCount; i++)
                {
                    var parts = reader.Next().Split(' ').Select(Int64.Parse).ToList();
                    var L = parts[0];
                    var X = parts[1];
                    var str = reader.Next();
                    var message = String.Format("Case #{0}: {1}", i + 1, CanGetDijkstra(X, str) ? "YES" : "NO");
                    Console.WriteLine(message);
                    yield return message;
                }
            }

            static readonly Dictionary<Tuple<Q, long>, Q> _pow = new Dictionary<Tuple<Q, long>, Q>();

            static Q Pow(Q q, long pow)
            {
                if (pow == 0)
                    return Q.O;

                if (pow == 1)
                    return q;

                Q cached;
                var key = Tuple.Create(q, pow);

                if (_pow.TryGetValue(key, out cached))
                    return cached;

                return _pow[key] = Pow(q, pow / 2) * Pow(q, pow - pow / 2);
            }

            public static bool CanGetDijkstra(long X, string str)
            {
                var L = str.Length;
                Console.WriteLine("L={0}, X={1}", L, X);
                var result = Q.O;
                var a = Q.O;

                var targets = new[] { Q.I, Q.J, Q.K };
                var targetIndex = 0;

                var values = str.Select(Q.FromChar).ToList();

                for (var i = 0; i < L; i++)
                    a *= values[i];

                for (var i = 0L; i < L * Math.Min(X, 100); i++)
                {
                    result *= values[(int)(i % str.Length)];

                    if (targets[targetIndex].Equals(result))
                    {
                        targetIndex++;
                        result = Q.O;

                        if (targetIndex == targets.Length)
                        {
                            for (i++; i % L > 0; i++)
                            {
                                result *= values[(int)(i % str.Length)];
                            }
                            var tailACount = X - i / L;
                            result *= Pow(a, tailACount);

                            break;
                        }
                    }
                }

                return targetIndex == targets.Length && result.Equals(Q.O);
            }
        }

        class Reader
        {
            readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
            }

            public string NextOrNull()
            {
                if (!_enumerator.MoveNext())
                    return null;

                return _enumerator.Current;
            }

            public string Next()
            {
                if (!_enumerator.MoveNext())
                    throw new ApplicationException("End of input");

                return _enumerator.Current;
            }
        }
    }

    public struct Q : IEquatable<Q>
    {
        readonly bool _isNegative;
        readonly int _valueIndex;

        Q(bool isNegative, int valueIndex)
        {
            _isNegative = isNegative;
            _valueIndex = valueIndex;
        }

        public static Q FromChar(char c)
        {
            return new Q(false, GetValueIndex(c));
        }

        static int GetValueIndex(char c)
        {
            switch (c)
            {
                case '1':
                    return 0;
                case 'i':
                    return 1;
                case 'j':
                    return 2;
                case 'k':
                    return 3;
                default:
                    return -1;
            }
        }

        public override string ToString()
        {
            return (_isNegative ? "-" : "") + GetIndexValue(_valueIndex);
        }

        static char GetIndexValue(int value)
        {
            switch (value)
            {
                case 0:
                    return '1';
                case 1:
                    return 'i';
                case 2:
                    return 'j';
                case 3:
                    return 'k';
                default:
                    return '?';
            }
        }

        public static Q operator -(Q q)
        {
            return new Q(!q._isNegative, q._valueIndex);
        }

        public static Q operator *(Q l, Q r)
        {
            var result = MulMatrix[l._valueIndex][r._valueIndex];
            return l._isNegative == r._isNegative ? result : -result;
        }

        public bool Equals(Q other)
        {
            return _isNegative.Equals(other._isNegative) && _valueIndex == other._valueIndex;
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj)) return false;
            return obj is Q && Equals((Q)obj);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                return (_isNegative.GetHashCode() * 397) ^ _valueIndex;
            }
        }

        public static readonly Q O = new Q(false, 0);
        public static readonly Q I = new Q(false, 1);
        public static readonly Q J = new Q(false, 2);
        public static readonly Q K = new Q(false, 3);

        static readonly Q[][] MulMatrix =
        {
            new[] {  O,  I,  J,  K },
            new[] {  I, -O,  K, -J },
            new[] {  J, -K, -O,  I },
            new[] {  K,  J, -I, -O }
        };
    }
}