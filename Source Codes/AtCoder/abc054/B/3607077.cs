using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
// ReSharper disable MemberCanBeMadeStatic.Local
// ReSharper disable PossibleNullReferenceException
// ReSharper disable UnusedMember.Global
// ReSharper disable UnusedMember.Local
// ReSharper disable ArrangeTypeMemberModifiers
// ReSharper disable SuggestVarOrType_BuiltInTypes
// ReSharper disable SuggestVarOrType_Elsewhere
// ReSharper disable InvertIf

namespace Csharp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve(new Input(Console.In));
        }

        private void Solve(Input cin)
        {
            //'.': ?
            //'#': ?

            var N = cin.ReadInt;
            var M = cin.ReadInt;

            var a = cin.ReadStrArray(N);
            var b = cin.ReadStrArray(M);

            var s = N - M;
            for (int i = 0; i <= s; i++)
            {
                //B???????
                for (int j = 0; j <= s; j++)
                {
                    if (check(a, b, i, j))
                    {
                        Console.WriteLine("Yes");
                        return;
                    }
                }
            }

            Console.WriteLine("No");








        }

        bool check(IReadOnlyList<string> a, IReadOnlyList<string> b, int add1, int add2)
        {
            for (int i = 0; i < b.Count; i++)
            {
                for (int j = 0; j < b[i].Length; j++)
                {
                    if (a[i + add1][j + add2] != b[i][j])
                        return false;
                }
            }
            return true;
        }
    }

    public class Input
    {
        private readonly TextReader _stream;
        private readonly char _separator;
        private readonly Queue<string> _input;

        public Input(TextReader reader, char separator = ' ')
        {
            this._separator = separator;
            this._stream = reader;
            this._input = new Queue<string>();
        }

        public string Read
        {
            get {
                if (this._input.Count != 0) return this._input.Dequeue();

                var tmp = this._stream.ReadLine().Split(this._separator);
                foreach (var val in tmp) {
                    this._input.Enqueue(val);
                }

                return this._input.Dequeue();
            }
        }

        public string ReadLine => _stream.ReadLine();

        public int ReadInt => int.Parse(Read);

        public long ReadLong => long.Parse(Read);

        public double ReadDouble => double.Parse(Read);

        public string[] ReadStrArray(long n)
        {
            var ret = new string[n];
            for (long i = 0; i < n; ++i) ret[i] = Read;
            return ret;
        }

        public int[] ReadIntArray(long n)
        {
            var ret = new int[n];
            for (long i = 0; i < n; ++i) ret[i] = ReadInt;
            return ret;
        }

        public long[] ReadLongArray(long n)
        {
            var ret = new long[n];
            for (long i = 0; i < n; ++i) ret[i] = ReadLong;
            return ret;
        }
    }
}