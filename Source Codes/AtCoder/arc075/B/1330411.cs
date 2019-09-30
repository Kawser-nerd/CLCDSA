using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace NotFounds
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
        }

        public void Solve()
        {
            var cin = new MyInputStream();
            var N = cin.ri();
            var A = cin.ri();
            var B = cin.ri();
            var h = new int[N];
            for (int i = 0; i < N; ++i)
                h[i] = cin.ri();

            var diff = A - B;
            Func<long, bool> check = (K) =>
            {
                var k = K;
                for (int i = 0; i < N; ++i)
                {
                    var t = h[i] - B * K;
                    if (t > 0)
                        k -= (long)Math.Ceiling((double)t / diff);
                }
                return k >= 0;
            };

            var r = (long)0;
            var l = (long)1e9;
            for (int i = 0; i < 150; ++i)
            {
                var mid = (l + r) >> 1;
                if (check(mid))
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
                //WriteLine($"{r} {l}");
            }
            WriteLine(l);
        }
    }

    public class MyInputStream
    {
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(char separator = ' ')
        {
            this.separator = separator;
            inputStream = new Queue<string>();
        }

        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = Console.ReadLine().Trim().Split(separator);
            for (int i = 0; i < tmp.Length; i++)
            {
                inputStream.Enqueue(tmp[i]);
            }
            return inputStream.Dequeue();
        }
        public string ReadLine() => Console.ReadLine();
        public int ReadInt() => int.Parse(Read());
        public long ReadLong() => long.Parse(Read());
        public double ReadDouble() => double.Parse(Read());
        public string r() => Read();
        public int ri() => ReadInt();
        public long rl() => ReadLong();
        public double rd() => ReadDouble();
    }
}