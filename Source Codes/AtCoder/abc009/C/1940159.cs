using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);
            new Program().Solve(new MyInputStream(Console.In, ' '));
            Console.Out.Flush();
        }

        public void Solve(MyInputStream cin)
        {
            var N = cin.ReadInt();
            var K = cin.ReadInt();
            var S = cin.Read();
            var s = new Queue<char>(S.ToCharArray().OrderBy(x => x));
            var a = new HashMap<char, int>();
            var b = new HashMap<char, int>();
            for (int i = 0; i < N; ++i)
            {
                a[S[i]]++;
                b[S[i]]++;
            }

            string T = "";
            for (int i = 0; i < N; ++i)
            {
                a[S[i]]--;
                for (int j = 0; j < 26; ++j)
                {
                    if (b[(char)(j + 'a')] > 0)
                    {
                        b[(char)(j + 'a')]--;
                        if (S[i] != (char)(j + 'a'))
                            K--;

                        int diff = 0;
                        for (int k = 0; k < 26; ++k)
                            diff += Abs(a[(char)(k + 'a')] - b[(char)(k + 'a')]);

                        if (diff / 2 <= K)
                        {
                            T += (char)(j + 'a');
                            break;
                        }
                        else
                        {
                            if (S[i] != (char)(j + 'a'))
                                K++;
                            b[(char)(j + 'a')]++;
                        }
                    }
                }                
            }

            WriteLine(T);
        }
    }

    public class HashMap<K, V> : Dictionary<K, V>
    {
        public HashMap() : base() { }
        public HashMap(int cap) : base(cap) { }
        public HashMap(IDictionary<K, V> dictionary) : base(dictionary) { }
        new public V this[K i]
        {
            get
            {
                V v;
                return TryGetValue(i, out v) ? v : base[i] = default(V);
            }
            set { base[i] = value; }
        }
    }
    public static class MyExtentions
    {
        public static string Swap(this string sourse, int a, int b)
        {
            if (a < 0 || a >= sourse.Length) throw new ArgumentException();
            if (b < 0 || b >= sourse.Length) throw new ArgumentException();
            char[] chrAry = sourse.ToCharArray();
            var c = chrAry[a];
            chrAry[a] = chrAry[b];
            chrAry[b] = c;
            return new string(chrAry);
        }
    }
    public class MyInputStream
    {
        private readonly System.IO.TextReader _stream;
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(System.IO.TextReader s, char separator = ' ')
        {
            this.separator = separator;
            this._stream = s;
            inputStream = new Queue<string>();
        }
        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = _stream.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; ++i)
                inputStream.Enqueue(tmp[i]);
            return inputStream.Dequeue();
        }
        public string ReadLine() { return _stream.ReadLine(); }
        public int ReadInt() { return int.Parse(Read()); }
        public long ReadLong() { return long.Parse(Read()); }
        public double ReadDouble() { return double.Parse(Read()); }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read(); return ret;}
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt(); return ret;}
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong(); return ret;}
    }
}